#include "Router.h"
#include "Packet.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define NODES 5

#ifndef Graph_H
#define Graph_H

class Graph
{
    public:
        Graph(int N); //Graph Constructor
        void add_edges(int i, int j); //adds edges between two routers
        bool is_connected(int i, int j); //checks if two routers are directly connected
        bool packet_path(Packet packet, int src, int dest, int packets); //sends packet between any two routers in the graph
        bool send_packet(Packet packet, int src, int dest); //sends packet between two directly connected routers in graph
        Router getRouter(int router); //returns the router
        
    private:
        int router_num; //unique number for each router
        vector<Router> line; //vector that contains the routers in the graph
        int adjacency_matrix[NODES][NODES]; //matrix that stores router edges
};

#endif 