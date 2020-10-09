#include "Graph.h"
#include <queue>

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

void Graph::send_packet(Packet packet, int src, int dest)
{
  //simultes packet traversal betwwen two routers
  line[src].add_packet(packet);
  line[dest].add_packet(packet);
  line[src].remove_packet();
}

void Graph::packet_path(Packet packet, int src, int dest) 
{
  //  line[i].add_packet(packet); //send the packet from the router
    
    int distance [NODES] = {};
    bool nodeVisited [NODES] = {false};
    queue <int> Q;
    int current_node = src;
    int path[] = {}; // might need to add nodes 
      
        Q.push(src);
        nodeVisited[Q.front()] = true;

        while(!Q.empty())
        {
        int x = Q.front();
        cout << x << endl;
        Q.pop();
        for(int i = 0; i < line.size(); i++)
        {
          if (is_connected(x,i) == true && (!nodeVisited[i]))
          {
            distance[i] = distance[x] + 1;
            Q.push(i);
            nodeVisited[i] = true;
          }
        }
       }

      path[0] = src;

      for(int i = 1; i < line.size(); i++)
      {
        for(int j = 0; j < line.size(); j++)
        {
          if(distance[j] == i)
            path[i] = j;
        }
      }

      for (int j = 0; j < line.size(); j++)
      {
        int src = path[j];
        int dest = path[j+1];

        send_packet(packet, src, dest);
      }

      /*for(int i = 0; i < (sizeof(path)/sizeof(path[0])); i++)
      {
        cout << path[i] << endl;
      }*/
}

Router Graph::getRouter(int router)
{
  return line[router];
}



int Graph::distance(int src, int dest)
{  
  int distance [NODES] = {};
  bool nodeVisited [NODES] = {false};
  queue <int> Q;
  int current_node = src;

  cout << current_node << endl;

    if(is_connected(src, dest) == true)  //check if they're neighbors
    {
      return 1;
    }
   
    else 
    {
      Q.push(src);
      nodeVisited[Q.front()] = true;

      while(!Q.empty())
      {
      int x = Q.front();
      cout << x << endl;
      Q.pop();
      for(int i = 0; i < line.size(); i++)
      {
        if (is_connected(x, i) == true && (!nodeVisited[i]))
        {
          distance[i] = distance[x] + 1;
          Q.push(i);
          nodeVisited[i] = true;
        }
      }
     }

    return distance[dest];

   }
}
