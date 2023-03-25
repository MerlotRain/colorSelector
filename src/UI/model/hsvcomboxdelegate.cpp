#include "hsvcomboxdelegate.h"
#include <QBrush>
#include <QColor>
#include <QConicalGradient>
#include <QPainter>
#include <QPen>
#include <QPixmap>

/*
 * ______________
 * |            |
 * |            |
 * |            |
 * |____________/
 *     text
 */

HSVComboxDelegete::HSVComboxDelegete(QObject *parent) : QStyledItemDelegate(parent) {
}

HSVComboxDelegete::~HSVComboxDelegete() {
}

static QList<QColor> hsvColors = {
        QColor(255, 0, 0),
        QColor(255, 255, 0),
        QColor(0, 255, 0),
        QColor(0, 255, 255),
        QColor(0, 0, 255),
        QColor(255, 0, 255)};

static qreal angle = 1.0 / hsvColors.size();

void HSVComboxDelegete::paint(QPainter *painter, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const {

    QStyleOptionViewItem optionViewItem(option);
    if (optionViewItem.state & QStyle::State_HasFocus) {
        optionViewItem.state = optionViewItem.state ^ QStyle::State_HasFocus;
    }

    QString str = index.model()->data(index, Qt::UserRole).toString();
    if (str.isEmpty()) {
        return;
    }

    QPixmap pixmap;
    QRect rect;
    QConicalGradient conicalGradient(rect.center(), 0);
    for (int i = 0; i < hsvColors.size(); ++i) {
        conicalGradient.setColorAt(i * angle, hsvColors.at(i));
    }
    conicalGradient.setColorAt(1.0, hsvColors.at(0));

    painter->setBrush(conicalGradient);
    painter->setPen(QPen(Qt::NoPen));


    QStyledItemDelegate::paint(painter, option, index);
}

bool HSVComboxDelegete::editorEvent(QEvent *event, QAbstractItemModel *model,
                                    const QStyleOptionViewItem &option, const QModelIndex &index) {
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}
