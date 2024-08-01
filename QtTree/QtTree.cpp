#include "QtTree.h"

QtTree::QtTree(QWidget *parent)
    : QMainWindow(parent), head(0, "Alice", "Director")
{
    ui.setupUi(this);
	roles.push_back(head);

    Role admin1(1, "Bob", "Developer");
    roles.push_back(admin1);

    Role admin2(1, "Charlie", "Designer");
    roles.push_back(admin2);

    head.addSubordinate(admin1);
    head.addSubordinate(admin2);

}


void QtTree::on_addSubordinateBtn_clicked() {
	QString name = ui.nameField->text();
	QString position = ui.positionField->text();

	Role role(0, name.toStdString(), position.toStdString());


	ui.nameField->clear();
	ui.positionField->clear();
}





QtTree::~QtTree()
{}
