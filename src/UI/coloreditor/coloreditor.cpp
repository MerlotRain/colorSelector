#include "coloreditor.h"
#include "ui_coloreditor.h"

ColorEditor::ColorEditor(QWidget *parent)
    : QDialog(parent), ui(new Ui::ColorEditor) {
    ui->setupUi(this);
    setWindowTitle("Color Editor");
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ColorEditor::onOk);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &ColorEditor::onCancel);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ColorEditor::onColorModelChange);
}

ColorEditor::~ColorEditor() {
}

QColor ColorEditor::color() const {
    return QColor();
}

void ColorEditor::onOk() {
}

void ColorEditor::onCancel() {
}

void ColorEditor::onColorModelChange(int index) {
}