#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>

struct FullState;

struct WorkerComponent {
    int timesRun = 0;
    static void getWorkers(FullState &state);
    void work(FullState &state);
};

struct DataWorkerComponent {
    std::vector<WorkerComponent> workers;
    void clearState() {
        workers.clear();
    }
};

#endif //WORKER_H
