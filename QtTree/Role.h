#ifndef ROLE_H
#define ROLE_H

#include <iostream>
#include <vector>

using namespace std;

class Role {
private:
    int x = 8;
    static int idCounter;
    int id;

public:
    int level;
    string name;
    string position;
    vector<Role*> subordinates;


    Role(int level, string name, string position);

    void addSubordinate(Role* person);

    void printSubordinates();
};

#endif
