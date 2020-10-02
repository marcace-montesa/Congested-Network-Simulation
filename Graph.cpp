#include "Graph.h"

using namespace std;

Graph::Graph(int N)
{
  router_num = N;
    for(int i = 0; i < N; i++) 
   {
      Router router;
      line.push_back(router); //add Router to the graph
   }
   for(int i = 0; i < N; i++) 
   {
      for(int j = 0; j < N; j++) 
      {
        adjacency_matrix[i][j] = 0;
      }
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

int Graph::distance(int src, int dest)
{  
  int distance [router_num] = {};
  bool nodeVisited [router_num] = {false};
  vector <int> Q;
  int current_node = src;
  cout << current_node << endl;
  
    if(is_connected(src, dest) == true)  //check if they're neighbors
    {
      return 1;
    }
   
    else 
    {
      Q.push_back(src);
      nodeVisited[Q.front()] = true;

      while(!Q.empty())
      {
      int x = Q.front();
      cout << x << endl;
      Q.pop_back();
      for(int i = 0; i < line.size(); i++)
      {
        if(is_connected(x,i) == true && (!nodeVisited[i]))
        {
          distance[i] = distance[x] + 1;
          Q.push_back(i);
          nodeVisited[i] = true;
        }
      }
     }

    return distance[dest];

   }
}
