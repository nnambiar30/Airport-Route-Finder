#pragma once

#include "graph.h"
#include "edge.h"
#include "airport.h"

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

typedef string Vertex;

class A_star{
    public: 
        A_star(Graph g, Vertex source, map<string, airport> airports);
        Graph g_;
        Vertex source_;
        int numofairport;
        map<Vertex, double> actualdistance;
        map<Vertex, double> distance;
        void printPath(Vertex dest);
        void printmin_and_max();
        Vertex getMax();
        Vertex getMin();
        
        map<Vertex, Vertex> path;
        string getpaths(Vertex source, Vertex dest);
        void print(string FileName, map<string, airport> airports);
};