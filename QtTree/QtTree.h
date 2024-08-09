#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtTree.h"
#include "Role.h"

using namespace std;

class QtTree : public QMainWindow{
    Q_OBJECT
private:
    Ui::QtTreeClass ui;
    vector<Role> roles;
    static int levels;
    vector<QWidget*> widgetVector;

    void on_addSubordinateBtn_clicked();
    void createLevel(int level);
public:
    QtTree(QWidget *parent = nullptr);
    ~QtTree();
};
