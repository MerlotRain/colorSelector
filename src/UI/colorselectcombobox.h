/**
 * @file colorselectcombobox.h
 * @brief
 * @author MerlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-27
 * 
*/

#ifndef COLORSELECTCOMBOBOX_H
#define COLORSELECTCOMBOBOX_H

#include <QToolButton>

class ColorSelectComboBox : public QToolButton {
    Q_OBJECT
public:
    explicit ColorSelectComboBox(QColor color = QColor(0, 0, 0), QWidget *parent = nullptr);
    ~ColorSelectComboBox() override;
    void setColor(QColor color);
    QColor color() const;
    void setShowInvalidColor(bool bshow);

Q_SIGNALS:
    void selectColorChange(QColor color);

private:
    QMenu *createColorMenu(const char *slot, const char *slotColrBoard);
    QIcon createColorToolButtonIcon(QColor color);
    QIcon createColorIcon(QColor color);

private:
    QColor _currentColor;
    bool _showInvalidColor;
};


#endif//COLORSELECTCOMBOBOX_H
