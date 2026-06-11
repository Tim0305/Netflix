#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();
    void reset();

signals:
    void return2LoginWindow();

private slots:
    void on_returnButton_clicked();
    void on_signinButton_clicked();

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
