#include "networktraining.h"
#include <QThread>
#include <ctime>
#include <fstream>

void NetworkTraining::loadData(std::vector<std::string> fNames)
{
    inFile = fNames;
    allMatches = 1;
    winMatches = 0;
    std::fstream inData(inFile[0], std::ios_base::in);
    if(inData.is_open())
    {
        network.push_back(NeuroNetwork());
        std::string s;
        std::getline(inData, s);
        std::getline(inData, s);
        network[0].inputParameter = std::stoi(s);
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
            for(int j = 0; j < network[0].inputParameter-1; j++)
            {
                beg = end;
                end = s.find(" ", beg+1);
                neurons.back().weights.push_back(std::stod(s.substr(beg, end-beg)));
            }
            neurons.back().weights.push_back(std::stod(s.substr(end+1, s.size()-end-1)));
        }
        network[0].neurons = neurons;
        inData.close();
    }
    inData.open(inFile[1], std::ios_base::in);
    if(inData.is_open())
    {
        network.push_back(NeuroNetwork());
        std::string s;
        std::getline(inData, s);
        std::getline(inData, s);
        network[1].inputParameter = std::stoi(s);
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
            for(int j = 0; j < network[1].inputParameter-1; j++)
            {
                beg = end;
                end = s.find(" ", beg+1);
                neurons.back().weights.push_back(std::stod(s.substr(beg, end-beg)));
            }
            neurons.back().weights.push_back(std::stod(s.substr(end+1, s.size()-end-1)));
        }
        network[1].neurons = neurons;
        inData.close();
    }
}

std::vector<int> NetworkTraining::getStats()
{
    std::vector<int> res;
    res.push_back(winMatches);
    res.push_back(allMatches);
    return res;
}

void NetworkTraining::unloadData()
{
    std::fstream outFile(inFile[0], std::ios_base::out);
    if(outFile.is_open())
    {
        outFile << "InputParameters" << std::endl << std::to_string(network[0].inputParameter) << std::endl;
        outFile << "Neurons" << std::endl << std::to_string(network[0].neurons.size()) << std::endl;
        outFile << "Weights" << std::endl;
        for(unsigned long long i = 0; i < network[0].neurons.size(); i++)
        {
            std::string check = std::to_string(network[0].neurons[i].weights[0]);
            outFile << std::to_string(network[0].neurons[i].weights[0]);
            for(int j = 1; j < 20; j++)
            {
                outFile << " " << std::to_string(network[0].neurons[i].weights[j]);
            }
            outFile << std::endl;
        }
        outFile.close();
    }
}

bool NetworkTraining::playMatch(NeuroNetwork *currentNet, NeuroNetwork opponentNet)
{
    int countSticks = 20;
    bool whoPlay = (rand()%100) < 50 ? false : true;
    std::vector<std::pair<int, int>>parametrList;
    while(countSticks > 1)
    {
        if(whoPlay)
        {
            int par = opponentNet.inputParameter;
            while(countSticks%par != 0)
                par--;
            int whatNeuron;
            std::pair<int, int> firstNeuronWeight(0, (int)(opponentNet.neurons[0].weights[par-1]*100));
            int whatWeight = rand()%100;
            if(whatWeight >= firstNeuronWeight.first && whatWeight <= firstNeuronWeight.second)
                whatNeuron = 0;
            else
                whatNeuron = 1;
            if(whatNeuron)
                countSticks -= 2;
            else
                countSticks--;
        }
        else
        {
            int par = currentNet->inputParameter;
            while(countSticks%par != 0)
                par--;
            int whatNeuron;
            std::pair<int, int> firstNeuronWeight(0, (int)(currentNet->neurons[0].weights[par-1]*100));
            int whatWeight = rand()%100;
            if(whatWeight >= firstNeuronWeight.first && whatWeight <= firstNeuronWeight.second)
                whatNeuron = 0;
            else
                whatNeuron = 1;
            if(whatNeuron)
                countSticks -= 2;
            else
                countSticks--;
            parametrList.push_back(std::pair<int, int>(par, whatNeuron));
        }
        whoPlay = !whoPlay;
    }
    if(countSticks == 1)
        whoPlay = !whoPlay;
    for(auto it : parametrList)
    {
        if(whoPlay)
            currentNet->neurons[it.second].weights[it.first-1] += (1-currentNet->neurons[it.second].weights[it.first-1])/2;
        else
            currentNet->neurons[it.second].weights[it.first-1] /= 2;
        currentNet->neurons[it.second == 0 ? 1 : 0].weights[it.first-1] = 1-currentNet->neurons[it.second].weights[it.first-1];
    }
    return whoPlay;
}

void NetworkTraining::training(bool *trainingFlag)
{
    srand(time(0));
    allMatches = 1;
    winMatches = 0;
    while(*trainingFlag)
    {
        if(playMatch(&(network[0]), network[1]))
        {
            winMatches++;
        }
        allMatches++;
    }
}
