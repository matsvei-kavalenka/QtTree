#include "QtTree.h"

QtTree::QtTree(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    levelWidgets.clear();

    connect(ui.addSubordinateBtn, &QPushButton::clicked, this, &QtTree::on_addSubordinateBtn_clicked);
}

void QtTree::on_addSubordinateBtn_clicked() {
    QString name = ui.nameField->text();
    QString position = ui.positionField->text();

    if (lastFocusedButton) {
        void* ptr = lastFocusedButton->property("rolePtr").value<void*>();
        Role* roleHead = static_cast<Role*>(ptr);
        QColor color = roleHead->getColor();

        int newLevel = roleHead->getLevel() + 1;
        QWidget* levelWidget = nullptr;

        if (levelWidgets.size() <= newLevel) {
            levelWidget = new QWidget(ui.treeFrame);
            QVBoxLayout* mainLayout = qobject_cast<QVBoxLayout*>(ui.treeFrame->layout());
            QHBoxLayout* hLayout = new QHBoxLayout(levelWidget);
            levelWidget->setLayout(hLayout);

            mainLayout->addWidget(levelWidget);
            levelWidgets.push_back(levelWidget);
        }
        else {
            levelWidget = levelWidgets[newLevel];
        }

        Role* role = new Role(newLevel, name, position, color, levelWidget);
        roles.push_back(unique_ptr<Role>(role));

        roleHead->addSubordinate(role);

        QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(levelWidget->layout());
        layout->addWidget(role->getButton());

        connect(role, &Role::focusChanged, this, &QtTree::onButtonFocusChanged);

        ui.nameField->clear();
        ui.positionField->clear();
    }
    else {
        if (levelWidgets.empty()) {
            QWidget* levelWidget = new QWidget(ui.treeFrame);
            QVBoxLayout* mainLayout = new QVBoxLayout(ui.treeFrame);
            ui.treeFrame->setLayout(mainLayout);

            QHBoxLayout* hLayout = new QHBoxLayout(levelWidget);
            levelWidget->setLayout(hLayout);

            mainLayout->addWidget(levelWidget);
            levelWidgets.push_back(levelWidget);
        }

        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution<> dis(50, 200);
        int r = dis(gen);
        int g = dis(gen);
        int b = dis(gen);

        QColor color(r, g, b);

        Role* role = new Role(0, name, position, color, levelWidgets[0]);
        roles.push_back(unique_ptr<Role>(role));

        QHBoxLayout* layout = qobject_cast<QHBoxLayout*>(levelWidgets[0]->layout());
        layout->addWidget(role->getButton());

        connect(role, &Role::focusChanged, this, &QtTree::onButtonFocusChanged);

        ui.nameField->clear();
        ui.positionField->clear();

        
    }
    
}

void QtTree::onButtonFocusChanged(QPushButton* button) {
    if (button) {
        if (lastFocusedButton) {
            void* ptr = lastFocusedButton->property("rolePtr").value<void*>();
            Role* roleHead = static_cast<Role*>(ptr);
            QColor color = roleHead->getColor();

            const QString defaultStyle =
                "border: none; "
                "border-radius: 5px; "
                "color: white;"
                "background-color: " + color.name() + ";";

            lastFocusedButton->setStyleSheet(defaultStyle);
        }

        lastFocusedButton = button;
        void* ptr = lastFocusedButton->property("rolePtr").value<void*>();
        Role* roleHead = static_cast<Role*>(ptr);
        roleHead->printSubordinates();
        QColor color = roleHead->getColor();

        const QString focusedStyle =
            "border: 2px solid black; "
            "border-radius: 5px; "
            "color: white;"
            "background-color: " + color.name() + ";";

        lastFocusedButton->setStyleSheet(focusedStyle);
    }
}

QtTree::~QtTree() {
}
