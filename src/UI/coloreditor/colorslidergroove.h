/**
 * @file colorslidergroove.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-27
 * 
 */

#include <QColor>
#include <QPoint>
#include <QSize>
#include <QWidget>
#include <vector>

class ColorSliderGroove : public QWidget {
    Q_OBJECT
public:
    explicit ColorSliderGroove(QWidget *parent = nullptr);
    ~ColorSliderGroove() = default;
    QColor beginColor;
    QColor endColor;
    int value;
    bool hue;
    int margin;
    int sliderWidth;
    int sliderHeight;
    int interValue;
    int maximum;
    int minimum;

    static std::vector<QColor> hsvColorModel;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *evnet) override;
    void mouseMoveEvent(QMouseEvent *evnet) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    QSize sizeHint() const override;

private:
    void selectedPoint(const QPoint &pos);
Q_SIGNALS:
    void valueChange(int value);
};