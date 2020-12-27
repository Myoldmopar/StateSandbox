#include <api/api.h>

int main() {
    State s = getNewState();
    runSimulation(s);
    clearState(s);
    runSimulation(s);
    deleteState(s);
    return 0;
}
