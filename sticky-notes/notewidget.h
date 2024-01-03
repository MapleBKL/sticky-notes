#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

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

signals:
    void new_note_created(NoteWidget* note);

private slots:
    void on_btnClose_clicked();

    void on_btnNewNote_clicked();

private:
    Ui::NoteWidget *ui;
    QPoint dragPos;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    // void paintEvent(QPaintEvent* event) override;
};

#endif // NOTEWIDGET_H
