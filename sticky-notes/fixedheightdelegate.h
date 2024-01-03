#ifndef FIXEDHEIGHTDELEGATE_H
#define FIXEDHEIGHTDELEGATE_H

#include <QStyledItemDelegate>

class FixedHeightDelegate: public QStyledItemDelegate {
public:
    FixedHeightDelegate(int height, QWidget* parent = nullptr);
    QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const override;

private:
    int height;
};

#endif // FIXEDHEIGHTDELEGATE_H
