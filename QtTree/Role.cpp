#include "Role.h"

int Role::idCounter = 0;


Role::Role(int level, string name, string position): id(++idCounter) {
	this->level = level;
	this->name = name;
	this->position = position;
	id++;

}

void Role::addSubordinate(Role* person) {
	if (person) {
		cout << "Adding " << person->name << " as a subordinate of " << this->name << endl;
		subordinates.push_back(person);
	}
}

void Role::printSubordinates() {
	for (const Role* person : subordinates) {
		cout << person->name << endl;
	}
}

