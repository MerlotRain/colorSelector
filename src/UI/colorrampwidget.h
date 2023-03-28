/**
 * @file colorrampwidget.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-28
 * 
 */

#include "colormosaicbar.h"

class ColorRampWidget : public ColorMosaicBar {
    Q_OBJECT
public:
    explicit ColorRampWidget(QWidget *parent = nullptr);
    ~ColorRampWidget();
};