#include "Graph.h"
#include "Packet.h"
#include "Router.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

//track packet loss between routers
/*void packet_loss(bool packet) 
{

}

void print_graph(vector<int> a, int b) 
{

} */

int main() 
{
  int node_number = 5;
  Graph G(node_number);
  G.add_edges(0,1);
  G.add_edges(0,2);
  G.add_edges(1,3);
  G.add_edges(2,3);
  G.add_edges(4,1);
  //int distance = G.distance(3, 4); 
  //cout << "distance is " << distance << endl;

  /*Packet packet = Packet("header");
  bool packet_sent = G.packet_path(packet, 2, 4);
  cout << packet_sent << endl;
  cout << G.getRouter(4).getPacket().getHeader() << endl;
  bool packet_sent1 = G.packet_path(packet, 0, 3);
  cout << packet_sent1 << endl;
  cout << G.getRouter(3).getPacket().getHeader() << endl;
  bool packet_sent4 = G.packet_path(packet, 3, 0);
  cout << packet_sent4 << endl;
  cout << G.getRouter(0).getPacket().getHeader() << endl;
  bool packet_sent3 = G.packet_path(packet, 4, 2);
  cout << packet_sent3 << endl;
  cout << G.getRouter(2).getPacket().getHeader() << endl;

  bool packet_sent5 = G.packet_path(packet, 0, 1);
  cout << packet_sent5 << endl;
  cout << G.getRouter(1).getPacket().getHeader() << endl;*/

  Packet packet = Packet("header2");
  bool packet_sent1 = G.packet_path(packet, 2, 4);
  bool packet_sent2 = G.packet_path(packet, 2, 4);
  bool packet_sent3 = G.packet_path(packet, 2, 4);
  bool packet_sent4 = G.packet_path(packet, 2, 4);
  bool packet_sent5 = G.packet_path(packet, 2, 4);
  bool packet_sent6 = G.packet_path(packet, 2, 4);
  bool packet_sent7 = G.packet_path(packet, 2, 4);
  bool packet_sent8 = G.packet_path(packet, 2, 4);
  bool packet_sent9 = G.packet_path(packet, 2, 4);
  cout << "packet1 " << packet_sent1 << endl;
  cout << "packet6 " << packet_sent6 << endl;
  cout << "packet7 " << packet_sent7 << endl;
  cout << "packet8 " << packet_sent8 << endl;
  for(int i = 0; i < G.getRouter(4).getPacketTotal(); i++) 
  {
  	cout << G.getRouter(4).getPacket().getHeader() << endl;
  }
  //cout << G.getRouter(1).getPacket().getHeader() << endl;
  

  cout << G.getRouter(4).getPacketTotal() << endl;
  
  return 0;
}
