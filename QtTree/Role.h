#ifndef ROLE_H
#define ROLE_H

#include <iostream>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QString>
#include <QEvent>
#include <QFrame>
#include <QPainter>



using namespace std;

class Role : public QObject {
    Q_OBJECT
private:
    static int idCounter;
    int id;
    int level;
    QPushButton* roleButton;
    QColor color;


public:
    string name;
    string position;
    vector<Role*> subordinates;


    Role(int level, QString name, QString position, QColor color, QWidget* parent);

    
    void addSubordinate(Role* person);

    void printSubordinates();

    int getId() const { return id; };
    int getLevel() const { return level; };
    QColor getColor() const { return color; };
    QPushButton* getButton() const { return roleButton; }
protected:
    bool eventFilter(QObject* watched, QEvent* event) override;
signals:
    void focusChanged(QPushButton* button);

};

#endif
