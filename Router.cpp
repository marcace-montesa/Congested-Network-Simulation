#include "Router.h"
#include "Packet.h"
#include <iostream>
#include <list>
using namespace std;

Router::Router() {};

bool Router::add_packet(Packet packet)
{
    //cout << "Entered add_packet function" << endl;
    //cout << "buffer queue size " << packet_queue.size() << endl;
    if(packet_queue.size() < 7) //check the size of the queue to see if we can add packets or not
    {
       packet_queue.push(packet);
       //cout << "buffer queue size after packet added " << packet_queue.size() << endl;
       //cout << "pushed packet to queue" << endl;
       return true;
    }

    else if(packet_queue.size() >= 7 && packet_queue.size() < 10)
    {
        //set flag
    }

    //flag to signify queue is full, clear buffer queue
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

void Router::register_observer(Observer *o) 
{
   Observer_list.push_back(o);
}

void Router::remove_observer(Observer *o) 
{
   Observer_list.remove(o);
}

void Router::notify_observer(bool buffer_flag)
{
   list<Observer *>::iterator iterator = Observer_list.begin();
   while (iterator != Observer_list.end())
   {
      (*iterator)->Update(get_flag());
      iterator++;
   }
}

void Router::set_flag(bool buffer_flag) 
{
   this -> buffer_flag = buffer_flag;
}

bool Router::get_flag()
{
   return this -> buffer_flag;
}
