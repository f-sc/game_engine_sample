#include "filesystemod.h"

filesystemod::filesystemod(QObject* parent): QFileSystemModel(parent)
{

}

QVariant filesystemod::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole && index.column() == 0) {
            QString path  = QDir::toNativeSeparators(filePath(index));
            if (path.endsWith(QDir::separator()))
                path.chop(1);
            return path;
        }

        return QFileSystemModel::data(index, role);
}

