#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pebblewebpage.h"
#include <QWebFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->webView->page(), SIGNAL(loginSuccess(const QString &)), this, SLOT(onLoginSuccess(const QString &)));
    connect(ui->webView->page(), SIGNAL(downloadPebbleApp(const QString &, const QString &)), this, SLOT(onDownloadPebbleApp(const QString &, const QString &)));

    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    //Get all the correct URLs from here:
    //https://boot.getpebble.com/api/config/android/v1/3

    QString authUrl = "https://auth.getpebble.com/oauth/authorize?client_id=f88739e8e7a696c411236c41afc81cbef16dc54c3ff633d92dd4ceb0e5a25e5f&response_type=token&mid=$$phone_id$$&pid=$$pebble_id$$&platform=android&mobile=sign_in&redirect_uri=pebble%3A%2F%2Flogin";

    authUrl = authUrl.replace("$$phone_id$$", "XXX");
    authUrl = authUrl.replace("$$pebble_id$$", "YYY");


    ui->webView->setUrl(authUrl);
}

void MainWindow::openStore()
{
    QString url = "https://apps-prod.getpebble.com/en_US/?access_token=$$access_token$$&platform=android&uid=$$user_id$$&mid=$$phone_id$$&pid=$$pebble_id$$#/watchfaces";

    url = url.replace("$$user_id$$", "ZZZ");
    url = url.replace("$$phone_id$$", "XXX");
    url = url.replace("$$pebble_id$$", "YYY");
    url = url.replace("$$access_token$$", this->accessToken);

    ui->webView->setUrl(url);
}

void MainWindow::onLoginSuccess(const QString &accessToken )
{
    this->accessToken = accessToken;
    openStore();
}

void MainWindow::onDownloadPebbleApp(const QString &title, const QString &url)
{
    qDebug()<<"DL REQUEST"<<title<<url;
}


MainWindow::~MainWindow()
{
    delete ui;
}
