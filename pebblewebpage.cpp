#include "pebblewebpage.h"
#include <QtGui>
#include <QNetworkAccessManager>
#include <QNetworkRequest>

PebbleWebPage::PebbleWebPage(QObject *parent) : QWebPage(parent)
{
}

QString PebbleWebPage::userAgentForUrl(const QUrl &url ) const
{
    return QString("Mozilla/5.0 (Linux; Android 4.4; Nexus 5 Build/_BuildID_) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/30.0.0.0 Mobile Safari/537.36");
}

bool PebbleWebPage::acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type)
{
    if (request.url().scheme() == "pebble") {
        if (request.url().host() == "login") {
            QUrlQuery *accessTokenFragment = new QUrlQuery(request.url().fragment());
            emit loginSuccess(accessTokenFragment->queryItemValue("access_token"));
        }
    }
    if (request.url().scheme() == "pebble-method-call-js-frame") {
        QString urlStr = "";

        //Basic parse error string
        QRegExp reg(".*; source was \"(.*)\";.*");
        reg.setMinimal(true);
        if (reg.indexIn(request.url().errorString()) > -1) {
            urlStr = reg.cap(1);
            reg.setPattern("method=(.*)&args=(.*)$");
            reg.setMinimal(true);
            if (reg.indexIn(urlStr) > -1) {
                QString methodStr = reg.cap(1);
                QString argsStr = QUrl::fromPercentEncoding(reg.cap(2).toUtf8());
                emit call(methodStr, argsStr);
                if (methodStr == "loadAppToDeviceAndLocker") {
                    QJsonDocument jsonResponse = QJsonDocument::fromJson(argsStr.toUtf8());
                    QJsonObject jsonObject = jsonResponse.object();
                    QJsonObject data = jsonObject.value("data").toObject();
                    emit downloadPebbleApp(data.value("title").toString(), data.value("pbw_file").toString());
                }
            }
        }
    }
    return true;
}
