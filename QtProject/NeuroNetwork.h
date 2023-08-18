#ifndef NEURONETWORK_H
#define NEURONETWORK_H

#include <vector>

class SelectionNeuron
{
public:
    std::vector<double> weights;

    SelectionNeuron() = default;
    ~SelectionNeuron() = default;
};

class NeuroNetwork
{
public:
    int inputParameter;
    std::vector<SelectionNeuron> neurons;

    NeuroNetwork();
    ~NeuroNetwork() = default;
};

#endif // NEURONETWORK_H
