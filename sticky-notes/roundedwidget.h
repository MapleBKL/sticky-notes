#ifndef ROUNDEDWIDGET_H
#define ROUNDEDWIDGET_H

#include <QWidget>
#include <QPainter>

class RoundedWidget: public QWidget
{
    Q_OBJECT

public:
    RoundedWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // ROUNDEDWIDGET_H
