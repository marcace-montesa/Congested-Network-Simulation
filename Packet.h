#include <string>
#include <vector>
using namespace std;

#ifndef Packet_H
#define Packet_H

//packets are stored in the buffer queue of routers
class Packet
{
    public:
        string getHeader(); //returns the header of the packet
        void setHeader(string header); //sets packet header
        Packet(string header);
        Packet();
        void setDestination(int dest); //sets the final destination
        int getDestination(); //returns the final destination
        void setSource(int src); //sets the initial source
        int getSource(); //returns the initial source
        
    private:
        string Header; 
        int destination;
        int source;
};

#endif