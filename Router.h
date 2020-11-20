#include "Packet.h"
#include <queue>
#include <list>
using namespace std;

#ifndef Router_H
#define Router_H

class Router
{
    public:
        bool add_packet(Packet packet); //adds packet to buffer queue
        void remove_packet(); //removes packet from buffer queue
        Router(); 
        Packet getPacket(); //gets packet at front of queue
        int getPacketTotal(); //returns number of packets in queue
        void print_queue(); //shows whats in the queue (for debugging)
        void set_flag(bool buffer_flag);
        bool get_flag(); //returns the flag
        int getID(); //returns each routers unique id
        void setID(int ID); //sets each routers id
        void depop(); //depopulates the buffer queue, resets flag
        
    private:
        queue<Packet> packet_queue; 
        bool buffer_flag; //flag that signals if the router is getting full
        int ID;
};

#endif
