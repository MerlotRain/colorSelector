/**
 * @file colorblockwidget.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-28
 * 
 */

#include "colormosaicbar.h"

class ColorBlockWidget : public ColorMosaicBar {
    Q_OBJECT
    explicit ColorBlockWidget(QWidget *parent = nullptr);
    ~ColorBlockWidget();
    void setColor(QColor color);

protected:
    void paint(QPainter &painter) override;
    void mousePressEvent(QMouseEvent *evnet) override;
    void mouseMoveEvent(QMouseEvent *evnet) override;
    void mouseReleaseEvent(QMouseEvent *evnet) override;

Q_SIGNALS:
    void clicked(QColor color);
    void colorChange(QColor previous, QColor current);

private:
    QColor _color;
    QString _name;
};