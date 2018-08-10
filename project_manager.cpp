#include "project_manager.h"

 project_manager::project_manager(QWidget* parent, map_elements* map_view):parent(parent), map_view(map_view)
{

}

 ProjectsList::ProjectsList(QWidget* parent, project_manager* wnd):QListWidget(parent), wnd(wnd)
 {

 }

void project_manager::showProjectManager()
{
    QDir dir;
    QFile fp(QString(dir.currentPath()+"/"+"params.cfg"));
    qDebug() << "COnfig file:" << fp.fileName();
    fp.open(QIODevice::ReadOnly);
    w_pm_main = new QWidget(parent, 0);
    w_pm_main ->setObjectName("w_pm_main");
    w_pm_main ->resize(300, 300);
    w_pm_main ->move(250, 200);
    w_pm_main->setStyleSheet(QString("background: rgba(0, 0, 0, 90); border: 1px solid; border-radius: 8px;"));
    QGridLayout* layout = new QGridLayout(  w_pm_main );
    QLabel* caption = new QLabel(  w_pm_main );
    caption->setText("Project manager");
    caption->setStyleSheet("color: white; background: rgba(0, 0, 0, 0); border: 0px;");
    ProjectsList* lastProjects = new ProjectsList(w_pm_main, (project_manager*)(this));//перекинуть в главный класс
    lastProjects->setStyleSheet("color: white");
    lastProjects->setObjectName("lst_projects");
    if(fp.isOpen())
    {
        QByteArray in = fp.readAll();
        lastProjects->addItems(QStringList(QString::fromStdString(in.toStdString()).split(';')));
        project_names.push_back(QString::fromStdString(in.toStdString()));
        fp.close();
    }
    QPushButton* CreateNew = new QPushButton(  w_pm_main );
    CreateNew->setText("Create New Project");
    CreateNew->setStyleSheet("color: white; background-color: #27a9e3; border-radius: 3px");
   // ok_btn->move(QPoint(ok_btn->pos().x()+10, ok_btn->pos().y()));
    QPushButton* LoadProject = new QPushButton(w_pm_main);
    LoadProject->setText("Load Chosen Project");
    LoadProject->setStyleSheet("color: white; background-color: #27a9e3");
    QPushButton* RemoveChosenProject = new QPushButton(w_pm_main);
    RemoveChosenProject->setText("Remove Chosen Project");
    RemoveChosenProject->setStyleSheet("color: white; background-color: #27a9e3");
    QPushButton* Close = new QPushButton(w_pm_main);
    Close->setText("Close");
    Close->setStyleSheet("color: white; background-color: #27a9e3");
    QEventLoop::connect(Close, SIGNAL(clicked(bool)), w_pm_main, SLOT(close()));
    QEventLoop::connect(CreateNew, SIGNAL(clicked(bool)), this, SLOT(addProjectWindow()));
    QEventLoop::connect(LoadProject, SIGNAL(clicked(bool)), this, SLOT(loadChosenProject()));
    QEventLoop::connect(RemoveChosenProject, SIGNAL(clicked(bool)), lastProjects, SLOT(deleteCurrentElement()));
    layout->addWidget(caption);
    layout->addWidget(lastProjects);
    layout->setAlignment(caption, Qt::AlignCenter);
    layout->addWidget(CreateNew);
    layout->addWidget(LoadProject);
    layout->addWidget(RemoveChosenProject);
    layout->addWidget(Close);
    w_pm_main->show();
}

