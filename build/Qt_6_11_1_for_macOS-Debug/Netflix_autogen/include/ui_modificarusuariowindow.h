/********************************************************************************
** Form generated from reading UI file 'modificarusuariowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARUSUARIOWINDOW_H
#define UI_MODIFICARUSUARIOWINDOW_H

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

class Ui_ModificarUsuarioWindow
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

    void setupUi(QWidget *ModificarUsuarioWindow)
    {
        if (ModificarUsuarioWindow->objectName().isEmpty())
            ModificarUsuarioWindow->setObjectName("ModificarUsuarioWindow");
        ModificarUsuarioWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(ModificarUsuarioWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(ModificarUsuarioWindow);
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

        verticalSpacer = new QSpacerItem(20, 46, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(40, -1, 40, -1);
        label_2 = new QLabel(ModificarUsuarioWindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_2);

        usuarioEdit = new QLineEdit(ModificarUsuarioWindow);
        usuarioEdit->setObjectName("usuarioEdit");
        usuarioEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, usuarioEdit);

        label_3 = new QLabel(ModificarUsuarioWindow);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_3);

        passwordEdit = new QLineEdit(ModificarUsuarioWindow);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setAlignment(Qt::AlignmentFlag::AlignCenter);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, passwordEdit);

        label_4 = new QLabel(ModificarUsuarioWindow);
        label_4->setObjectName("label_4");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_4);

        rolBox = new QComboBox(ModificarUsuarioWindow);
        rolBox->setObjectName("rolBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, rolBox);


        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 46, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        registrarButton = new QPushButton(ModificarUsuarioWindow);
        registrarButton->setObjectName("registrarButton");

        verticalLayout->addWidget(registrarButton);


        retranslateUi(ModificarUsuarioWindow);

        QMetaObject::connectSlotsByName(ModificarUsuarioWindow);
    } // setupUi

    void retranslateUi(QWidget *ModificarUsuarioWindow)
    {
        ModificarUsuarioWindow->setWindowTitle(QCoreApplication::translate("ModificarUsuarioWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("ModificarUsuarioWindow", "Modificar usuario", nullptr));
        label_2->setText(QCoreApplication::translate("ModificarUsuarioWindow", "Usuario:", nullptr));
        label_3->setText(QCoreApplication::translate("ModificarUsuarioWindow", "Contrase\303\261a:", nullptr));
        label_4->setText(QCoreApplication::translate("ModificarUsuarioWindow", "Rol", nullptr));
        registrarButton->setText(QCoreApplication::translate("ModificarUsuarioWindow", "Guardar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModificarUsuarioWindow: public Ui_ModificarUsuarioWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARUSUARIOWINDOW_H
