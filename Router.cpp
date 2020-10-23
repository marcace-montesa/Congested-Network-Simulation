#include "Router.h"
#include "Packet.h"
#include <iostream>

using namespace std;

Router::Router() {};

bool Router::add_packet(Packet packet)
{
    //cout << "Entered add_packet function" << endl;
    //cout << "buffer queue size " << packet_queue.size() << endl;
    if(packet_queue.size() < 5) //check the size of the queue to see if we can add packets or not
    {
       packet_queue.push(packet);
       //cout << "buffer queue size after packet added " << packet_queue.size() << endl;
       //cout << "pushed packet to queue" << endl;
       return true;
    }
    return false;
}

int Router::getPacketTotal()
{
    return packet_queue.size();
}

void Router::remove_packet()
{
    packet_queue.pop();
}

Packet Router::getPacket()
{
    return packet_queue.front();
}
void Router::print_queue()
{
    while(!packet_queue.empty())
    {
      cout << packet_queue.front().getHeader() << " ";
      packet_queue.pop();
    }
    cout << "*" << endl;
} 
