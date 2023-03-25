#include "hsvcomboxmodel.h"

HSVComboxModel::HSVComboxModel(QObject *parent) : QAbstractListModel(parent) {
}

HSVComboxModel::~HSVComboxModel() {
}

void HSVComboxModel::setModelData() {
}

QVariant HSVComboxModel::headerData(int section, Qt::Orientation orientation, int role) const {
    return QAbstractItemModel::headerData(section, orientation, role);
}

int HSVComboxModel::rowCount(const QModelIndex &parent) const {
    return 0;
}

QVariant HSVComboxModel::data(const QModelIndex &index, int role) const {
    return QVariant();
}

Qt::ItemFlags HSVComboxModel::flags(const QModelIndex &index) const {
    return QAbstractListModel::flags(index);
}
