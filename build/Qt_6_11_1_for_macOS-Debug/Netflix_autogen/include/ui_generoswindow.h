/********************************************************************************
** Form generated from reading UI file 'generoswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENEROSWINDOW_H
#define UI_GENEROSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GenerosWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QListView *listView;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *GenerosWindow)
    {
        if (GenerosWindow->objectName().isEmpty())
            GenerosWindow->setObjectName("GenerosWindow");
        GenerosWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(GenerosWindow);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(GenerosWindow);
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

        verticalSpacer = new QSpacerItem(20, 7, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(GenerosWindow);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        listView = new QListView(GenerosWindow);
        listView->setObjectName("listView");

        verticalLayout->addWidget(listView);

        verticalSpacer_2 = new QSpacerItem(20, 7, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(GenerosWindow);

        QMetaObject::connectSlotsByName(GenerosWindow);
    } // setupUi

    void retranslateUi(QWidget *GenerosWindow)
    {
        GenerosWindow->setWindowTitle(QCoreApplication::translate("GenerosWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("GenerosWindow", "G\303\251neros", nullptr));
        pushButton->setText(QCoreApplication::translate("GenerosWindow", "Crear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GenerosWindow: public Ui_GenerosWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENEROSWINDOW_H
