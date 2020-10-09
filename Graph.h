#include "Router.h"
#include "Packet.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define NODES 5

#ifndef Graph_H
#define Graph_H

//basic functionality complete
//not complete: packet traversal of graph, sending multiple packets, faulty router problem
class Graph
{
    public:
        //graph constructor, will receive number of routers in graph.
        Graph(int N);
        void add_edges(int i, int j);   
        bool is_connected(int i, int j); 
        void send_packet(Packet packet, int src, int dest);
        //next step: create send_packet that traverses graph
        //also: send multiple packets
        Router getRouter(int router);
        int distance(int i, int j);
        
    private:
        int router_num;
        vector<Router> line;
        int adjacency_matrix[NODES][NODES];
};

#endif 
