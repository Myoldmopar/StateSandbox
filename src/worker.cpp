#include <iostream>

#include "worker.h"
#include "state.h"

void WorkerComponent::getWorkers(FullState &state) {
    state.dataWorkerComponent->workers.emplace_back();  // static function fills out current state
}

void WorkerComponent::work(FullState &state) {
    this->timesRun++;  // something on the local instance
    std::cout << "Worker has run " << this->timesRun << " times!\n";
    state.someValue++;  // something on the current state
}

