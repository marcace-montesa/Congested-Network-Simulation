#include "Graph.h"
#include "Packet.h"
#include "Router.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

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
  //G.add_edges(3,4);
  int distance = G.distance(3,4);
  cout << distance << endl;
  return 0;
}
