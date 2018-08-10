#ifndef FILESYSTEMOD_H
#define FILESYSTEMOD_H

#include <QFileSystemModel>

class filesystemod:public QFileSystemModel
{
    Q_OBJECT
public:
    filesystemod(QObject* parent = 0);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // FILESYSTEMOD_H
