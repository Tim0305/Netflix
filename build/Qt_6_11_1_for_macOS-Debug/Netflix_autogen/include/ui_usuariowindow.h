/********************************************************************************
** Form generated from reading UI file 'usuariowindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIOWINDOW_H
#define UI_USUARIOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsuarioWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;
    QPushButton *buscarButton;
    QListView *listView;

    void setupUi(QWidget *UsuarioWindow)
    {
        if (UsuarioWindow->objectName().isEmpty())
            UsuarioWindow->setObjectName("UsuarioWindow");
        UsuarioWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(UsuarioWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(UsuarioWindow);
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

        lineEdit = new QLineEdit(UsuarioWindow);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);

        buscarButton = new QPushButton(UsuarioWindow);
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

        listView = new QListView(UsuarioWindow);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);


        retranslateUi(UsuarioWindow);

        buscarButton->setDefault(false);


        QMetaObject::connectSlotsByName(UsuarioWindow);
    } // setupUi

    void retranslateUi(QWidget *UsuarioWindow)
    {
        UsuarioWindow->setWindowTitle(QCoreApplication::translate("UsuarioWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("UsuarioWindow", "Usuarios", nullptr));
        buscarButton->setText(QCoreApplication::translate("UsuarioWindow", "Buscar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsuarioWindow: public Ui_UsuarioWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIOWINDOW_H
