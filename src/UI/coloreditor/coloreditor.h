/**
 * @file coloreditor.h
 * @brief 
 * @author merlotRain (1198477036@qq.com)
 * @version 1.0
 * @date 2023-03-27
 *  
 */

#include <QColor>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
    class ColorEditor;
}
QT_END_NAMESPACE

class ColorEditor : public QDialog {
    Q_OBJECT
public:
    explicit ColorEditor(QWidget *parent = nullptr);
    ~ColorEditor();
    QColor color() const;

private slots:
    void onOk();
    void onCancel();
    void onColorModelChange(int index);

private:
    Ui::ColorEditor *ui;
};