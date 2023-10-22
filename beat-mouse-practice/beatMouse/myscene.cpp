#include "myscene.h"
#include <stdlib.h>

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    int i = 0;
    for (i = 0; i < 16; i++) {
        this->item[i] = new myItem;
        int w = this->item[i]->boundingRect().width();
        int h = this->item[i]->boundingRect().height();
        this->item[i]->setPos(i / 4 * w, i % 4 * h);
        this->addItem(item[i]);
    }
    this->ptimer = new QTimer;
    connect(this->ptimer, SIGNAL(timeout()), this, SLOT(showMouse()));
}

void myScene::showMouse() {
    int count = rand() % 3 + 1;
    int i = 0;

    for (i = 0; i < 16; i++) {
        this->item[i]->setPic(":/bg/pic/bg.jpg");
        this->item[i]->setMouse(false);
    }
    for (i = 0; i < count; i++) {
        int index = rand() % 16;
        this->item[index]->setPic(":/bg/pic/bg1.jpg");
        this->item[index]->setMouse(true);
    }
}

void myScene::startGame() {
    int i = 0;
    for (i = 0; i < 16; i++) {
        this->item[i]->setStart(true);
    }
    this->ptimer->start(800);
}

void myScene::pauseGame() {
    int i = 0;
    for (i = 0; i < 16; i++) {
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
}

void myScene::stopGame() {
    int i = 0;
    for (i = 0; i < 16; i++) {
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();

    for (i = 0; i < 16; i++) {
        this->item[i]->setPic(":/bg/pic/bg.jpg");
        this->item[i]->setMouse(false);
    }
}
