#ifndef NOTEWIDGET_H
#define NOTEWIDGET_H

#include <QWidget>
#include <QMouseEvent>
// #include <QPainter>

namespace Ui {
class NoteWidget;
}

class NoteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NoteWidget(QWidget *parent = nullptr);
    ~NoteWidget();

private slots:
    void on_btnClose_clicked();

private:
    Ui::NoteWidget *ui;
    QPoint dragPos;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    // void paintEvent(QPaintEvent* event) override;
};

#endif // NOTEWIDGET_H