void project_manager::addProjectWindow()
{
    w_pm_main->close();
    w_project_manager = new QWidget(parent, 0);
    w_project_manager ->setObjectName("w_new_project");
    w_project_manager ->resize(200, 220);
    w_project_manager ->move(300, 250);
    w_project_manager ->setStyleSheet(QString("background: rgba(0, 0, 0, 90); border: 1px solid; border-radius: 8px;"));
    QLabel* caption = new QLabel(  w_project_manager );
    QLineEdit* Name = new QLineEdit(  w_project_manager );
    QLineEdit* Developer = new QLineEdit(  w_project_manager );
    QLineEdit* Path = new QLineEdit(  w_project_manager );
    QLineEdit* MapName = new QLineEdit(  w_project_manager );
    Name->setObjectName("i_PName");
    Name->setStyleSheet("background-color: white;");
    Developer->setStyleSheet("background-color: white;");
    Path->setObjectName("i_PPath");
    Developer->setObjectName("i_PDeveloper");
    Name->setText("Name");
    Path->setText("/Users/2ima/Documents");
    MapName->setObjectName("i_PMapName");
    MapName->setStyleSheet("background-color: white;");
    Developer->setText("Developer_Name");
    checkPath();
    caption->setText("        New project:");
    caption->setStyleSheet("color: white; background: rgba(0, 0, 0, 0); border: 0px;");
    QPushButton* ok_btn = new QPushButton(  w_project_manager );
    ok_btn->setText("Create");
    ok_btn->setStyleSheet("color: white; background-color: #27a9e3; border-radius: 3px");
   // ok_btn->move(QPoint(ok_btn->pos().x()+10, ok_btn->pos().y()));
    QPushButton* can_btn = new QPushButton();
    can_btn->setText("Cancel");
    can_btn->setStyleSheet("color: white; background-color: #27a9e3");
    QEventLoop::connect(can_btn, SIGNAL(clicked(bool)), w_project_manager, SLOT(close()));

    QEventLoop::connect(Path, SIGNAL(textChanged(QString)), this, SLOT(checkPath()));
     QEventLoop::connect(can_btn, SIGNAL(clicked(bool)), w_pm_main, SLOT(show()));
     QEventLoop::connect(ok_btn, SIGNAL(clicked(bool)), this, SLOT(addProject()));
     if(w_project_manager->layout()==0)
     {
         QGridLayout* layout = new QGridLayout(  w_project_manager );
         layout->addWidget(caption);
         layout->addWidget(Name);
         layout->addWidget(Path);
         layout->addWidget(Developer);
         layout->addWidget(ok_btn);
         layout->addWidget(can_btn);
         layout->addWidget(MapName);
    }
    w_project_manager->show();
}

void project_manager::addProject()
{
    QLineEdit* temp_edit_name = 0;
    QLineEdit* temp_edit_path = 0;
    for(auto proj_name: w_project_manager->children())
    {
        if(proj_name->objectName() == "i_PName")
        {
            temp_edit_name = dynamic_cast<QLineEdit*>(proj_name);
        }
        if(proj_name->objectName() == "i_PPath")
        {
            temp_edit_path = dynamic_cast<QLineEdit*>(proj_name);
        }
        }
    for(auto project_comp: w_pm_main->children())
    {
        if(project_comp->objectName() == "lst_projects")
        {

             dynamic_cast<QListWidget*>(project_comp)->insertItem(0, new QListWidgetItem(QString(temp_edit_name->text()+" "+temp_edit_path->text())));
        }
    }
    w_project_manager->close();
    w_pm_main->show();
    saveNewProject();
    saveProjectConfig();
}

void ProjectsList::deleteCurrentElement()
{
    this->takeItem(this->currentRow());
    wnd->saveProjectConfig();
}

QList<QString> ProjectsList::get_items_texts()
{
    QList<QString> temp;
    for(int i=0; i<this->count(); i++)
    {
        qDebug() << "AAA: " << this->item(i)->text();
        temp.push_back(this->item(i)->text());
    }
    return temp;
}

void project_manager::saveProjectConfig()
{
    QDir dir;
    QFile fp(QString(dir.currentPath()+"/"+"params.cfg"));
     qDebug() << "FILES: " << fp.fileName();
    fp.open(QIODevice::WriteOnly);
    if(fp.isOpen())
    {
        for(auto project_comp: w_pm_main->children())
        {
            if(project_comp->objectName() == "lst_projects")
            {
                for(QString project_names: (dynamic_cast<ProjectsList*>(project_comp)->get_items_texts()))
                {

                    fp.write(QByteArray::fromStdString(project_names.toStdString()));
                    fp.write(";");
                }
            }
        }
        fp.close();
    }
}

void project_manager::checkPath()
{
    QLineEdit* line = 0;
    for(auto elements: w_project_manager->children())
    {
        if(elements->objectName() == "i_PPath")
        {
            line = dynamic_cast<QLineEdit*>(elements);
        }
    }
    QDir dir(line->text());
    if(!dir.exists())
    {
      line->setStyleSheet("background-color: red");
    }
    else
    {
        line->setStyleSheet("background-color: white");
    }
}

