#ifndef LISTNOTEITEM_H
#define LISTNOTEITEM_H

#include <QListWidgetItem>
#include <QWidget>
#include <QDate>
#include <QMessageBox>

namespace Ui {
class ListNoteItem;
}

class ListNoteItem : public QWidget
{
    Q_OBJECT

public:
    explicit ListNoteItem(QWidget *parent = nullptr);
    ~ListNoteItem();

    void setListWidgetItem(QListWidgetItem* item);
    QListWidgetItem* getListWidgetItem();

private:
    Ui::ListNoteItem* ui;
    QListWidgetItem* item;

    void set_labelDate();

signals:
    void delete_confirmed(ListNoteItem* item);

public slots:
    void on_contentChanged();

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;

private slots:
    void on_btnDelete_clicked();
};

#endif // LISTNOTEITEM_H
