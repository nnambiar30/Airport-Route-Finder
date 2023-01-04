#pragma once
#include <string>
#include "graph.h"
#include "edge.h"
#include "airport.h"
#include <fstream>
using namespace std;

class BFS {
    public:
        list<Vertex> print(Vertex source,Graph &graph, string FileName);
};