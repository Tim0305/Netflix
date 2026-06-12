#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include "signupwindow.h"
#include "adminwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    LoginWindow *loginWindow;
    SignUpWindow *signUpWindow;

    void logout();
    void showSignUpWindow();
    void showLoginWindow();
    void showAdminWindow();
};
#endif // MAINWINDOW_H
