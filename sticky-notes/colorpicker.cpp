#include "colorpicker.h"
#include "ui_colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

ColorPicker::~ColorPicker()
{
    delete ui;
}

void ColorPicker::on_btnRosewater_clicked()
{
    emit new_color_picked(ROSEWATER);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnPink_clicked()
{
    emit new_color_picked(PINK);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnYellow_clicked()
{
    emit new_color_picked(YELLOW);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnGreen_clicked()
{
    emit new_color_picked(GREEN);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnLavender_clicked()
{
    emit new_color_picked(LAVENDER);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnSky_clicked()
{
    emit new_color_picked(SKY);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnTeal_clicked()
{
    emit new_color_picked(TEAL);
    this->close();
    this->deleteLater();
}


void ColorPicker::on_btnGray_clicked()
{
    emit new_color_picked(GRAY);
    this->close();
    this->deleteLater();
}

