#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph(int N)
{
   router_num = N;
   for(int i = 0; i < N; i++) 
   {
     line.push_back(Router); //add Router to the graph
   }
}

void Graph::add_edges(int i, int j) 
{
   adjacency_matrix[i][j] = 1; //connecting the edges
   adjacency_matrix[j][i] = 1; //connecting the edges
} 
        
bool Graph::is_connected(int i, int j) 
{
  if(adjacency_matrix[i][j] == 1 && adjacency_matrix[j][i] == 1) 
  {
    return true; //to see if the adjacency matrix is connected
  }
  else
  {
    return false; //to see if the adjacency matrix is connected
  }
}

void Graph::send_packet(Packet packet, int i) 
{
   line[i].add_packet(packet); //send the packet from the router
   //Need to traverse the graph
}

int Graph::distance(int i, int j)
{  

   if(is_connected(i, j) == true)  //check if they're neighbors
   {
     return 1;
   }
   
   else {
     //traverse it
   }
   
}