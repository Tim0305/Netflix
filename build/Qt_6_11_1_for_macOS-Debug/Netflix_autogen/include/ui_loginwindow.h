/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *userEdit;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *signupButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(LoginWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        userEdit = new QLineEdit(LoginWindow);
        userEdit->setObjectName("userEdit");
        userEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(userEdit);

        passwordEdit = new QLineEdit(LoginWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(passwordEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");

        horizontalLayout->addWidget(loginButton);

        signupButton = new QPushButton(LoginWindow);
        signupButton->setObjectName("signupButton");

        horizontalLayout->addWidget(signupButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(LoginWindow);

        loginButton->setDefault(true);


        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Iniciar sesi\303\263n", nullptr));
        userEdit->setInputMask(QString());
        userEdit->setText(QString());
        userEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Usuario", nullptr));
        passwordEdit->setInputMask(QString());
        passwordEdit->setText(QString());
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Contrase\303\261a", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Iniciar Sesi\303\263n", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginWindow", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
