#include <string>
#include <vector>
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
        void setDestination(int dest);
        int getDestination();
        void setSource(int src);
        int getSource();
        
    private:

        //Header
        string Header;
        int destination;
        int source;

};

#endif
