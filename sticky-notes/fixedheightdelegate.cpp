#include "fixedheightdelegate.h"

FixedHeightDelegate::FixedHeightDelegate(int height, QWidget* parent)
    : QStyledItemDelegate(parent)
    , height(height)
{}

QSize FixedHeightDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return QSize(QStyledItemDelegate::sizeHint(option, index).width(), height);
}

