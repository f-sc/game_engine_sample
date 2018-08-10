#include "map_elements.h"

enum colors{red, green, blue};

map_elements::map_elements(QWidget* me_widget, QWidget* main_widget):me_widget(me_widget), main_widget(main_widget)
{
    int counter = 0;
    for(QObject* children_me: me_widget->children())
    {
        counter++;
        if(children_me->objectName().at(0) == 'b')
        {
         map_element* new_me = new map_element;
         new_me->position = (QPoint)((dynamic_cast<QToolButton*>(children_me))->pos());
         new_me->btn_me = dynamic_cast<QToolButton*>(children_me);
         new_me->btn_me->setStyleSheet(QString("background-color: green"));
         new_me->name = "Grass";
         new_me->color = "green";
         new_me->isVisible = 1;
         new_me->isAllreadyFull = false;
         elements.push_back(new_me);
        }
    }

    for(auto t_elem: main_widget->children())
    {
        if(t_elem->objectName() == "w_items")
        {
            treeWidget = dynamic_cast<QTreeWidget*>(t_elem);
        }
    }
    loadConfigMapElements("/Users/2ima/game_engine/map_elems.cfg");
}

QString map_elements::get_color(QString name)
{
    for(auto color: tree_elements)
    {
        if(color->name == name)
        {
            return color->color;
        }
    }
    return "green";

}

void map_elements::add_new_element(QString name, QPoint pos, bool isVisible)
{
  for(auto temp: elements)
  {
      if(temp->position == pos)
      {
          if(temp->isAllreadyFull!=true && temp->name=="Grass")
          {
          temp->name = name;
          qDebug() << name;
          temp->color = get_color(name);
          temp->isVisible = isVisible;
          temp->btn_me->setStyleSheet(QString("background-color: "+get_color(name)));
          temp->isAllreadyFull = true;
          }
          else
          {
              QMessageBox error;
              error.setText("Item is allready added! You can change it only.");
              error.exec();
          }
      }
  }
}

void map_elements::changeElement(QPoint position, bool Remove, QString name, QPoint pos, int color, bool isVisible)
{

}

void map_elements::ClickedD(QString pos)
{
    QPoint temp_point;
    QStringList tsp = pos.split(',');
    temp_point.setX(QString(tsp.at(0)).toInt());
    temp_point.setY(QString(tsp.at(1)).toInt());

     add_new_element(treeWidget->currentItem()->text(0), temp_point, 1);
qDebug() << pos;
}

void map_elements::add_to_preview(QString data)
{
    tree_element* new_element = new tree_element;
    for(auto temp: add_item->children())
    {
        if(temp->objectName() == "i_Name")
        {
        new_element->name = (dynamic_cast<QLineEdit*>(temp))->text();
        }
        else if(temp->objectName() == "i_Color")
        {
            new_element->color = (dynamic_cast<QLineEdit*>(temp))->text();
        }
    }
    treeWidget->currentItem()->addChild(new QTreeWidgetItem(QStringList(new_element->name)));
    new_element->category = treeWidget->currentItem()->text(0);
    tree_elements.push_back(new_element);
    saveConfigMapElements("/Users/2ima/game_engine/map_elems.cfg");
}

void map_elements::saveConfigMapElements(QString config)
{
    QFile fp(config);
    fp.open(QIODevice::WriteOnly);
    if(fp.isOpen())
    {
        for(tree_element* elements: tree_elements)
        {
            QByteArray out = QByteArray::fromStdString(QString(elements->category+","+elements->name+","+elements->color+" ").toStdString());
            fp.write(out);
        }
        fp.close();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Error, confing file not found or corrupted.");
        msg.exec();
    }
}

void map_elements::loadConfigMapElements(QString config)
{
    QFile fp(config);
    fp.open(QIODevice::ReadOnly);
    if(fp.isOpen())
    {
        QList<QByteArray> indata = fp.readAll().split(' ');
        for(QByteArray elems: indata)
        {
            QList<QByteArray> temp = elems.split(',');
            if(temp.at(0)!="")
            {
            tree_element* element = new tree_element;
            element->category = temp.at(0);
            element->name = temp.at(1);
            element->color = temp.at(2);
           // qDebug() << treeWidget->itemAt(QPoint(0, 0))->text(0);
            //qDebug() << treeWidget->itemBelow(treeWidget->itemAt(QPoint(0, 0)))->text();
           for(QTreeWidgetItem* start = treeWidget->itemAt(QPoint(0, 0)); start != NULL; start = treeWidget->itemBelow(start))
           {

               if(QString::fromStdString(start->text(0).toStdString()) == element->category)
               {
                  start->addChild(new QTreeWidgetItem(QStringList(element->name)));//!!!!
               }
           }

            tree_elements.push_back(element);
            }
        }
        fp.close();
    }
}

void map_elements::update_tree_view()
{
    for(auto temp: tree_elements)
    {
        if(temp->name == treeWidget->currentItem()->text(0))
        {
            tree_elements.removeOne(temp);
        }
    }
    treeWidget->currentItem()->parent()->removeChild(treeWidget->currentItem());
    /*for(auto element: tree_elements)
    {
        treeWidget->currentItem()->parent()->addChild(new QTreeWidgetItem(QStringList(element->name)));
    }*/
    saveConfigMapElements("/Users/2ima/game_engine/map_elems.cfg");
}


void map_elements::SaveMap(QString map)
{
    QFile fp(map);
    qDebug() << map;
    fp.open(QIODevice::WriteOnly);
    if(fp.isOpen())
    {
        for(map_element* map_el: elements)
        {
           fp.write(QByteArray::fromStdString(QString(map_el->color+",").toStdString()));
        }
        fp.write(QByteArray("E"));
        fp.close();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Error, map file not found or corrupted.");
        msg.exec();
    }
}

void map_elements::LoadMap(QString map)
{
    QFile fp(map);
    fp.open(QIODevice::ReadOnly);
    if(fp.isOpen())
    {
        QList<QToolBox*> m_children;
        for(auto temp_el: me_widget->children())
        {
            if(temp_el->objectName().at(0) == 'b')
            {
               m_children.push_back((QToolBox*)(temp_el));
            }
        }
        QList<QByteArray> map_contents = fp.readAll().split(',');
        for(int i=0; i<map_contents.length(); i++)
        {
            if(map_contents.at(i) != "E" && i<=m_children.length())
            {
                m_children.at(i)->setStyleSheet(QString("background-color: "+map_contents.at(i)));
                elements.at(i)->color = map_contents.at(i);
            }
        }
        fp.close();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Error, map file not found or corrupted.");
        msg.exec();
    }
}

void map_elements::clearMapView()
{
    for(auto map_el: elements)
    {
        map_el->btn_me->setStyleSheet(QString("background-color: green"));
    }
}
