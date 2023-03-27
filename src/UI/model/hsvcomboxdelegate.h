#pragma once

/**
 * @file hsvcomboxdelegate.h
 * @brief
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-24
 *
 */

#include <QStyledItemDelegate>

class HSVComboxDelegete : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit HSVComboxDelegete(QObject *parent = nullptr);
    ~HSVComboxDelegete() override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

protected:
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option,
                     const QModelIndex &index) override;
};