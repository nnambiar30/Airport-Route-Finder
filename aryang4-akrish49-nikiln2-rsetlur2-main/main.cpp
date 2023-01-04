#include "airport.h"
#include "graph.h"
#include "bfs.h"
#include "kruskal.h"
#include "A_star.h"
#include "edge.h"

#include <vector>
#include <map>
#include <iostream>

#define airports_file "data/airports.dat"
#define routes_file "data/routes.dat"
#define BFS_output "output/bfs.txt"
#define statistics_output "output/statistics.txt"
#define ex_airport "3830"

using namespace std;

int main()
{
    airport a = airport();
	map<string, airport> airports = a.make_airports(airports_file);
	map<string, vector<string>> routes = a.make_routes(routes_file);
	Graph graph = a.make_graph(airports, routes);

	BFS bfs;
	Vertex source = "1";
	bfs.print(source, graph, BFS_output);
	// cout<< BFS_output << endl;

	A_star shortest_graph = A_star(graph, ex_airport, airports);
	shortest_graph.print("output/statistics.txt", airports);

	// cout << shortest_graph.getpaths(shortest_graph.source_, shortest_graph.getMax()) << endl;
	shortest_graph.printPath(shortest_graph.getMax());
	// cout << shortest_graph.getpaths(shortest_graph.source_, shortest_graph.getMin()) << endl;
	shortest_graph.printPath(shortest_graph.getMin());

	kruskal mst = kruskal(graph);
	mst.runKruskal();
	mst.print();
	// cout << "sum: " << sum << endl;

	return 0;
}