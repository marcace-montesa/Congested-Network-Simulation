#include <string>
using namespace std;

#ifndef Packet_H
#define Packet_H

//packets are stored in the buffer queue of routers
class Packet
{
    public:

        //returns the header of the packet
        string getHeader();

        //sets packet header
        void setHeader(string header);

        //packet constructor
        Packet(string header);
        Packet();

    private:

        //Header
        string Header;

};

#endif