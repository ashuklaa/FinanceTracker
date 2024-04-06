#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "login.h"
#include <QMainWindow>
#include <qtmetamacros.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ftk::backend::login::LoginManager* loginManager;
private slots:
    void onLoginClicked();
    void onSignupClicked();
};
#endif // MAINWINDOW_H
