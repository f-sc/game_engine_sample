#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QDebug>
#include <QSignalMapper>
#include <QFormLayout>
#include <QLineEdit>
#include <QDir>
#include <QListWidget>
#include <QListWidgetItem>

#include <map_elements.h>
#include "project_manager.h"

namespace Ui {
class main_window;
}

class main_window : public QWidget
{
    Q_OBJECT

public:

    explicit main_window(QWidget *parent = 0);
    ~main_window();




private slots:
    void on_b_loadlvl_clicked();

    void on_b_add_clicked();

    void on_b_remove_clicked();

    void on_w_items_clicked(const QModelIndex &index);

    void on_b_saveLvl_clicked();

    void on_toolButton_3_clicked();

    void on_main_window_destroyed();



    void on_w_items_itemActivated(QTreeWidgetItem *item, int column);

private:
    Ui::main_window *ui;
    map_elements* main_elements;
    QSignalMapper* mapper;
    project_manager* manager;

};

#endif // MAIN_WINDOW_H
