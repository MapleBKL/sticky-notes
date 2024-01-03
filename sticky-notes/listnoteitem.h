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

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

};

#endif // LISTNOTEITEM_H
