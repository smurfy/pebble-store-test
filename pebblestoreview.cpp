#include "pebblestoreview.h"
#include "pebblewebpage.h"
#include <QtNetwork>
#include <QNetworkAccessManager>

PebbleStoreView::PebbleStoreView(QWidget *parent)
    : QWebView(parent)
{
    setPage(new PebbleWebPage());
    connect(page()->networkAccessManager(), SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> & )), this, SLOT(sslErrorHandler(QNetworkReply*, const QList<QSslError> & )));
}

void PebbleStoreView::sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist)
{
  qnr->ignoreSslErrors();
}


