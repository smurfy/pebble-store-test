#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSslError>
#include <QNetworkReply>
#include <QWebFrame>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void openStore();

public slots:
    void onLoginSuccess(const QString &accessToken);
    void onDownloadPebbleApp(const QString &, const QString &);

private:
    Ui::MainWindow *ui;
    QString accessToken;
};

#endif // MAINWINDOW_H
