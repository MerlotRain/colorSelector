/**
 * @file colorrampwidget.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-28
 * 
 */

#ifndef COLORRAMPWIDGET_H
#define COLORRAMPWIDGET_H

#include "colormosaicbar.h"

class ColorRampWidget : public ColorMosaicBar {
    Q_OBJECT
public:
    explicit ColorRampWidget(QWidget *parent = nullptr);
    ~ColorRampWidget() override;

protected:
    void paint(QPainter &painter) override;
};

#endif //COLORRAMPWIDGET_H