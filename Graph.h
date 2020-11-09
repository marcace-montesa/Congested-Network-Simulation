#include "Router.h"
#include "Packet.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define NODES 5

#ifndef Graph_H
#define Graph_H

//basic functionality complete

class Graph
{
    public:
        //graph constructor, will receive number of routers in graph.
        Graph(int N);
        void add_edges(int i, int j);   
        bool is_connected(int i, int j); 
        bool packet_path(Packet packet, int src, int dest, int packets);
        bool send_packet(Packet packet, int src, int dest);
        Router getRouter(int router);
        int distance(int i, int j);
        int get_router_num();
        
    private:
        int router_num;
        vector<Router> line;
        int adjacency_matrix[NODES][NODES];
        bool buffer_flag;
};



#endif 
