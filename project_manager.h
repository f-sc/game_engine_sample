#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <QEventLoop>
#include <QFormLayout>
#include <QLineEdit>
#include <QDir>
#include <QListWidget>
#include <QListWidgetItem>
#include <QObject>
#include <QList>

#include "map_elements.h"
#include "filesystemod.h"

struct project_info
{
    QString name;
    QString developer;
    QString path;
    QString cfg_elem_name;
    QString map_name;
};

class project_manager:public QObject
{
    Q_OBJECT
    QWidget* parent;
    QList<QString> project_names;
    map_elements* map_view;
    filesystemod* dir_list;
public:
    QWidget* w_pm_main;
    QWidget* w_project_manager;
    project_info* pinfo;
    project_manager(QWidget* parent = 0,  map_elements* map_view = 0);

    void saveProjectConfig();

signals:

public slots:
    void showProjectManager();
    void addProjectWindow();

    void addProject();
    void checkPath();

    void loadChosenProject();
    void saveNewProject();

    void loadBindedMap();
    void saveBindedMap();
};

class ProjectsList:public QListWidget
{
    Q_OBJECT
   project_manager* wnd;
public:
    ProjectsList(QWidget* parent = 0, project_manager* wnd=0);
    QList<QString> get_items_texts();
public slots:
    void deleteCurrentElement();
};



#endif // PROJECT_MANAGER_H
