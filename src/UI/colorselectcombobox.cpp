#include "colorselectcombobox.h"
#include <QAction>
#include <QGridLayout>
#include <QMenu>
#include <QString>

struct color_info {
    QColor color;
    QString color_name;
    color_info(QString _name, QColor _color)
        : color(_color), color_name(_name) {}
};

// clang-format off
const color_info colorInfos[10][12] = {
        {
            {"Arctic White",        QColor(255, 255, 255)},
            {"Rose Quartz",         QColor(255, 190, 190)},
            {"Sahara Sand",         QColor(255, 235, 190)},
            {"Topaz Sand",          QColor(255, 235, 175)},
            {"Yucca Yellow",        QColor(255, 255, 190)},
            {"Olivine Yellow",      QColor(233, 255, 190)},
            {"Tzavorite Green",     QColor(211, 255, 190)},
            {"Indicolite Green",    QColor(190, 255, 232)},
            {"Sodalite Blue",       QColor(190, 232, 255)},
            {"Sugilite Sky",        QColor(190, 210, 255)},
            {"Lepidolite Lilac",    QColor(232, 190, 255)},
            {"Rhodolite Rose",      QColor(255, 190, 232)}
        },
        {
            {"Gray 10%",            QColor(225, 225, 225)},
            {"Medium Coral Light",  QColor(255, 127, 127)},
            {"Cantaloupe",          QColor(255, 167, 127)},
            {"Mango",               QColor(255, 211, 127)},
            {"Autunite Yellow",     QColor(255, 255, 115)},
            {"Lemongrass",          QColor(209, 255, 115)},
            {"Light Apple",         QColor(163, 255, 115)},
            {"Beryl Green",         QColor(115, 255, 223)},
            {"Apatite Blue",        QColor(115, 223, 255)},
            {"Yogo Blue",           QColor(115, 178, 255)},
            {"Heliotrope",          QColor(223, 115, 255)},
            {"Fushia Pink",         QColor(255, 115, 223)}},
        {   
            {"Gray 20%",            QColor(204, 204, 204)},
            {"Mars Red",            QColor(255,   0,   0)},
            {"Fire Red",            QColor(255,  85,   0)},
            {"Electron Gold",       QColor(255, 170,   0)},
            {"Solar Yellow",        QColor(255, 255,   0)},
            {"Peridot Green",       QColor(170, 255,   0)},
            {"Medium Apple",        QColor( 85, 255,   0)},
            {"Tourmaline Green",    QColor(  0, 255, 197)},
            {"Big Sky Blue",        QColor(  0, 197, 255)},
            {"Cretean Blue",        QColor(  0, 130, 255)},
            {"Amethyst",            QColor(197,   0, 255)},
            {"Ginger Pink",         QColor(255,   0, 197)}
        },
        {
            {"Gray 30%",            QColor(178, 178, 178)},
            {"Poinsettia Red",      QColor(230,   0,   0)},
            {"Flame Red",           QColor(230,  76,   0)},
            {"Seville Orange",      QColor(230, 152,   0)},
            {"Citroen Yellow",      QColor(230, 230,   0)},
            {"Macaw Green",         QColor(152, 230,   0)},
            {"Quetzel Green",       QColor( 76, 230,   0)},
            {"Chrysophase",         QColor(  0, 230, 169)},
            {"Moorea Blue",         QColor(  0, 169, 230)},
            {"Lapis Lazuli",        QColor(  0,  92, 230)},
            {"Anemone Violet",      QColor(169,   0, 230)},
            {"Peony Pink",          QColor(230,   0, 169)}
        },
        {
            {"Gray 40%",            QColor(156, 156, 156)},
            {"Tuscan Red",          QColor(168,   0,   0)},
            {"Cherry Cola",         QColor(168,  56,   0)},
            {"Raw Umber",           QColor(168, 112,   0)},
            {"Olivenite Green",     QColor(168, 168,   0)},
            {"Tarragon Green",      QColor(112, 168,   0)},
            {"Leaf Green",          QColor( 56, 168,   0)},
            {"Malachite Green",     QColor(  0, 168, 132)},
            {"Delft Blue",          QColor(  0, 132, 168)},
            {"Ultra Blue",          QColor(  0,  77, 168)},
            {"Dark Amethyst",       QColor(132,   0, 168)},
            {"Cattleya Orchid",     QColor(168,   0, 132)}
        },
        {
            {"Gray 50%",            QColor(130, 130, 130)},
            {"Dark Umber",          QColor(115,   0,   0)},
            {"Cherrywood Brown",    QColor(115,  38,   0)},
            {"Burnt Umber",         QColor(115,  76,   0)},
            {"Dark Olivenite",      QColor(115, 115,   0)},
            {"Spruce Green",        QColor( 76, 115,   0)},
            {"Fir Green",           QColor( 38, 115,   0)},
            {"Peacock Green",       QColor(  0, 115,  76)},
            {"Steel Blue",          QColor(  0,  76, 115)},
            {"Dark Navy",           QColor(  0,  38, 115)},
            {"Ultramarine",         QColor( 76,   0, 115)},
            {"Purple Heart",        QColor(115,   0,  76)}
        },
        {
            {"Gray 60%",            QColor(104, 104, 104)},
            {"Rose Dust",           QColor(215, 158, 158)},
            {"Soapstone Dust",      QColor(215, 176, 158)},
            {"Tecate Dust",         QColor(215, 194, 158)},
            {"Lime Dust",           QColor(215, 215, 158)},
            {"Apple Dust",          QColor(199, 215, 158)},
            {"Sage Dust",           QColor(180, 215, 158)},
            {"Turquoise Dust",      QColor(158, 215, 194)},
            {"Blue Gray Dust",      QColor(158, 187, 215)},
            {"Violet Dust",         QColor(158, 170, 215)},
            {"Lilac Dust",          QColor(194, 158, 215)},
            {"Tudor Rose Dust",     QColor(214, 157, 188)}
        },
        {
            {"Gray 70%",            QColor( 78,  78,  78)},
            {"Medium Coral",        QColor(245, 122, 122)},
            {"Orange Dust",         QColor(245, 162, 122)},
            {"Medium Sand",         QColor(245, 202, 122)},
            {"Medium Yellow",       QColor(245, 245, 122)},
            {"Medium Lime",         QColor(205, 245, 122)},
            {"Medium Key Lime",     QColor(165, 245, 122)},
            {"Light Vert",          QColor(122, 245, 202)},
            {"Oxide Blue",          QColor(122, 182, 245)},
            {"Medium Azul",         QColor(122, 142, 245)},
            {"Medium Lilac",        QColor(202, 122, 245)},
            {"Medium Fushia",       QColor(245, 122, 182)}
        },
        {
            {"Gray 80%",            QColor( 52,  52,  52)},
            {"Tulip Pink",          QColor(205, 102, 102)},
            {"Nubuck Tan",          QColor(205, 137, 102)},
            {"Light Sienna",        QColor(205, 170, 102)},
            {"Light Olivenite",     QColor(205, 205, 102)},
            {"Medium Olivenite",    QColor(171, 205, 102)},
            {"Fern Green",          QColor(137, 205, 102)},
            {"Jadeite",             QColor(102, 205, 171)},
            {"Atlantic Blue",       QColor(102, 153, 205)},
            {"Pacific Blue",        QColor(102, 119, 205)},
            {"Aster Purple",        QColor(170, 102, 205)},
            {"Protea Pink",         QColor(205, 102, 153)}
        },
        {
            {"Black",               QColor(  0,   0,   0)},
            {"Cordovan Brown",      QColor(137,  68,  68)},
            {"Cocoa Brown",         QColor(137,  90,  68)},
            {"Leather Brown",       QColor(137, 112,  68)},
            {"Lichen Green",        QColor(137, 137,  68)},
            {"Moss Green",          QColor(114, 137,  68)},
            {"Lotus Pond Green",    QColor( 92, 137,  68)},
            {"Deep Forest",         QColor( 68, 137, 112)},
            {"Larkspur Blue",       QColor( 68, 101, 137)},
            {"Glacier Blue",        QColor( 38,  79, 137)},
            {"Blackberry",          QColor(112,  68, 137)},
            {"Cabernet",            QColor(137,  68, 101)}
        }
    };

