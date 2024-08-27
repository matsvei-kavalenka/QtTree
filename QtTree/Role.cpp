#include "Role.h"

int Role::idCounter = 0;

Role::Role(int level, QString name, QString position, QColor color, QWidget* parent): id(idCounter++), level(level), name(name.toStdString()), position(position.toStdString()), color(color) {
    const QString defaultStyle =
        "border: none; "
        "border-radius: 5px; "
        "color: white;"
        "background-color: " + color.name() + ";";

    roleButton = new QPushButton(name, parent);
    roleButton->setFixedSize(80, 25);
    roleButton->setObjectName("roleField");
    roleButton->setProperty("rolePtr", QVariant::fromValue(static_cast<void*>(this)));
    roleButton->setStyleSheet(defaultStyle);

    roleButton->installEventFilter(this);
}

bool Role::eventFilter(QObject* watched, QEvent* event) {
    if (event->type() == QEvent::FocusIn) {
        QPushButton* button = qobject_cast<QPushButton*>(watched);
        if (button) {
            emit focusChanged(button);
        }
    }
    return QObject::eventFilter(watched, event);
}

void Role::addSubordinate(Role* person) {
    if (person) {
        qDebug() << "Adding" << QString::fromStdString(person->name) << "as a subordinate of" << QString::fromStdString(this->name);
        subordinates.push_back(person);
    }
}

void Role::printSubordinates() {
    for (const Role* person : subordinates) {
        qDebug() << QString::fromStdString(person->name);
    }
}
