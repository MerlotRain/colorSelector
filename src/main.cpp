#include <iostream>
#include <QApplication>
#include "UI/colorselectcombobox.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ColorSelectComboBox* col = new ColorSelectComboBox();
    col->show();
    return app.exec();
}