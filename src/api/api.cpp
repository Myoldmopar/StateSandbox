#include "api.h"
#include <state.h>
#include <manager.h>
#include <worker.h>  // needed to instantiate FullState

State getNewState() {
    createNewState();
    return currentStateHandle;
}

void clearState(State s) {
    currentStateHandle = s;
    FullState & sp = getCurrentState();
    sp.clearState();
}

void deleteState(State s) {
    currentStateHandle = s;
    deleteCurrentState();
}

void runSimulation(State s) {
    currentStateHandle = s;
    internalRunSimulation();
}
