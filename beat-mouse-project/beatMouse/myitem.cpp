#include "myitem.h"
#include <QPixmap>
#include <QDebug>
#include <handler.h>
#include <QCursor>

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/pic/bg.jpg"));
    this->start = false;
    this->mouse = false;
    this->setCursor(QCursor(QPixmap(":/mouse/pic/up.jpg")));
}

void myItem::setPic(QString path) {
    this->setPixmap(QPixmap(path));
}


void myItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->setCursor(QCursor(QPixmap(":/mouse/pic/down.jpg")));
    if (this->isStart()) {
        handler *hand = handler::getInstance();
        if (this->isMouse()) {
            hand->addScore();
            this->setCursor(QCursor(QPixmap(":/mouse/pic/beat.jpg")));
            this->mouse = false;
        }
    }
}

void myItem::mouseRealeaseEvent(QGraphicsSceneMoveEvent *event) {
    this->setCursor(QCursor(QPixmap(":/mouse/pic/up.jpg")));
}

void myItem::setMouse(bool mouse) {
    this->mouse = mouse;
}

bool myItem::isMouse() {
    return this->mouse;
}

void myItem::setStart(bool start) {
    this->start = start;
}

bool myItem::isStart() {
    return this->start;
}
