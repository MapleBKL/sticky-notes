#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Note;
}

class Note : public QWidget
{
    Q_OBJECT

public:
    explicit Note(QWidget *parent = nullptr);
    ~Note();

private slots:
    void on_btnClose_clicked();

private:
    Ui::Note *ui;
    QPoint dragPos;

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif // NOTE_H
