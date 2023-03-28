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

#include "gradient.h"
#include <QString>
#include <vector>

class ColorScheme {
public:
    ColorScheme() = default;
    virtual ~ColorScheme() = default;
    QString name() const;
    void name(const QString &name);
    virtual QColor color(double value) = 0;
    virtual std::vector<QColor> interpolate(int size) = 0;
    virtual void serialize() = 0;
    virtual void deserialize() = 0;

protected:
    QString _name;
};


class RandomColorScheme : public ColorScheme {
public:
    RandomColorScheme();
    ~RandomColorScheme();
    QColor color(double value) override;
    std::vector<QColor> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;
    void setGradient(RandomGradient *gradient);
    RandomGradient *gradient();

protected:
    RandomGradient *_gradient;
};


class ContinuousColorScheme : public ColorScheme {
public:
    struct Step {
        double begin;
        ColorGradient *gradient;
    };

    ContinuousColorScheme();
    ~ContinuousColorScheme();
    QColor color(double value) override;
    std::vector<QColor> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;
    void addStep(Step step);
    void removeStep(int index);

protected:
    std::vector<Step> _steps;
};


class DiscreteColorScheme : public ColorScheme {
public:
    DiscreteColorScheme();
    ~DiscreteColorScheme();
    QColor color(double value) override;
    std::vector<QColor> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;
    void addColor(const QColor &color);
    void removeColor(int index);

protected:
    std::vector<QColor> _colors;
};


class MultiColorScheme : public ColorScheme {
public:
    struct Step {
        double begin;
        ColorGradient *gradient;
    };

    MultiColorScheme();
    ~MultiColorScheme();
    QColor color(double value) override;
    std::vector<QColor> interpolate(int size) override;
    void serialize() override;
    void deserialize() override;

protected:
    std::vector<Step> _steps;
};