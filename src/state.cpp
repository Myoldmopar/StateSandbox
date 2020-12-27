#include "state.h"

#include <memory>
#include <worker.h>

FullState::FullState() {
    this->dataWorkerComponent = std::make_unique<DataWorkerComponent>();
}

void FullState::clearState() {
    this->dataWorkerComponent->clearState();
}
