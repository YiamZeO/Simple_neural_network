#ifndef NETWORKPLAYING_H
#define NETWORKPLAYING_H

#include <string>
#include "NeuroNetwork.h"

class NetworkPlaying
{
    NeuroNetwork net;
    std::string neuroData;
public:
    NetworkPlaying(std::string fName);
    int netChose(int sticks);
};

#endif // NETWORKPLAYING_H
