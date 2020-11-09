#include "Packet.h"
#include <string>

//implementations
Packet::Packet(string header)
{
    this -> setHeader(header);
}

Packet::Packet() {}

void Packet::setHeader(string header)
{
    this -> Header = header;
}

string Packet::getHeader()
{
    return this -> Header;
}

void Packet::setDestination(int dest) 
{
  this->destination = dest;
}

int Packet::getDestination() 
{
   return destination;
}

void Packet::setSource(int src) 
{
   this->source = src;
}
        
int Packet::getSource() 
{
  return source;
}
