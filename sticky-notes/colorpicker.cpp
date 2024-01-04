#include "colorpicker.h"
#include "ui_colorpicker.h"

ColorPicker::ColorPicker(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ColorPicker)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::Tool);
}

ColorPicker::~ColorPicker()
{
    delete ui;
}

void ColorPicker::on_btnRosewater_clicked()
{
    emit new_color_picked(ROSEWATER);
    delete_and_return_focus();
}


void ColorPicker::on_btnPink_clicked()
{
    emit new_color_picked(PINK);
    delete_and_return_focus();
}


void ColorPicker::on_btnYellow_clicked()
{
    emit new_color_picked(YELLOW);
    delete_and_return_focus();
}


void ColorPicker::on_btnGreen_clicked()
{
    emit new_color_picked(GREEN);
    delete_and_return_focus();
}


void ColorPicker::on_btnLavender_clicked()
{
    emit new_color_picked(LAVENDER);
    delete_and_return_focus();
}


void ColorPicker::on_btnSky_clicked()
{
    emit new_color_picked(SKY);
    delete_and_return_focus();
}


void ColorPicker::on_btnTeal_clicked()
{
    emit new_color_picked(TEAL);
    delete_and_return_focus();
}


void ColorPicker::on_btnGray_clicked()
{
    emit new_color_picked(GRAY);
    delete_and_return_focus();
}

void ColorPicker::delete_and_return_focus()
{
    this->close();
    this->deleteLater();
    qobject_cast<QWidget*>(parent())->activateWindow();
}

