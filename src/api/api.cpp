#include "api.h"
#include <state.h>
#include <manager.h>
#include <worker.h>  // needed to instantiate FullState

State getNewState() {
    FullState * s = new FullState;
    return s;
}

void clearState(State s) {
    FullState * sp = static_cast<FullState *>(s);
    sp->clearState();
}

void deleteState(State s) {
    FullState * sp = static_cast<FullState *>(s);
    delete sp;
}

void runSimulation(State s) {
    FullState * sp = static_cast<FullState *>(s);
    internalRunSimulation(*sp);
}
