#include "roundedwidget.h"

RoundedWidget::RoundedWidget(QWidget *parent): QWidget(parent) {}

void RoundedWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(255, 255, 255, 200));
    painter.drawRoundedRect(rect(), 10, 10);
}
