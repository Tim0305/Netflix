/********************************************************************************
** Form generated from reading UI file 'generowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENEROWIDGET_H
#define UI_GENEROWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneroWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *label;
    QLabel *generoLabel;
    QWidget *editline;
    QLineEdit *generoEdit;
    QPushButton *eliminarButton;

    void setupUi(QWidget *GeneroWidget)
    {
        if (GeneroWidget->objectName().isEmpty())
            GeneroWidget->setObjectName("GeneroWidget");
        GeneroWidget->resize(400, 300);
        horizontalLayout = new QHBoxLayout(GeneroWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        stackedWidget = new QStackedWidget(GeneroWidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        label = new QWidget();
        label->setObjectName("label");
        generoLabel = new QLabel(label);
        generoLabel->setObjectName("generoLabel");
        generoLabel->setGeometry(QRect(100, 10, 58, 276));
        stackedWidget->addWidget(label);
        editline = new QWidget();
        editline->setObjectName("editline");
        generoEdit = new QLineEdit(editline);
        generoEdit->setObjectName("generoEdit");
        generoEdit->setGeometry(QRect(0, 100, 125, 21));
        stackedWidget->addWidget(editline);

        horizontalLayout->addWidget(stackedWidget);

        eliminarButton = new QPushButton(GeneroWidget);
        eliminarButton->setObjectName("eliminarButton");

        horizontalLayout->addWidget(eliminarButton);


        retranslateUi(GeneroWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GeneroWidget);
    } // setupUi

    void retranslateUi(QWidget *GeneroWidget)
    {
        GeneroWidget->setWindowTitle(QCoreApplication::translate("GeneroWidget", "Form", nullptr));
        generoLabel->setText(QCoreApplication::translate("GeneroWidget", "TextLabel", nullptr));
        eliminarButton->setText(QCoreApplication::translate("GeneroWidget", "Eliminar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneroWidget: public Ui_GeneroWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENEROWIDGET_H
