#ifndef API_H
#define API_H

#ifdef __cplusplus
extern "C" {
#endif

    typedef unsigned int State;
    State getNewState();
    void clearState(State s);
    void deleteState(State s);
    void runSimulation(State s);

#ifdef __cplusplus
};
#endif

#endif //API_H