// clang-format on

ColorSelectComboBox::ColorSelectComboBox(QColor color, QWidget *parent)
    : QToolButton(parent) {
    setPopupMode(QToolButton::MenuButtonPopup);
    setMenu(createColorMenu(SLOT(onColorChanged()), SLOT(onShowColorBoard())));
    setColor(color);
}

ColorSelectComboBox::~ColorSelectComboBox() {
}

QMenu *ColorSelectComboBox::createColorMenu(const char *slot, const char *slotColorBoard) {

    QAction *pActionTransparent = new QAction(this);
    pActionTransparent->setData(QColor(0, 0, 0, 0));//透明色
    pActionTransparent->setText(QObject::tr("No Color"));
    connect(pActionTransparent, SIGNAL(triggered()), this, slot);
    QToolButton *pBtnTransparent = new QToolButton;
    pBtnTransparent->setFixedSize(QSize(142, 20));
    pBtnTransparent->setText(QObject::tr("No Color"));
    pBtnTransparent->setDefaultAction(pActionTransparent);

    QToolButton *pBtnOtherColor = new QToolButton;
    pBtnOtherColor->setText("Color Properties...");
    pBtnOtherColor->setFixedSize(QSize(142, 20));
    pBtnOtherColor->setAutoRaise(true);
    pBtnOtherColor->setToolTip("Color Properties...");
    connect(pBtnOtherColor, SIGNAL(clicked()), this, slotColorBoard);

    QGridLayout *pGridLayout = new QGridLayout;
    pGridLayout->setAlignment(Qt::AlignCenter);
    pGridLayout->setContentsMargins(0, 0, 0, 0);
    pGridLayout->setSpacing(2);

    for (int iRow = 0; iRow < 10; iRow++) {
        for (int iCol = 0; iCol < 12; iCol++) {
            QAction *action = new QAction(this);
            action->setData(colorInfos[iRow][iCol].color);
            action->setIcon(createColorIcon(colorInfos[iRow][iCol].color));
            connect(action, SIGNAL(triggered()), this, slot);

            QToolButton *pBtnColor = new QToolButton();
            pBtnColor->setFixedSize(QSize(16, 16));
            pBtnColor->setAutoRaise(true);
            pBtnColor->setDefaultAction(action);
            pBtnColor->setToolTip(colorInfos[iRow][iCol].color_name);

            pGridLayout->addWidget(pBtnColor, iRow, iCol);
        }
    }

    QWidget *pWidget = new QWidget;
    pWidget->setLayout(pGridLayout);

    QVBoxLayout *pVLayout = new QVBoxLayout;
    pVLayout->addWidget(pBtnTransparent);
    pVLayout->addStretch();
    pVLayout->addWidget(pWidget);
    pVLayout->addStretch();
    pVLayout->addWidget(pBtnOtherColor);

    QMenu *colorMenu = new QMenu(this);
    colorMenu->setLayout(pVLayout);
    colorMenu->addSeparator();
    return colorMenu;
}