#include "networkplaying.h"
#include <fstream>

NetworkPlaying::NetworkPlaying(std::string fName)
{
    std::fstream inData(fName, std::ios_base::in);
    if(inData.is_open())
    {
        std::string s;
        std::getline(inData, s);
        std::getline(inData, s);
        net.inputParameter = std::stoi(s);
        std::getline(inData, s);
        std::getline(inData, s);
        int neuronsCount = std::stoi(s);
        std::getline(inData, s);
        std::vector<SelectionNeuron> neurons;
        for(int i = 0; i < neuronsCount; i++)
        {
            neurons.push_back(SelectionNeuron());
            std::getline(inData, s);
            int end = 0;
            int beg;
            for(int j = 0; j < net.inputParameter-1; j++)
            {
                beg = end;
                end = s.find(" ", beg+1);
                neurons.back().weights.push_back(std::stod(s.substr(beg, end-beg)));
            }
            neurons.back().weights.push_back(std::stod(s.substr(end+1, s.size()-end-1)));
        }
        net.neurons = neurons;
        inData.close();
    }
}

int NetworkPlaying::netChose(int sticks)
{
    if(sticks > 1)
    {
        int par = net.inputParameter;
        while(sticks%par != 0)
            par--;
        int whatNeuron;
        std::pair<int, int> firstNeuronWeight(0, (int)(net.neurons[0].weights[par-1]*100));
        int whatWeight = rand()%100;
        if(whatWeight >= firstNeuronWeight.first && whatWeight <= firstNeuronWeight.second)
            whatNeuron = 0;
        else
            whatNeuron = 1;
        return whatNeuron == 0 ? 1 : 2;
    }
    else
        return 0;
}
