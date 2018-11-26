#include "threadmae.h"
#include <QDebug>

ThreadMae::ThreadMae(QObject * parent) {
}

void ThreadMae::run() {
    while(isRunning()) {
        mae.activer();
        qDebug() << mae.getEtatPresent();
    }
}
