#include "CustomLineEdit.h"

CustomLineEdit::CustomLineEdit(QWidget* parent)
    : QLineEdit(parent) {
}

void CustomLineEdit::mousePressEvent(QMouseEvent* e) {
    if (e->button() == Qt::RightButton) {
        emit mouseClick();  
    }

    QLineEdit::mousePressEvent(e);
}
