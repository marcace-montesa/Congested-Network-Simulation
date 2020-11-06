#include "Graph.h"
#include "Packet.h"
#include "Router.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//track packet loss between routers
/*void packet_loss(bool packet) 
{

}

void print_graph(vector<int> a, int b) 
{

} */


//set "flag toggle" to compare networks before and after network congestion
int main() 
{
  int node_number = 5;
  Graph G(node_number);
  G.add_edges(0,1);
  G.add_edges(0,2);
  G.add_edges(1,3);
  G.add_edges(2,3);
  G.add_edges(4,1);

  cout << "router 0 flag is " << G.getRouter(0).get_flag() << endl;

  srand(time(NULL));
  int src;
  int dest;
  int packets = 50;

  G.getRouter(0).register_observer(&G);
  G.getRouter(1).register_observer(&G);
  G.getRouter(2).register_observer(&G);
  G.getRouter(3).register_observer(&G);
  G.getRouter(4).register_observer(&G);

  G.getRouter(0).remove_observer(&G);
  G.getRouter(1).remove_observer(&G);
  G.getRouter(2).remove_observer(&G);
  G.getRouter(3).remove_observer(&G);
  G.getRouter(4).remove_observer(&G);

  cout << " random number of packets sent: " << packets << endl;

  Packet packet = Packet("header");
  
  for (int i = 0; i < 3; i++)
  {
    src = rand() % 5;
    dest = rand() % 5;
    cout << "random src: " << src << " random dest: " << dest << endl;
    bool packet_sent = G.packet_path(packet, src, dest, packets);
    cout << G.getRouter(dest).getPacketTotal() << endl;
  } 
  
  return 0;
}
