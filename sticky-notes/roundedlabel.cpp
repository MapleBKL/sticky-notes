#include "roundedlabel.h"

RoundedLabel::RoundedLabel(QWidget *parent): QLabel(parent) {}

void RoundedLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QColor(255, 255, 255, 0));
    painter.drawRoundedRect(rect(), 10, 10);
}
