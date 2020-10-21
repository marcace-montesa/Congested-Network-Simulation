#include "Graph.h"
#include <queue>
#include <stdio.h>
#include <vector>

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

bool Graph::send_packet(Packet packet, int src, int dest)
{
  //cout << "Entered send_packet function" << endl;
  //simultes packet traversal betwwen two routers
  bool src_packetadded = line[src].add_packet(packet);
  if(src_packetadded == false) 
  {  //is possible to get stuck on this loop if the space in the buffer is not free
     return false;
  }
  bool dest_packetadded = line[dest].add_packet(packet);
  if(dest_packetadded == false) 
  {
     return false;
  }
  line[src].remove_packet();
  //cout << "removing packet" << endl;
  return true;
}

bool Graph::packet_path(Packet packet, int src, int dest) 
{
    //line[i].add_packet(packet); //send the packet from the router
    
    //cout << "Entered packet_path function" << endl;

    int distance [NODES] = {};
    bool nodeVisited [NODES] = {false};
    queue <int> Q;
    int current_node = src;
    vector <int> path; 
      
        Q.push(src);
        nodeVisited[Q.front()] = true;

        while(!Q.empty())
        {
        int x = Q.front();
        //cout << x << endl;
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

      path.push_back(src);

      for(int i = 1; i < line.size(); i++)
      {
        for(int j = 0; j < line.size(); j++)
        {
          if((distance[j] == i) && (path.size() == i))
          {
            path.push_back(j);
          }
        } 
      }

      /*for (int i = 0; i < path.size(); i++)
      {
        cout << path[i] << endl;
      }
      */
      int path_len = path.size();

      //cout << "path length is: " << path_len << endl;

      for (int j = 0; j < (path_len-1); j++)
      {
        int new_src = path[j];
        int new_dest = path[j+1];
        int track = 0;
        bool packet_sent = send_packet(packet, src, dest);
        //cout << packet_sent << endl;
        while((packet_sent == false) && track < 3)
        {
           track++;
           packet_sent = send_packet(packet, src, dest);
        }

        if (track == 2)
        {
          cout << "Packet traversal failed between routers " << j << " and " << j+1 << 
          " (packet was dropped 3 times)" << endl;
          return false;
        }
        
      }
      //cout << "returning from packet_path" << endl;
      return true;
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

  //cout << current_node << endl;

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
