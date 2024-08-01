#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtTree.h"
#include "Role.h"

using namespace std;

class QtTree : public QMainWindow{
    Q_OBJECT
public:
    QtTree(QWidget *parent = nullptr);
    ~QtTree();

private:
    Ui::QtTreeClass ui;
    vector<Role> roles;
    Role head;
private slots:
    void on_addSubordinateBtn_clicked();
};
