/**
 * @file colorslider.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-27
 * 
 */

#include <QWidget>

class ColorSliderGroove;
class ColorSlider : public QWidget {
    Q_OBJECT
public:
    explicit ColorSlider(QWidget *parent = nullptr);
    ~ColorSlider() noexcept override;

private:
    ColorSliderGroove *_groove;
};