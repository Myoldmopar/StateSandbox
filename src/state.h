#ifndef STATE_H
#define STATE_H

#include <memory>

struct DataWorkerComponent;

struct FullState {
    std::unique_ptr<DataWorkerComponent> dataWorkerComponent;
    int someValue = 0;
    FullState();
    void clearState();
};

#endif //STATE_H
