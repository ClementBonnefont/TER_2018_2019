#include "threadmae.h"

ThreadMae::ThreadMae(MachineAEtat* mae) {
    this->mae = mae;
}

void ThreadMae::run() {
    while(isRunning()) {
        mae->activer();
    }
}
