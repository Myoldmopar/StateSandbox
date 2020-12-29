#include "state.h"

#include <cassert>
#include <iostream>
#include <memory>
#include <worker.h>

FullState::FullState() {
    this->dataWorkerComponent = std::make_unique<DataWorkerComponent>();
}

void FullState::clearState() const {
    this->dataWorkerComponent->clearState();
}

std::vector<FullState *> stateVector;

unsigned int thread_local currentStateHandle = -1;

void createNewState() {
    stateVector.push_back(new FullState);
    currentStateHandle = size(stateVector) - 1;
    std::cout << "New state created at index: " << currentStateHandle << std::endl;
}

FullState & getCurrentState() {
    assert(currentStateHandle < size(stateVector));
    return *stateVector[currentStateHandle];
}

void deleteCurrentState() {
    delete stateVector[currentStateHandle];
}
