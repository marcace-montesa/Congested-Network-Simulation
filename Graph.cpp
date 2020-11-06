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
        line[i].set_flag(0); //sets the buffer flags
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
  
  if(line[src].getPacketTotal() == 0)
  {
    bool src_packetadded = line[src].add_packet(packet);
    //cout << "src " << src_packetadded << endl;
    if(src_packetadded == false) 
    {  //is possible to get stuck on this loop if the space in the buffer is not free
      return false;
    }
  }
  bool dest_packetadded = line[dest].add_packet(packet);
  //cout << "dest " << dest_packetadded << endl;
  if(dest_packetadded == false) 
  {
     return false;
  }
  line[src].remove_packet();
  //cout << "removing packet" << endl;
  return true;
}

bool Graph::packet_path(Packet packet, int src, int dest, int packets) 
{   
    //cout << "Entered packet_path function" << endl
    int distance [NODES] = {};
    bool nodeVisited [NODES] = {false};
    queue <int> Q;
    int current_node = src;
    vector <int> path; 

    if(src == dest)
    {
      cout << "no path to traverse" << endl;
      return 1;
    }

    else if(is_connected(src, dest) == true)  //check if they're neighbors
    {
      distance[dest] = 1; 
    }

    else {  
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
      }
      
      //cout << "distance array:";

      /*for (int i = 0; i < NODES; i++)
      {
        cout << " " << distance[i] << " ";
      }*/

      //cout << endl;

      path.push_back(src);

      //cout << "line size is " << line.size() << endl;

      for(int i = 1; i < line.size(); i++) //iterating through distances
      {
        for(int j = 0; j < line.size(); j++) //iterating through routers
        {
          if((distance[j] == i) && (path.size() == i) && distance[dest] != i)
          {
            path.push_back(j);
          }
        } 
      }

      path.push_back(dest);

      /*for (int i = 0; i < path.size(); i++)
      {
        cout << path[i] << endl;
      }*/
      
      int path_len = path.size();

      //cout << "path length is: " << path_len << endl;

      for (int j = 0; j < (path_len - 1); j++)
      {
        int new_src = path[j];
        int new_dest = path[j+1];
        int track = 0;
        bool packets_reduced = 0;

        if ((line[new_dest].get_flag() == 1) && (packets_reduced == 0)) 
          {
            packets = packets/2;
            packets_reduced = 1;
            cout << "reduced packets send by half" << endl;
          }
        
        for (int i = 0; i < packets; i++)
        {   
          cout << "current flag value: " << line[new_dest].get_flag() << endl;
          if ((line[new_dest].get_flag() == 1) && (packets_reduced == 0)) 
          {
            packets = packets/2;
            packets_reduced = 1;
            cout << "reduced packets send by half" << endl;
          }
          
          bool packet_sent = send_packet(packet, new_src, new_dest);
          cout << "packet sent value " << packet_sent << endl;
          cout << "current dest: " << new_dest << endl;
          while((packet_sent == false) && track < 3)
          {
            track++;
            packet_sent = send_packet(packet, src, dest);
          }

          if (track >= 2)
          {
            cout << "Packet traversal failed between routers " << path[j] << " and " << path[j+1] << 
            " (packet was dropped 3 times)" << endl;
            return false;
          }
        }

        //if flag value gets modified, cut packets in half
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
      //cout << x << endl;
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

int Graph::get_router_num()
{
    return this -> router_num;
}

void Graph::Update(bool buffer_flag) 
{
    this -> buffer_flag = buffer_flag;
}
