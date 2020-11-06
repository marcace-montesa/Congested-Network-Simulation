#include "Packet.h"
#include "Subject.h"
#include <queue>
#include <list>
using namespace std;

#ifndef Router_H
#define Router_H

class Router: public Subject
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
        void register_observer(Observer *o) override;
        void remove_observer(Observer *o) override;
        void notify_observer() override;
        void set_flag(bool buffer_flag);
        bool get_flag();

    private:
        queue<Packet> packet_queue;
        bool queue_full;
        bool isActive;
        bool buffer_flag;
        list<Observer *> Observer_list;
};

#endif
