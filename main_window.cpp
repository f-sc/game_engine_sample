#include "main_window.h"
#include "ui_main_window.h"

main_window::main_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::main_window)
{
    ui->setupUi(this);
    int y =0;
    int b_c = 0;
    for(int i=0; i<7; i++)
    {
        int x =0;
        for(int k=0; k<9; k++)
        {
            QToolButton* button = new QToolButton(ui->w_all_items);
            button->setObjectName(QString("b_")+QString::number(b_c));
            button->setGeometry(x, y, 61, 61);
            b_c++;
            x+=60;
           // ui->w_all_items->
        }
        y+=60;
    }
    main_elements = new map_elements(ui->w_all_items, ui->widget);
    for(auto temp: main_elements->getAllElements())
    {
        mapper = new QSignalMapper(this);
        QEventLoop::connect(temp->btn_me, SIGNAL(clicked(bool)), mapper, SLOT(map()));
        mapper->setMapping(temp->btn_me, QString(QString::number(temp->btn_me->pos().x())+","+QString::number(temp->btn_me->pos().y())));
        connect(mapper, SIGNAL(mapped(QString)),//потренировать!
                main_elements, SLOT(ClickedD(QString)));
    }
    manager = new project_manager(this, main_elements);
    manager->showProjectManager();
    ui->w_items->setCurrentItem(ui->w_items->itemAt(QPoint(0, 0)));
}

main_window::~main_window()
{
    delete ui;
}

void main_window::on_b_loadlvl_clicked()
{

}

void main_window::on_b_add_clicked()
{
    if(main_elements->add_item!=NULL)
    {
        delete main_elements->add_item;
    }
    main_elements->add_item = new QWidget(this, 0);
    main_elements->add_item->setObjectName("w_new_input");
    main_elements-> add_item->resize(100, 150);
    main_elements->add_item->move(300, 250);
    main_elements->add_item->setStyleSheet(QString("background: rgba(0, 0, 0, 97); border: 1px solid; border-radius: 9px"));
    QFormLayout* layout = new QFormLayout( main_elements->add_item);
    QLabel* caption = new QLabel( main_elements->add_item);
    QLineEdit* Name = new QLineEdit( main_elements->add_item);
    QLineEdit* Color = new QLineEdit( main_elements->add_item);
    Name->setObjectName("i_Name");
    Name->setStyleSheet("background-color: white;");
    Color->setObjectName("i_Color");
    Color->setStyleSheet("color: white;");
    Name->setText("   Name");
    Color->setText("   green");
    caption->setText("Properties:");
    Name->setStyleSheet("color: white;");
    caption->setStyleSheet(QString("color: #27a9e3; border: 0px; background: rgba(0, 0, 0, 0)"));
    QPushButton* ok_btn = new QPushButton( main_elements->add_item);
    ok_btn->setText("        ADD         ");
    ok_btn->setStyleSheet(QString("background-color: #27a9e3; border-radius: 2px"));
    QPushButton* can_btn = new QPushButton( main_elements->add_item);
    can_btn->setText("      Cancel      ");
    can_btn->setStyleSheet(QString("background-color: #27a9e3;"));
    mapper = new QSignalMapper(this);
    QEventLoop::connect(ok_btn, SIGNAL(clicked(bool)), mapper, SLOT(map()));
    mapper->setMapping(ok_btn, QString(QString(Name->text())+","+QString(Color->text())));
    QEventLoop::connect(mapper, SIGNAL(mapped(QString)), main_elements, SLOT(add_to_preview(QString)));
    QEventLoop::connect(can_btn, SIGNAL(clicked(bool)),  main_elements->add_item, SLOT(close()));
    QEventLoop::connect(ui->b_loadlvl, SIGNAL(clicked(bool)),  manager, SLOT(loadBindedMap()));
   // QEventLoop::connect(ui->b_saveLvl, SIGNAL(clicked(bool)),  manager, SLOT(saveBindedMap()));

    layout->addWidget(caption);
    layout->addWidget(Name);
    layout->addWidget(Color);
    layout->addWidget(ok_btn);
    layout->addWidget(can_btn);
    main_elements->add_item->show();

}

void main_window::on_b_remove_clicked()
{
    main_elements->update_tree_view();
}

void main_window::on_w_items_clicked(const QModelIndex &index)
{

}

void main_window::on_b_saveLvl_clicked()
{
    manager->saveBindedMap();
}

void main_window::on_toolButton_3_clicked()
{
    manager->showProjectManager();
}


void main_window::on_main_window_destroyed()
{

}


void main_window::on_w_items_itemActivated(QTreeWidgetItem *item, int column)
{
    //item->set(column, Qt::black);
}
