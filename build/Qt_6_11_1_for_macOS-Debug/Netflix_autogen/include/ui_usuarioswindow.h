/********************************************************************************
** Form generated from reading UI file 'usuarioswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIOSWINDOW_H
#define UI_USUARIOSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsuariosWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *buscarEdit;
    QPushButton *buscarButton;
    QListWidget *listWidget;

    void setupUi(QWidget *UsuariosWindow)
    {
        if (UsuariosWindow->objectName().isEmpty())
            UsuariosWindow->setObjectName("UsuariosWindow");
        UsuariosWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(UsuariosWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(UsuariosWindow);
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        buscarEdit = new QLineEdit(UsuariosWindow);
        buscarEdit->setObjectName("buscarEdit");

        horizontalLayout_2->addWidget(buscarEdit);

        buscarButton = new QPushButton(UsuariosWindow);
        buscarButton->setObjectName("buscarButton");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buscarButton->sizePolicy().hasHeightForWidth());
        buscarButton->setSizePolicy(sizePolicy1);
        buscarButton->setAutoDefault(false);
        buscarButton->setFlat(false);

        horizontalLayout_2->addWidget(buscarButton);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(UsuariosWindow);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);


        retranslateUi(UsuariosWindow);

        buscarButton->setDefault(false);


        QMetaObject::connectSlotsByName(UsuariosWindow);
    } // setupUi

    void retranslateUi(QWidget *UsuariosWindow)
    {
        UsuariosWindow->setWindowTitle(QCoreApplication::translate("UsuariosWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("UsuariosWindow", "Usuarios", nullptr));
        buscarButton->setText(QCoreApplication::translate("UsuariosWindow", "Buscar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsuariosWindow: public Ui_UsuariosWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIOSWINDOW_H
