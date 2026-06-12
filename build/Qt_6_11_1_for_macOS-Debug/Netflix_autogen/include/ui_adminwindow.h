/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *sidebar;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(AdminWindow);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        sidebar = new QListWidget(AdminWindow);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(sidebar);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(sidebar);
        __qlistwidgetitem1->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(sidebar);
        __qlistwidgetitem2->setTextAlignment(Qt::AlignCenter);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(sidebar);
        __qlistwidgetitem3->setTextAlignment(Qt::AlignCenter);
        sidebar->setObjectName("sidebar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sidebar->sizePolicy().hasHeightForWidth());
        sidebar->setSizePolicy(sizePolicy);
        sidebar->setMaximumSize(QSize(100, 16777215));
        sidebar->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(sidebar);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        stackedWidget = new QStackedWidget(AdminWindow);
        stackedWidget->setObjectName("stackedWidget");

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QWidget *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "Form", nullptr));

        const bool __sortingEnabled = sidebar->isSortingEnabled();
        sidebar->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = sidebar->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("AdminWindow", "Inicio", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = sidebar->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("AdminWindow", "Usuarios", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = sidebar->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("AdminWindow", "G\303\251neros", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = sidebar->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("AdminWindow", "Cerrar sesi\303\263n", nullptr));
        sidebar->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
