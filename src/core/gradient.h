/**
 * @file gradient.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-24
 * 
 */

#pragma once


#include <QColor>
#include <vector>

class ColorGradient {
public:
    ColorGradient() = default;
    virtual ~ColorGradient() = default;
    virtual QColor color(double value) = 0;
    virtual void generateColor(int size, double start = 0, double end = 1) = 0;
};

class LinearGradient : public ColorGradient {
public:
    LinearGradient();
    virtual ~LinearGradient();
    QColor begin();
    void begin(const QColor &color);
    QColor end();
    void end(const QColor &color);

protected:
    QColor _begin, _end;
};


class BlockGradient : public ColorGradient {
public:
    BlockGradient();
    ~BlockGradient();
    QColor bolckcolor();
    void bolckcolor(const QColor &col);
    QColor color(double value) override;
    void generateColor(int size, double start = 0, double end = 1.0) override;

protected:
    QColor _color;
};


class RandomGradient : public ColorGradient {
public:
    RandomGradient();
    ~RandomGradient();
    void minimumColor(const QColor &color);
    QColor minimumColor();
    void maximumColor(const QColor &color);
    QColor maximumColor();
    void seed(int val);
    int seed() const;
    void update();
    std::vector<QColor> sample();
    QColor color(double value) override;
    void generateColor(int size, double start = 0, double end = 1.0) override;

protected:
    QColor _minimumColor;
    QColor _maximumColor;
    int _seed;
};


class LinearHSVGradient : public LinearGradient {
public:
    LinearHSVGradient();
    ~LinearHSVGradient();

    enum class PolarDirection : uint8_t {
        eShortest,
        eLongest,
    };

    void direction(PolarDirection direct);
    QColor color(double value) override;
    void generateColor(int size, double start = 0, double end = 1.0) override;
};
