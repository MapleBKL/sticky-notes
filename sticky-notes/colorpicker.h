#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QWidget>

// the color options for the note widget
#define ROSEWATER "#F4DBD6"
#define PINK      "#F5C2E7"
#define GREEN     "#A6E3A1"
#define SKY       "#89DCEB"
#define TEAL      "#94E2D5"
#define LAVENDER  "#B4BEFE"
#define YELLOW    "#F8FFAB"
#define GRAY      "#CDD6F4"

namespace Ui {
class ColorPicker;
}

class ColorPicker : public QWidget
{
    Q_OBJECT

public:
    explicit ColorPicker(QWidget *parent = nullptr);
    ~ColorPicker();

signals:
    void new_color_picked(QString color);

private slots:
    void on_btnRosewater_clicked();

    void on_btnPink_clicked();

    void on_btnYellow_clicked();

    void on_btnGreen_clicked();

    void on_btnLavender_clicked();

    void on_btnSky_clicked();

    void on_btnTeal_clicked();

    void on_btnGray_clicked();

private:
    Ui::ColorPicker *ui;
};

#endif // COLORPICKER_H
