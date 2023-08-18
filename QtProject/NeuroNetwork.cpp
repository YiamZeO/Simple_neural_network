#include "NeuroNetwork.h"

NeuroNetwork::NeuroNetwork()
{
    neurons = std::vector<SelectionNeuron>(2, SelectionNeuron());
    inputParameter = 20;
}
