#include "Packet.h"
#include <queue>
#include <list>
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
        void set_flag(bool buffer_flag);
        bool get_flag();
        int getID();
        void setID(int ID);
        bool getPacketsReduced();
        void setPacketsReduced(bool packets_reduced);
        
    private:
        queue<Packet> packet_queue;
        bool queue_full;
        bool isActive;
        bool buffer_flag;
        int ID;
        bool packets_reduced;
};

#endif
