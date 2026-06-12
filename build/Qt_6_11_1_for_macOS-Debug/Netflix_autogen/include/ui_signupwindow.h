/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

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

class Ui_SignUpWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLineEdit *userEdit;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *returnButton;
    QPushButton *signinButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName("SignUpWindow");
        SignUpWindow->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(SignUpWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(SignUpWindow);
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

        userEdit = new QLineEdit(SignUpWindow);
        userEdit->setObjectName("userEdit");
        userEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(userEdit);

        passwordEdit = new QLineEdit(SignUpWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(passwordEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        returnButton = new QPushButton(SignUpWindow);
        returnButton->setObjectName("returnButton");

        horizontalLayout->addWidget(returnButton);

        signinButton = new QPushButton(SignUpWindow);
        signinButton->setObjectName("signinButton");

        horizontalLayout->addWidget(signinButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SignUpWindow);

        signinButton->setDefault(true);


        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QWidget *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("SignUpWindow", "Registrarse", nullptr));
        userEdit->setInputMask(QString());
        userEdit->setText(QString());
        userEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "Usuario", nullptr));
        passwordEdit->setInputMask(QString());
        passwordEdit->setText(QString());
        passwordEdit->setPlaceholderText(QCoreApplication::translate("SignUpWindow", "Contrase\303\261a", nullptr));
        returnButton->setText(QCoreApplication::translate("SignUpWindow", "Regresar", nullptr));
        signinButton->setText(QCoreApplication::translate("SignUpWindow", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
