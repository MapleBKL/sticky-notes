#include "listnoteitem.h"
#include "ui_listnoteitem.h"

ListNoteItem::ListNoteItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListNoteItem)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);
    // the delete button is inititally hidden
    ui->btnDelete->setVisible(false);
}

ListNoteItem::~ListNoteItem()
{
    delete ui;
}

void ListNoteItem::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    ui->btnDelete->setVisible(true);
}

void ListNoteItem::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    ui->btnDelete->setVisible(false);
}
