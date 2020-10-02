#include "Router.h"
#include "Packet.h"
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define NODES 5

#ifndef Graph_H
#define Graph_H

//not complete: added graph class so we can create objects of graph in main
class Graph
{
    public:
        //graph constructor, will receive number of routers in graph.
        Graph(int N);
        //note: decided to do an adjacency matrix instead of adjacency list, will change how the below methods are
        //implemented compared to what we had in UML
        
        //the following methods were moved here instead of Packet.h
        void add_edges(int i, int j);   
        bool is_connected(int i, int j); 
        void send_packet(Packet packet, int i);
        int distance(int i, int j);

    private:
        int router_num;
        vector<Router> line;
        int adjacency_matrix[NODES][NODES];
};

#endif 