void project_manager::loadChosenProject()
{
    QFile fp;
    pinfo = new project_info;

     map_view->clearMapView();

    for(auto form_elements: w_pm_main->children())
    {
        if(form_elements->objectName() == "lst_projects")
        {
            if(dynamic_cast<QListWidget*>(form_elements)->currentItem() != NULL && dynamic_cast<QListWidget*>(form_elements)->currentItem()->text() != "")
            {
            QStringList temp = (dynamic_cast<QListWidget*>(form_elements))->currentItem()->text().split(' ');
            fp.setFileName(QString(temp.at(1)+"/"+temp.at(0)+".fpr"));
            }
            else
            {
                QMessageBox msg;
                msg.setText("No project chosen!");
                msg.exec();
            }
        }
    }
    fp.open(QIODevice::ReadOnly);
    qDebug() << "Config:" << fp.fileName();
    if(fp.isOpen())
    {
        QList<QByteArray> in = fp.readAll().split(' ');
        if(in.length()>=5)
        {
                pinfo->name = in.at(0);
                pinfo->developer = in.at(1);
                pinfo->path = in.at(2);
                pinfo->cfg_elem_name= in.at(3);
                pinfo->map_name = in.at(4);
        }
        parent->setWindowTitle(QString("["+pinfo->name+"] "+pinfo->map_name));
        map_view->LoadMap(QString(pinfo->path+"/"+pinfo->map_name));
        qDebug() << "MAP: " << QString(pinfo->path+"/"+pinfo->map_name);
        w_pm_main->close();
        for(auto form_elements: parent->children())
        {
            if(form_elements->objectName() == "b_saveLvl")
            {
              dynamic_cast<QToolButton*>(form_elements)->setEnabled(true);
              dynamic_cast<QToolButton*>(form_elements)->setStyleSheet("color: white; background: rgba(0, 250, 195, 80); border: 1.5px solid; border-radius: 7px;");
            }
            else if(form_elements->objectName() == "b_loadlvl")
            {
              dynamic_cast<QToolButton*>(form_elements)->setEnabled(true);
              dynamic_cast<QToolButton*>(form_elements)->setStyleSheet("color: white; background: rgba(0, 250, 195, 80); border: 1.5px solid; border-radius: 7px;");
            }
        }
        fp.close();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Error, project file not found or corrupted.");
        msg.exec();
    }

}

void project_manager::saveNewProject()
{
    QFile fp;
    QString filename = "";
     pinfo = new project_info;
    for(auto elements: w_project_manager->children())
    {
        if(elements->objectName() == "i_PPath")
        {
            pinfo->path=((QLineEdit*)(elements))->text();
        }
        else if(elements->objectName() == "i_PName")
        {
           pinfo->name = ((QLineEdit*)(elements))->text();
        }
        else if(elements->objectName() == "i_PDeveloper")
        {
           pinfo->developer = ((QLineEdit*)(elements))->text();
        }
        else if(elements->objectName() == "i_PMapName")
        {
           pinfo->map_name = ((QLineEdit*)(elements))->text();
        }

        pinfo->cfg_elem_name = QString("params.cfg");
    }
    fp.setFileName(QString(pinfo->path+"/"+pinfo->name+".fpr"));
    fp.open(QIODevice::WriteOnly);
    qDebug() << fp.fileName();
    if(fp.isOpen())
    {
        fp.write(QByteArray::fromStdString((QString( pinfo->name+" "+pinfo->developer+" "+pinfo->path+" "+pinfo->cfg_elem_name+" "+pinfo->map_name).toStdString())));
        fp.close();
    }
    else
    {
        QMessageBox msg;
        msg.setText("Error, project was not created.\n Check if you have enougth rights to access folder you want to store project");
        msg.exec();
    }
    map_view->SaveMap(QString(pinfo->path+"/"+pinfo->map_name));
}

void project_manager::loadBindedMap()
{
    map_view->LoadMap(QString(pinfo->path+"/"+pinfo->map_name));
}

void project_manager::saveBindedMap()
{
        qDebug() << "OUT map: " << QString(pinfo->path+"/"+pinfo->map_name);
    if(map_view != NULL && pinfo!=NULL)
    {
    map_view->SaveMap(QString(pinfo->path+"/"+pinfo->map_name));
    }
    else
    {
        QMessageBox msg;
        msg.setText("Nothing to save yet.");
    }
}
