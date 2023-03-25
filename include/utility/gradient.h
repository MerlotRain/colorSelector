#pragma once

/**
 * @file gradient.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023 By MerlotRain
 * 
 */

#include "color.h"
#include <string>
#include <vector>

class Gradient {
public:
    Gradient() = default;
    virtual ~Gradient() = default;
    virtual Color color(double value) = 0;
    virtual void generateColor(int size, double start = 0, double end = 1) = 0;
};

class LinearGradient : public Gradient {
public:
    LinearGradient();
    virtual ~LinearGradient();
    Color begin();
    void begin(const Color &color);
    Color end();
    void end(const Color &color);

protected:
    Color _begin, _end;
};


class BlockGradient : public Gradient {
public:
    BlockGradient();
    ~BlockGradient();
    Color bolckcolor();
    void bolckcolor(const Color &col);
    Color color(double value) override;
    void generateColor(int size, double start = 0, double end = 1.0) override;

protected:
    Color _color;
};


class RandomGradient : public Gradient {
public:
    RandomGradient();
    ~RandomGradient();
    void minimumColor(const Color &color);
    Color minimumColor();
    void maximumColor(const Color &color);
    Color maximumColor();
    void seed(int val);
    int seed() const;
    void update();
    std::vector<Color> sample();
    Color color(double value) override;
    void generateColor(int size, double start = 0, double end = 1.0) override;

protected:
    Color _minimumColor;
    Color _maximumColor;
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
    Color color(double value) override;
    void generateColor(int size, double start = 0, double end = 1.0) override;
};
