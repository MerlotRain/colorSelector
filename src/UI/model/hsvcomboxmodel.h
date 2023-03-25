/**
 * @file hsvcomboxmodel.h
 * @brief
 * @author MerlotRain ${EMAIL}
 * @version 1.0
 * @date 2023-03-25
 * 
*/

#ifndef HSVCOMBOXMODEL_H
#define HSVCOMBOXMODEL_H

#include <QAbstractListModel>
#include <QColor>

struct HSVColorInfo {
    QColor beginColor;
    QColor endColor;
};

class HSVComboxModel : public QAbstractListModel {
    Q_OBJECT
public:
    HSVComboxModel(QObject *parent = nullptr);
    ~HSVComboxModel() override;
    void setModelData();
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
};


#endif//HSVCOMBOXMODEL_H
