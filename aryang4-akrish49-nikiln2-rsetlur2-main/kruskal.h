#pragma once

#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

#include "graph.h"
#include "edge.h"
#include "airport.h"

typedef string Vertex;
typedef pair<Vertex, Vertex> E;


class kruskal {
    public:
        kruskal(Graph g);
        Graph g_;
        Vertex source_;
        vector<pair<int, E> > gInit;
        vector<pair<int, E> > mst;
        map<Vertex, Vertex> parent;
        void union_set(Vertex u, Vertex v);
        Vertex find_set(Vertex i);
        void runKruskal();
        void print();
};