#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "notewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_newNoteCreated(NoteWidget* note);

private slots:
    void on_btnMinimize_clicked();

    void on_btnClose_clicked();

    void on_btnNewNote_clicked();

    void on_deleteConfirmed(ListNoteItem* listItem);

private:
    Ui::MainWindow *ui;
    QPoint dragPos;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    void add_item_to_list(NoteWidget* note);
};
#endif // MAINWINDOW_H
