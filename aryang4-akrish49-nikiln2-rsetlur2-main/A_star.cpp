#include "A_star.h"

using namespace std;
#define INF numeric_limits<double>::max()
typedef pair<double, Vertex> dis_node;

typedef string Vertex;

A_star::A_star(Graph g, Vertex source, map<string, airport> airports) : g_(true, true) {
	g_ = g;
	source_ = source;
	if (g_.adjacency_list[source].size() == 0) {
		for (auto &v : g_.getVertices()) {
			distance[v] = 0;
		}
	}

	for (auto &v : g_.getVertices()) {
    	distance[v] = +INF;
	}

	distance[source] = 0;

	priority_queue<dis_node, vector<dis_node>, greater<dis_node>> Q;

	Q.push(make_pair(0, source));

	while (!Q.empty()) {
		Vertex u = Q.top().second;
		Q.pop();
        Vertex v;
		for (auto it = g_.adjacency_list[u].begin(); it != g_.adjacency_list[u].end(); it++) {
			v = (*it).first;
            int heuristic = int(airports[u].find_distance(airports[v])); //heuristic
			int weight = g_.getEdgeWeight(u, v); //weight
			if (distance[v] > distance[u] + weight + heuristic) {
				distance[v] = distance[u] + weight;
				Q.push(make_pair(distance[v], v));
				path[v] = u;
			}
		}    
	}

	for (auto it = distance.begin(); it != distance.end(); it++) {
		if ((*it).second != +INF) {
			actualdistance[(*it).first] = (*it).second;
		}
	}

	numofairport = actualdistance.size();

}

void A_star::printPath(Vertex dest) {
	cout << "Distance from the node  " << source_ << " to " << dest << " is " << distance[dest] << endl;
}


Vertex A_star::getMax() {
	map<Vertex, double>::iterator max = max_element(actualdistance.begin(), actualdistance.end(), [](const pair<Vertex, double> &a, const pair<Vertex, double> &b) -> bool { return a.second < b.second; });
	Vertex a = max->first;
	return a;
}

Vertex A_star::getMin() {
	map<Vertex, double> actualdistance2 = actualdistance;
	actualdistance2.erase(source_);
	map<Vertex, double>::iterator minimum = min_element(actualdistance2.begin(), actualdistance2.end(), [](const pair<Vertex, double> &a, const pair<Vertex, double> &b) -> bool { return a.second < b.second; });

	Vertex a = minimum->first;
	return a;
}

string A_star::getpaths(Vertex source, Vertex dest) {
	string entire = dest;

	if (path[dest] == source) {
		return entire + " " + source;
	}

	return entire + " " + getpaths(source, path[dest]);
}

void A_star::print(string Filename, map<string, airport> airports)
{   

	map<Vertex, double> :: iterator it2;

	ofstream myfile;
    myfile.open(Filename);

	for(it2 = distance.begin(); it2 != distance.end(); it2++)
	{
		if (it2->second < 50000) {
			myfile << "Distance from the node " << airports[source_].name_<< " to " << airports[it2->first].name_ << " is " << it2->second << endl;	
		}	
	}

    myfile.close();
}