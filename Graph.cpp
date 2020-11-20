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
    line[i].setID(i);
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
  //simultes packet traversal betwwen two connected routers
  
  if(line[src].getPacketTotal() == 0)
  {
    bool src_packetadded = line[src].add_packet(packet);
    if(src_packetadded == false) 
    {  
      return false;
    }
  }
  bool dest_packetadded = line[dest].add_packet(packet);
  if(dest_packetadded == false) 
  {
    return false;
  }
  line[src].remove_packet();
  return true;
}

bool Graph::packet_path(Packet packet, int src, int dest, int packets) 
{   
  int distance [NODES] = {};
  bool nodeVisited [NODES] = {false};
  queue <int> Q;
  int current_node = src;
  vector <int> path; 
  int total_packet = packets;
  
  if(src == dest)
  {
    cout << "no path to traverse" << endl;
    return 1;
  }

  else if(is_connected(src, dest) == true)  //check if they're neighbors
  {
    distance[dest] = 1; 
  }

  else //finds the path between two routers in the graph that aren't directly connected
  {  
    Q.push(src);
    nodeVisited[Q.front()] = true;

    while(!Q.empty())
    {
      int x = Q.front();
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

  path.push_back(src);

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

  /* keeps sending packets through the determined route until the total number of packets
    is sent to destination */
  while(total_packet > 0) //while we still have packets to send
  {
    cout << "The total packet is " << total_packet << endl;
    /* traverses the path between the routers. path is traversed multiple times until all packets are sent */
    for(int i = 0; i < (path_len - 1); i++) 
    {
      int new_src = path[i];
      int new_dest = path[i+1];
      int track = 0;
      bool break_out = 0;

      while(line[new_dest].get_flag() != 1 && total_packet != 0) //keep sending packets until flag is set
      {
        cout << "new src: " << new_src << endl;
        cout << "new dest: " << new_dest << endl;

        if(new_dest == dest) //if the router is the final destination, send the packet and decrement total_packets
        {
          break_out = 1; 
          bool packet_sent = send_packet(packet, new_src, new_dest);

          if(total_packet > 0)
          {
            if(packet_sent == true)
            {
              total_packet--;
              cout << "Packets left " << total_packet << endl;
            }

            while((packet_sent == false) && track < 3)
            {
              track++;
              packet_sent = send_packet(packet, src, dest);
            }

            /* if(packet_sent == true)
            {
              total_packet--;
              cout << "Packets left " << total_packet << endl;
            } */		

            if (track >= 2)
            {
              cout << "Packet traversal failed between routers " << path[i] << " and " << path[i+1] << " (packet was dropped 3 times)" << endl;
              return false;
            }
          }
        }

        else //if not, we still call send_packet, but total_packets is not decremented
        {
          bool packet_sent = send_packet(packet, new_src, new_dest);
          if(total_packet > 0)
          {
            if(packet_sent == true)
            {
              cout << "Packets left " << total_packet << endl;
            }

            while((packet_sent == false) && track < 3)
            {
              track++;
              packet_sent = send_packet(packet, src, dest);
            }

            /*
            if(packet_sent == true)
            {
              cout << "Packets left " << total_packet << endl;
            }
            */

            if (track >= 2)
            {
              cout << "Packet traversal failed between routers " << path[i] << " and " << path[i+1] << " (packet was dropped 3 times)" << endl;
              return false;
            }
          }
        }
      }
      /* if we are at the final destination router, break out of the for loop. The for loop will traverse the path again
         from the beginning if there are more packets to send */
      if(break_out == 1) 
      {
        //clear the destination router buffer queue. this represents the packets being sent to the next layer.
        line[new_dest].depop(); 
        break;
      }

      //clear the intermediate destination router buffer queue. this represents the packets being sent to the next layer.
      line[new_dest].depop();
      continue;
    }
  }
  return true;
}

Router Graph::getRouter(int router)
{
  return line[router];
}