#include "airport.h"
#include "graph.h"
#include "bfs.h"

#include <iostream>
#include <vector>
#include <map>
#include <string>

typedef string Vertex;

using namespace std;

list<Vertex> BFS::print(Vertex Source, Graph &graph, string Filename)
{   
    list<Vertex> bfsOrder;
    vector<Vertex> vertexVector = graph.getVertices();
    map<Vertex, bool> visited;

    for (size_t i = 0; i < vertexVector.size(); i++)
    {
        visited[vertexVector[i]] = false;
    }

    list<Vertex> queue;

    visited[Source] = true;
    queue.push_back(Source);

    ofstream myfile;
    myfile.open(Filename);
    myfile << "The vertices traversed in BFS order are: " << endl;

    while (!queue.empty())
    {

        Source = queue.front();
        
        myfile << Source << ",";
        bfsOrder.push_back(Source);
        queue.pop_front();

        for (auto it = graph.adjacency_list[Source].begin(); it != graph.adjacency_list[Source].end(); ++it)
        {
            if (visited[it->first] == false)
            {
                visited[it->first] = true;
                queue.push_back(it->first);
            }
        }
    }
    myfile.close();
    return bfsOrder;
}