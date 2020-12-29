#ifndef STATE_H
#define STATE_H

#include <memory>

struct DataWorkerComponent;

struct FullState {
    std::unique_ptr<DataWorkerComponent> dataWorkerComponent;
    int someValue = 0;
    FullState();
    void clearState() const;
};

extern unsigned int thread_local currentStateHandle;
FullState & getCurrentState();
void createNewState();
void deleteCurrentState();

#endif //STATE_H
