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