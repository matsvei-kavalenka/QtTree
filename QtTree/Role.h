#ifndef ROLE_H
#define ROLE_H

#include <iostream>
#include <vector>
#include <QLineEdit>  

using namespace std;

class Role {
private:
    int x = 8;

public:
    int level;
    string name;
    string position;
    vector<Role> subordinates;
    QLineEdit* roleField;


    Role(int level, string name, string position);

    void addSubordinate(const Role& person);

    void printSubordinates();
    ~Role();
};

#endif
