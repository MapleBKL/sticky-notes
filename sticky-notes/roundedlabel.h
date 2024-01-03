#ifndef ROUNDEDLABEL_H
#define ROUNDEDLABEL_H

#include <QLabel>
#include <QPainter>

class RoundedLabel: public QLabel
{
    Q_OBJECT

public:
    RoundedLabel(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // ROUNDEDLABEL_H
