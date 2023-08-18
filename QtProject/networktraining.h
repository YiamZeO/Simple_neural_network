#ifndef NETWORKTRAINING_H
#define NETWORKTRAINING_H

#include "NeuroNetwork.h"
#include <string>
#include <utility>

class NetworkTraining
{
public:
    NetworkTraining() = default;
    ~NetworkTraining() = default;
    void loadData(std::vector<std::string> fNames);
    std::vector<int> getStats();
    void unloadData();
    bool playMatch(NeuroNetwork *currentNet, NeuroNetwork opponentNet);
    void training(bool *trainingFlag);
private:
    std::vector<NeuroNetwork> network;
    std::vector<std::string> inFile;
    int allMatches = 1;
    int winMatches = 0;
};

#endif // NETWORKTRAINING_H
