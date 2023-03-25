#pragma once
/**
 * @file scheme.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023 By MerlotRain
 * 
 */

#include "color.h"
#include "gradient.h"
#include <string>
#include <vector>

class Scheme {
public:
    Scheme() = default;
    virtual ~Scheme() = default;
    std::string name() const;
    void name(const std::string &name);
    virtual Color color(double value) = 0;
    virtual std::vector<Color> interpolate(int size) = 0;
    virtual void serialize() = 0;
    virtual void deserialize() = 0;

protected:
    std::string _name;
};


class RandomColorScheme : public Scheme {
public:
    RandomColorScheme();
    ~RandomColorScheme();
    Color color(double value) override;
    std::vector<Color> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;
    void setGradient(RandomGradient *gradient);
    RandomGradient *gradient();

protected:
    RandomGradient *_gradient;
};


class ContinuousColorScheme : public Scheme {
public:
    struct Step {
        double begin;
        Gradient *gradient;
    };

    ContinuousColorScheme();
    ~ContinuousColorScheme();
    Color color(double value) override;
    std::vector<Color> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;
    void addStep(Step step);
    void removeStep(int index);

protected:
    std::vector<Step> _steps;
};


class DiscreteColorScheme : public Scheme {
public:
    DiscreteColorScheme();
    ~DiscreteColorScheme();
    Color color(double value) override;
    std::vector<Color> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;
    void addColor(const Color &color);
    void removeColor(int index);

protected:
    std::vector<Color> _colors;
};


class MultiColorScheme : public Scheme {
public:
    struct Step {
        double begin;
        Gradient *gradient;
    };

    MultiColorScheme();
    ~MultiColorScheme();
    Color color(double value) override;
    std::vector<Color> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;

protected:
    std::vector<Step> _steps;
};