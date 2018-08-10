#ifndef MAP_ELEMENTS_H
#define MAP_ELEMENTS_H

#include <QList>
#include <QVector>
#include <QString>
#include <QPoint>
#include <QWidget>
#include <QToolButton>
#include <QObject>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QMessageBox>
#include <QLineEdit>
#include <QFile>
#include <QByteArray>
#include <QToolBox>


enum elements_clr{grass, tree, water,wall};

struct map_element
{
    QToolButton* btn_me;
    QString name;
    QPoint position;
    QString color;
    bool isAllreadyFull;
    bool isVisible;
};

struct tree_element
{
    QString category;
    QString name;
    QString color;
};

class map_elements: public QObject
{
    Q_OBJECT
    QList<map_element*> elements;
    QList<tree_element*> tree_elements;
    QWidget* me_widget;
    QWidget* main_widget;

    QTreeWidget* treeWidget;
public:
     QWidget* add_item;
    map_elements(QWidget* me_widget, QWidget* main_widget);
    void add_new_element(QString name, QPoint pos, bool isVisible);
    void changeElement(QPoint position, bool Remove, QString name, QPoint pos, int color, bool isVisible);
    QList<map_element*> getAllElements(){return elements;}
    QString get_color(QString name);

    void saveConfigMapElements(QString config);
    void loadConfigMapElements(QString config);

    void SaveMap(QString map);
    void LoadMap(QString map);

    void update_tree_view();

    void clearMapView();
signals:

public slots:
    void ClickedD(QString pos);
    void add_to_preview(QString data);

};

#endif // MAP_ELEMENTS_H
