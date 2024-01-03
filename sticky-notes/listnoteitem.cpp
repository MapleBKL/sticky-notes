#include "listnoteitem.h"
#include "ui_listnoteitem.h"

ListNoteItem::ListNoteItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListNoteItem)
{
    ui->setupUi(this);
}

ListNoteItem::~ListNoteItem()
{
    delete ui;
}
