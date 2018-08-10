/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QWidget *widget;
    QTreeWidget *w_items;
    QPushButton *b_remove;
    QPushButton *b_add;
    QToolButton *b_loadlvl;
    QToolButton *b_saveLvl;
    QToolButton *toolButton_3;
    QLabel *l_Status;
    QWidget *w_all_items;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QStringLiteral("main_window"));
        main_window->resize(778, 558);
        main_window->setMaximumSize(QSize(778, 558));
        main_window->setStyleSheet(QStringLiteral("background: rgba(0, 0, 0, 80);"));
        widget = new QWidget(main_window);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(560, 10, 181, 451));
        w_items = new QTreeWidget(widget);
        new QTreeWidgetItem(w_items);
        new QTreeWidgetItem(w_items);
        new QTreeWidgetItem(w_items);
        w_items->setObjectName(QStringLiteral("w_items"));
        w_items->setGeometry(QRect(0, 0, 181, 421));
        w_items->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        w_items->setFocusPolicy(Qt::NoFocus);
        w_items->setStyleSheet(QLatin1String("\n"
"border:  2px solid; border-bottom: none;  background-color: rgba(0, 0, 0, 80); color: rgb(105, 255, 0); \n"
"QTreeWidget::item\n"
"{\n"
"foreground-color:green;\n"
"}\n"
"\n"
"\n"
""));
        w_items->setFrameShape(QFrame::NoFrame);
        w_items->setFrameShadow(QFrame::Plain);
        w_items->setLineWidth(0);
        w_items->header()->setVisible(false);
        w_items->header()->setCascadingSectionResizes(false);
        b_remove = new QPushButton(widget);
        b_remove->setObjectName(QStringLiteral("b_remove"));
        b_remove->setGeometry(QRect(90, 420, 91, 31));
        b_remove->setStyleSheet(QStringLiteral("color: white; background: rgba(0, 0, 0, 40); border: 2px solid; "));
        b_add = new QPushButton(widget);
        b_add->setObjectName(QStringLiteral("b_add"));
        b_add->setGeometry(QRect(0, 420, 91, 31));
        b_add->setStyleSheet(QStringLiteral("color: white; background: rgba(0, 0, 0, 40); border: 2px solid;"));
        b_loadlvl = new QToolButton(main_window);
        b_loadlvl->setObjectName(QStringLiteral("b_loadlvl"));
        b_loadlvl->setEnabled(false);
        b_loadlvl->setGeometry(QRect(190, 10, 71, 22));
        b_loadlvl->setStyleSheet(QStringLiteral("color: rgb(247, 255, 180); background: rgba(0, 0, 0, 40); border: 1.5px  solid; border-radius: 7px; "));
        b_saveLvl = new QToolButton(main_window);
        b_saveLvl->setObjectName(QStringLiteral("b_saveLvl"));
        b_saveLvl->setEnabled(false);
        b_saveLvl->setGeometry(QRect(120, 10, 61, 22));
        b_saveLvl->setStyleSheet(QStringLiteral("color: white; background: rgba(0, 0, 0, 40); border: 1.5px solid; border-radius: 7px; "));
        toolButton_3 = new QToolButton(main_window);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(10, 10, 101, 22));
        toolButton_3->setStyleSheet(QStringLiteral("color: white; background: rgba(0, 100, 255, 80); border: 1.5px solid; border-radius: 9px;"));
        l_Status = new QLabel(main_window);
        l_Status->setObjectName(QStringLiteral("l_Status"));
        l_Status->setGeometry(QRect(10, 470, 60, 16));
        w_all_items = new QWidget(main_window);
        w_all_items->setObjectName(QStringLiteral("w_all_items"));
        w_all_items->setGeometry(QRect(10, 40, 541, 421));
        w_all_items->setStyleSheet(QStringLiteral(""));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QApplication::translate("main_window", "[By 2ima] Map Editor Sample", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = w_items->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("main_window", "Elements", nullptr));

        const bool __sortingEnabled = w_items->isSortingEnabled();
        w_items->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = w_items->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("main_window", "Ground", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = w_items->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("main_window", "Buildings", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = w_items->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("main_window", "NPCs", nullptr));
        w_items->setSortingEnabled(__sortingEnabled);

        b_remove->setText(QApplication::translate("main_window", "Remove", nullptr));
        b_add->setText(QApplication::translate("main_window", "Add", nullptr));
        b_loadlvl->setText(QApplication::translate("main_window", "Load map", nullptr));
        b_saveLvl->setText(QApplication::translate("main_window", "Save map", nullptr));
        toolButton_3->setText(QApplication::translate("main_window", "Project Manager", nullptr));
        l_Status->setText(QApplication::translate("main_window", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
