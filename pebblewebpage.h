#ifndef PEBBLEWEBPAGE_H
#define PEBBLEWEBPAGE_H

#include <QWebPage>

class PebbleWebPage : public QWebPage
{
    Q_OBJECT
public:
    PebbleWebPage(QObject *parent = 0);

    QString userAgentForUrl(const QUrl &url ) const;
    bool acceptNavigationRequest(QWebFrame *frame, const QNetworkRequest &request, NavigationType type);

signals:
    void loginSuccess(const QString &);
    void downloadPebbleApp(const QString &, const QString &);
    void call(const QString &, const QString &);
};

#endif // PEBBLEWEBPAGE_H
