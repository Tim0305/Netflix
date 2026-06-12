/********************************************************************************
** Form generated from reading UI file 'usuariowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIOWIDGET_H
#define UI_USUARIOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UsuarioWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *rolLabel;
    QLabel *usuarioLabel;
    QPushButton *modificarButton;
    QPushButton *eliminarButton;

    void setupUi(QWidget *UsuarioWidget)
    {
        if (UsuarioWidget->objectName().isEmpty())
            UsuarioWidget->setObjectName("UsuarioWidget");
        UsuarioWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(UsuarioWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        rolLabel = new QLabel(UsuarioWidget);
        rolLabel->setObjectName("rolLabel");
        rolLabel->setMinimumSize(QSize(16, 16));
        rolLabel->setMaximumSize(QSize(16, 16));
        rolLabel->setStyleSheet(QString::fromUtf8("background-color: green;border-radius: 8px;"));

        horizontalLayout->addWidget(rolLabel);

        usuarioLabel = new QLabel(UsuarioWidget);
        usuarioLabel->setObjectName("usuarioLabel");
        usuarioLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(usuarioLabel);

        modificarButton = new QPushButton(UsuarioWidget);
        modificarButton->setObjectName("modificarButton");
        modificarButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        horizontalLayout->addWidget(modificarButton);

        eliminarButton = new QPushButton(UsuarioWidget);
        eliminarButton->setObjectName("eliminarButton");
        eliminarButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        eliminarButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(eliminarButton);


        retranslateUi(UsuarioWidget);

        QMetaObject::connectSlotsByName(UsuarioWidget);
    } // setupUi

    void retranslateUi(QWidget *UsuarioWidget)
    {
        UsuarioWidget->setWindowTitle(QCoreApplication::translate("UsuarioWidget", "Form", nullptr));
        rolLabel->setText(QString());
        usuarioLabel->setText(QCoreApplication::translate("UsuarioWidget", "TextLabel", nullptr));
        modificarButton->setText(QCoreApplication::translate("UsuarioWidget", "Modificar", nullptr));
        eliminarButton->setText(QCoreApplication::translate("UsuarioWidget", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UsuarioWidget: public Ui_UsuarioWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIOWIDGET_H
