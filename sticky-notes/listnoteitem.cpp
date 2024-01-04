#include "listnoteitem.h"
#include "ui_listnoteitem.h"
#include "notewidget.h"

ListNoteItem::ListNoteItem(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListNoteItem)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);
    // the open and delete buttons are inititally hidden
    ui->btnOpen->setVisible(false);
    ui->btnDelete->setVisible(false);
}

ListNoteItem::~ListNoteItem()
{
    delete ui;
}

void ListNoteItem::setListWidgetItem(QListWidgetItem *item)
{
    this->item = item;
}

QListWidgetItem *ListNoteItem::getListWidgetItem()
{
    return this->item;
}

void ListNoteItem::on_contentChanged()
{
    NoteWidget* content = qobject_cast<NoteWidget*>(sender());

    // If the sticky note contains multiple lines, we only want to show the first two lines

    // extract all the lines
    QStringList lines = content->get_content()->toPlainText().split('\n');

    // extract the first 2 lines (or 1 line if only 1 line is present)
    QString headLines = "";
    if (lines.size() >= 2)
    {
        headLines = lines[0] + "\n" + lines[1];
    }
    else if (!lines.isEmpty())
    {
        headLines = lines[0];
    }

    // update list item content
    ui->browserNoteContent->setPlainText(headLines);
}

void ListNoteItem::enterEvent(QEnterEvent *event)
{
    Q_UNUSED(event);
    ui->btnOpen->setVisible(true);
    ui->btnDelete->setVisible(true);
}

void ListNoteItem::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
        ui->btnOpen->setVisible(false);
    ui->btnDelete->setVisible(false);
}

void ListNoteItem::on_btnDelete_clicked()
{
    auto decision = messageBox.question(this, "", "Delete this note?");
    if (decision == QMessageBox::Yes)
    {
        emit delete_confirmed(this);
    }
}

