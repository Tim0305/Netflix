/********************************************************************************
** Form generated from reading UI file 'registrarusuariowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRARUSUARIOWINDOW_H
#define UI_REGISTRARUSUARIOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegistrarUsuarioWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *usuarioEdit;
    QLabel *label_3;
    QLineEdit *passwordEdit;
    QLabel *label_4;
    QComboBox *rolBox;
    QSpacerItem *verticalSpacer_2;
    QPushButton *registrarButton;

    void setupUi(QWidget *RegistrarUsuarioWindow)
    {
        if (RegistrarUsuarioWindow->objectName().isEmpty())
            RegistrarUsuarioWindow->setObjectName("RegistrarUsuarioWindow");
        RegistrarUsuarioWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(RegistrarUsuarioWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(RegistrarUsuarioWindow);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(40, -1, 40, -1);
        label_2 = new QLabel(RegistrarUsuarioWindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        usuarioEdit = new QLineEdit(RegistrarUsuarioWindow);
        usuarioEdit->setObjectName("usuarioEdit");
        usuarioEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usuarioEdit);

        label_3 = new QLabel(RegistrarUsuarioWindow);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_3);

        passwordEdit = new QLineEdit(RegistrarUsuarioWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);

        label_4 = new QLabel(RegistrarUsuarioWindow);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_4);

        rolBox = new QComboBox(RegistrarUsuarioWindow);
        rolBox->setObjectName("rolBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, rolBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        registrarButton = new QPushButton(RegistrarUsuarioWindow);
        registrarButton->setObjectName("registrarButton");

        verticalLayout->addWidget(registrarButton);


        retranslateUi(RegistrarUsuarioWindow);

        QMetaObject::connectSlotsByName(RegistrarUsuarioWindow);
    } // setupUi

    void retranslateUi(QWidget *RegistrarUsuarioWindow)
    {
        RegistrarUsuarioWindow->setWindowTitle(QCoreApplication::translate("RegistrarUsuarioWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("RegistrarUsuarioWindow", "Usuario", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrarUsuarioWindow", "Usuario:", nullptr));
        label_3->setText(QCoreApplication::translate("RegistrarUsuarioWindow", "Contrase\303\261a:", nullptr));
        label_4->setText(QCoreApplication::translate("RegistrarUsuarioWindow", "Rol", nullptr));
        registrarButton->setText(QCoreApplication::translate("RegistrarUsuarioWindow", "Registrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistrarUsuarioWindow: public Ui_RegistrarUsuarioWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRARUSUARIOWINDOW_H
