#pragma once
#include <QtWidgets/QLineEdit>

class CustomLineEdit : public QLineEdit {
    Q_OBJECT

public:
    CustomLineEdit(QWidget* parent = Q_NULLPTR);

private slots:
    void mousePressEvent(QMouseEvent* e);

signals:
    void mouseClick();
protected:
    void mousePressEvent(QMouseEvent* e) override;
};
