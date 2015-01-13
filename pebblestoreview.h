#ifndef PEBBLESTOREVIEW_H
#define PEBBLESTOREVIEW_H

#include <QWebView>
#include "pebblewebpage.h"

class PebbleStoreView : public QWebView
{
    Q_OBJECT
public:
    PebbleStoreView(QWidget* parent = 0);

private slots:
    void sslErrorHandler(QNetworkReply* qnr, const QList<QSslError> & errlist);
};

#endif // PEBBLESTOREVIEW_H
