#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    void reset();

private slots:
    void on_signupButton_clicked();
    void on_loginButton_clicked();

signals:
    void gotoSignup();
    void gotoAdmin();

private:
    Ui::LoginWindow *ui;
    std::string ADMIN_USER;
    std::string ADMIN_PASSWORD;
};

#endif // LOGINWINDOW_H
