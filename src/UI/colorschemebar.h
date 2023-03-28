/**
 * @file colorschemebar.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-28
 * 
 */

#ifndef COLORSCHEMEBAR_H
#define COLORSCHEMEBAR_H

#include "../core/gradient.h"
#include "../core/scheme.h"
#include <QWidget>

class ColorSchemeBar : public QWidget {
    Q_OBJECT
public:
    explicit ColorSchemeBar(QWidget *parent = nullptr);
    ~ColorSchemeBar();

    void setColorScheme(ColorScheme *scheme);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif //COLORSCHEMEBAR_H