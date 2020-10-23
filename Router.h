#include "Packet.h"
#include <queue>
using namespace std;

#ifndef Router_H
#define Router_H

class Router
{
    //other public methods that are missing in UML will be in graph class
    public:
        //adds packet to buffer queue
        bool add_packet(Packet packet);
        void remove_packet();
        Router();
        Packet getPacket(); //gets packet at front of queue
        int getPacketTotal(); //returns number of packets in queue
        void print_queue();

    private:
        queue<Packet> packet_queue;
        bool queue_full;
        bool isActive;
};

#endif
