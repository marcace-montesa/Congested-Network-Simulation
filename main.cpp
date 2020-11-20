#include "Graph.h"
#include "Packet.h"
#include "Router.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main() 
{
  int node_number = 5;
  Graph G(node_number);
  G.add_edges(0,1);
  G.add_edges(0,2);
  G.add_edges(1,3);
  G.add_edges(2,3);
  G.add_edges(4,1);

  srand(time(NULL));
  int src;
  int dest;
  int packets = 50;
  
  cout << "number of packets sent: " << packets << endl;

  Packet packet = Packet("header");
  
  for (int i = 0; i < 3; i++)
  {
    src = rand() % 5;
    dest = rand() % 5;
    packet.setDestination(dest);
    packet.setSource(src);
    cout << "random src: " << src << " random dest: " << dest << endl;
    bool packet_sent = G.packet_path(packet, src, dest, packets);
    cout << G.getRouter(dest).getPacketTotal() << endl;
  } 
  
  return 0;
}
