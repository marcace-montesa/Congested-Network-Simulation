#include "Router.h"
#include "Packet.h"
#include <iostream>

using namespace std;

Router::Router() {};

void Router::add_packet(Packet packet)
{
    queue.push(packet);
}

void Router::remove_packet()
{
    queue.pop();
}


Packet Router::getPacket()
{
    return queue.front();
}

