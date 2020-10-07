#include "Packet.h"
#include <vector>
using namespace std;

#ifndef Router_H
#define Router_H

class Router
{
    //other public methods that are missing in UML will be in graph class
    public:
        //adds packet to buffer queue
        void add_packet(Packet packet);
        Router();
        Packet getPacket();

    private:
        vector<Packet> queue;
        bool queue_full;
        bool isActive;
};

#endif