#include "QtTree.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

int QtTree::levels = -1;

QtTree::QtTree(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.addSubordinateBtn, &QPushButton::clicked, this, &QtTree::on_addSubordinateBtn_clicked);
}

void QtTree::on_addSubordinateBtn_clicked() {
    QString levelText = ui.levelEdit->text(); 
    int level = levelText.toInt();

	cout << widgetVector.size() << endl;

    
    if (widgetVector.size() <= level ){
		createLevel(level);
    }

	QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(widgetVector[level]->layout());

	QString name = ui.nameField->text();
	QString position = ui.positionField->text();

	QLineEdit* roleField = new QLineEdit(name);
	roleField->setObjectName("roleField");

	layout->addWidget(roleField);

	ui.nameField->clear();
	ui.positionField->clear();
}


void QtTree::createLevel(int level) {
    QWidget* horizontalLayoutWidget = new QWidget(ui.treeFrame);
    QString widgetName = QString("horizontalLayoutWidget_%1").arg(level);
    horizontalLayoutWidget->setObjectName(widgetName);

    QHBoxLayout* levelLayout = new QHBoxLayout(horizontalLayoutWidget);
    levelLayout->setSpacing(6);
    levelLayout->setContentsMargins(11, 11, 11, 11);

    horizontalLayoutWidget->setLayout(levelLayout);
    if (!ui.treeFrame->layout()) {
        qWarning() << "No layout set for treeFrame. Setting QVBoxLayout.";
        QVBoxLayout* frameLayout = new QVBoxLayout(ui.treeFrame);
        ui.treeFrame->setLayout(frameLayout);
    }

    ui.treeFrame->layout()->addWidget(horizontalLayoutWidget);
    widgetVector.push_back(horizontalLayoutWidget);

	
}

QtTree::~QtTree() {
}
