
#include "kruskal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
typedef string Vertex;

kruskal::kruskal(Graph g) : g_(true, true) {
	g_ = g;
    vector<Vertex> vList = g_.getVertices();
    for (auto &v : vList) {
        parent[v] = v;
        for(auto &x : g_.getAdjacent(v)) {
            gInit.push_back(make_pair(g_.getEdgeWeight(v, x), E(x, v)));    
        }
    }
}

Vertex kruskal::find_set(Vertex i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void kruskal::union_set(Vertex u, Vertex v){
    parent[u] = parent[v];
}

void kruskal::runKruskal() {
    Vertex uRep;
    Vertex vRep;
    sort(gInit.begin(), gInit.end());
    for (unsigned long i = 0; i < gInit.size(); i++) {
        uRep = find_set(gInit[i].second.first);
        vRep = find_set(gInit[i].second.second);
        if (uRep != vRep) {
            mst.push_back(gInit[i]);
            union_set(uRep, vRep);
        }
    }
}

void kruskal::print() {
    cout << "Edge :" << " Weight " << endl;
    int count = 0;
    for(unsigned long i = 0; i < mst.size(); i++) {
        cout << mst[i].second.first << " - " << mst[i].second.second << " : " << mst[i].first;
        cout << endl;
        count++;
    }
    cout << "Count: " << count << endl;
}



