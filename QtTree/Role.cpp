#include "Role.h"


Role::Role(int level, string name, string position) {
	this->level = level;
	this->name = name;
	this->position = position;

	roleField = new QLineEdit();
	roleField->setText(QString::fromStdString(name));
	roleField->setObjectName("roleField");
	roleField->setGeometry(QRect(400, 300, 100, 25));
}

void Role::addSubordinate(const Role& person) {
	cout << "Adding " << person.name << " as a subordinate of " << this->name << endl;
	subordinates.push_back(person);
}

void Role::printSubordinates() {
	for (Role person : subordinates) {
		cout << person.name << endl;
	}
}


Role::~Role() {
	delete roleField;
}