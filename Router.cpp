#include "Router.h"
#include "Packet.h"
#include <iostream>

using namespace std;

Router::Router() {};

bool Router::add_packet(Packet packet)
{
    if(queue.size() <= 4) //check the size of the queue to see if we can add packets or not
    {
       queue.push(packet);
       return true;
    }
    else {
    	return false;
    }
}

void Router::remove_packet()
{
    queue.pop();
}

Packet Router::getPacket()
{
    return queue.front();
}

