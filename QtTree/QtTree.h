#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtTree.h"
#include "Role.h"
#include <memory>  
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QtGlobal>
#include <QTime>
#include <QColor>
#include <random>

using namespace std;

class QtTree : public QMainWindow {
    Q_OBJECT
private:
    Ui::QtTreeClass ui;
    vector<unique_ptr<Role>> roles;
    vector<QWidget*> levelWidgets;

    QPushButton* lastFocusedButton = nullptr;

    void on_addSubordinateBtn_clicked();

private slots:
    void onButtonFocusChanged(QPushButton* button);

public:
    QtTree(QWidget* parent = nullptr);
    ~QtTree();
};
