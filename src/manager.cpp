#include "manager.h"
#include <state.h>
#include <worker.h>

int internalRunSimulation(FullState &state) {
    WorkerComponent::getWorkers(state);  // calling static worker function with current state
    for (int i = 1; i <= 3; i++) {
        for (auto &w : state.dataWorkerComponent->workers) {  // looping over instances and doing stuff
            w.work(state);
        }
    }
    return 0;
}
