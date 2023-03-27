#include "colorslider.h"
#include <QColor>
#include <QPainter>
#include <QRect>
#include <QStyleOption>

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

    static std::list<QColor> hsvColorModel;

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

std::list<QColor> ColorSliderGroove::hsvColorModel << QColor(255, 0, 0) << QColor(255, 255, 0)
                                                   << QColor(0, 255, 0) << QColor(0, 255, 255)
                                                   << QColor(0, 0, 255) << QColor(255, 0, 255);

ColorSliderGroove::ColorSliderGroove(QWidget *parent)
    : QWidget(parent) {
}


ColorSliderGroove::~ColorSliderGroove() = default;

void ColorSliderGroove::paintEvent(QPaintEvent *event) override {
    QStyleOption opt;
    opt.init(this);
    QPainter *painter = new QPainter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, painter, this);

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    QRect rect = this->rect().adjusted(margin + sliderWidth / 2 - interValue, margin,
                                       -(margin + sliderWidth / 2 - interValue),
                                       -margin - sliderHeight);

    //draw margin
    painter->setPen(QColor(200, 200, 200));
    painter->drawRoundedRect(rect, 2, 2);

    //draw gradient
    rect = rect.adjusted(interValue, interValue, -interValue, -interValue);
    QLinearGradient linerGradient(rect.topLeft(), rect.topRight());
    if (hue) {
        for (int i = 0; i < m_colorVec.size(); ++i) {
            qreal part = 1.0 / m_colorVec.size() * i;
            linerGradient.setColorAt(part, m_colorVec[i]);
        }
    } else {
        linerGradient.setColorAt(0, m_cStartColor);
        linerGradient.setColorAt(1, m_cEndColor);
    }

    painter->setPen(Qt::NoPen);
    painter->setBrush(linerGradient);
    painter->drawRoundedRect(rect, 4, 4);

    // 绘制滑动三角形手柄
    painter->setBrush(QColor(220, 220, 220));
    qreal xPt = value * 1.0 / (maximum - minimum) * rect.width() + rect.x();
    QPoint currentPos(xPt, rect.bottom() + interValue + 1);
    QPolygon polygon;
    polygon << currentPos << QPoint(currentPos.x() - sliderWidth / 2, currentPos.y() + sliderHeight)
            << QPoint(currentPos.x() + sliderWidth / 2, currentPos.y() + sliderHeight);
    painter->drawPolygon(polygon);
    painter->restore();

    return QWidget::paintEvent(event);
}

void ColorSliderGroove::mousePressEvent(QMouseEvent *evnet) override {
}

void ColorSliderGroove::mouseMoveEvent(QMouseEvent *evnet) override {
}

void ColorSliderGroove::mouseReleaseEvent(QMouseEvent *event) override {
}

QSize ColorSliderGroove::sizeHint() const override {
    return QSize();
}

void ColorSliderGroove::selectedPoint(const QPoint &pos) {
}