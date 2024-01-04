#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QTextEdit>
#include "listnoteitem.h"

// #include <QPainter>

namespace Ui {
class NoteWidget;
}

// forward declaration
class MainWindow;

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(QWidget *parent = nullptr);
    ~NoteWidget();

    void initialize_connection(MainWindow* mainWindow);

    QTextEdit* get_content();

    void set_list_item(ListNoteItem* listItem);

signals:
    void new_note_created(NoteWidget* note);

    void content_changed();

    void delete_confirmed(ListNoteItem* listItem);

public slots:
    void on_deleteConfirmed(ListNoteItem* listItem);

private slots:
    void on_btnClose_clicked();

    void on_btnNewNote_clicked();

    void on_btnPin_clicked();

    void on_btnDelete_clicked();

private:
    Ui::NoteWidget *ui;
    QPoint dragPos;
    ListNoteItem* listItem;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    // void paintEvent(QPaintEvent* event) override;
};

#endif // NOTEWIDGET_H
