#ifndef LISTNOTEITEM_H
#define LISTNOTEITEM_H

#include <QWidget>

namespace Ui {
class ListNoteItem;
}

class ListNoteItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListNoteItem(QWidget *parent = nullptr);
    ~ListNoteItem();

private:
    Ui::ListNoteItem *ui;
};

#endif // LISTNOTEITEM_H
