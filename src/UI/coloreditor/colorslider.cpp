#include "colorslider.h"
#include "colorslidergroove.h"
#include <QColor>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QStyleOption>

std::vector<QColor> ColorSliderGroove::hsvColorModel = {QColor(255, 0, 0), QColor(255, 255, 0),
                                                        QColor(0, 255, 0), QColor(0, 255, 255),
                                                        QColor(0, 0, 255), QColor(255, 0, 255)};

ColorSliderGroove::ColorSliderGroove(QWidget *parent)
    : QWidget(parent) {
}

void ColorSliderGroove::paintEvent(QPaintEvent *event) {
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
        for (int i = 0; i < hsvColorModel.size(); ++i) {
            qreal part = 1.0 / hsvColorModel.size() * i;
            linerGradient.setColorAt(part, hsvColorModel.at(i));
        }
    } else {
        linerGradient.setColorAt(0, beginColor);
        linerGradient.setColorAt(1, endColor);
    }

    painter->setPen(Qt::NoPen);
    painter->setBrush(linerGradient);
    painter->drawRoundedRect(rect, 4, 4);

    // draw slider groove
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

void ColorSliderGroove::mousePressEvent(QMouseEvent *evnet) {
}

void ColorSliderGroove::mouseMoveEvent(QMouseEvent *evnet) {
}

void ColorSliderGroove::mouseReleaseEvent(QMouseEvent *event) {
}

QSize ColorSliderGroove::sizeHint() const {
    return QSize();
}

void ColorSliderGroove::selectedPoint(const QPoint &pos) {
}




ColorSlider::ColorSlider(QWidget *parent) {}

ColorSlider::~ColorSlider() noexcept {}