#include "Router.h"
#include "Packet.h"
#include <iostream>

using namespace std;

Router::Router() {};

bool Router::add_packet(Packet packet)
{
    //cout << "Entered add_packet function" << endl;
    if(queue.size() <= 4) //check the size of the queue to see if we can add packets or not
    {
       //cout << "entered if statement" << endl;
       queue.push(packet);
       //cout << "pushed packet to queue" << endl;
       return true;
    }
    else {
    	return false;
    }
}

int Router::getPacketTotal()
{
    return queue.size();
}

void Router::remove_packet()
{
    queue.pop();
}

Packet Router::getPacket()
{
    return queue.front();
}

