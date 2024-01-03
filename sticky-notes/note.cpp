#include "note.h"
#include "ui_note.h"

Note::Note(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Note)
{
    ui->setupUi(this);
}

Note::~Note()
{
    delete ui;
}

void Note::on_btnClose_clicked()
{
    this->close();
}

void Note::mousePressEvent(QMouseEvent *event)
{
    dragPos = event->globalPosition().toPoint();
}

void Note::mouseMoveEvent(QMouseEvent *event)
{
    move(pos() + event->globalPosition().toPoint() - dragPos);
    dragPos = event->globalPosition().toPoint();
    event->accept();
}
