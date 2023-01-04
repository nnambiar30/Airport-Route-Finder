#include "airport.h"
#include <math.h>
#include <iostream>
#define radius 3956

using namespace std;

airport::airport() {}

airport::airport( string airportID, string name, string latitude, string longitude) {
	ID_ = airportID;
	name_ = name;
	latitude_ = latitude;
	longitude_ = longitude;
}

double airport::rad(double dec) {
	return dec * M_PI / 180.0;
}


double airport::hav(double a, double b) {
	return pow(sin(rad(a - b) / 2), 2);
}

int airport::find_distance(airport other) {
	double longA = stof(longitude_);
	double longB = stof(other.longitude_);
	double latA  = stof(latitude_);
	double latB  = stof(other.latitude_);

	double a =  hav(latA, latB) +
				hav(longA, longB) *
				cos(rad(latB)) * 
				cos(rad(latA));
	return (int) 2.0 * radius * asin(sqrt(a));
}

map<string, airport> airport::make_airports(string file_name) {
	ifstream airport_file;
	airport_file.open(file_name);
	map<string, airport> airports;

	while (airport_file.good()) {

		airport airport;
		string temp;
		getline(airport_file, airport.ID_, ',');
		getline(airport_file, airport.name_, ',');
		getline(airport_file, temp, ',');
		getline(airport_file, temp, ',');
		getline(airport_file, temp, ',');
		getline(airport_file, temp, ',');
		getline(airport_file, airport.latitude_, ',');
		getline(airport_file, airport.longitude_, ',');
		getline(airport_file, temp, '\n');

		try {
			stof(airport.longitude_);
			stof(airport.latitude_);
			airports[airport.ID_] = airport;
		}
		catch (...) {
		}
	}
	airport_file.close();

	return airports;
}

map<string, vector<string>> airport::make_routes(string file_name) {
	ifstream route_file;
	route_file.open(file_name);
	map<string, vector<string>> routes;

	while (route_file.good()) {
		string temp;
		string source_ID;
		string dest_ID;

		getline(route_file, temp, ',');
		getline(route_file, temp, ',');
		getline(route_file, temp, ',');
		getline(route_file, source_ID, ',');
		getline(route_file, temp, ',');
		getline(route_file, dest_ID, ',');
		getline(route_file, temp, '\n');

		if (routes.find(source_ID) == routes.end()) {
			routes[source_ID] = vector<string>{dest_ID};
		}
		else {
			routes[source_ID].push_back(dest_ID);
		}
	}
	route_file.close();

	return routes;
}

Graph airport::make_graph(map<string, airport> airports, map<string, vector<string>> routes) {
	Graph graph = Graph(true, true);

	for (auto &keyVal : airports) {
		graph.insertVertex(keyVal.first);
	}

	for (auto &keyVal : routes) {
		string source = keyVal.first;

		if (graph.vertexExists(source) && airports.find(source) != airports.end()) {
			airport source_airport = airports[source];
			for (auto &dest : keyVal.second) {
				if (airports.find(dest) != airports.end() && airports.find(source) != airports.find(dest)) { 
					airport dest_air = airports[dest];
					graph.insertEdge(source, dest);
					graph.setEdgeWeight(source, dest, source_airport.find_distance(airports[dest]));
					graph.setEdgeLabel(source, dest, source_airport.name_ + "To" + dest_air.name_);
				}
			}
		}
	}

	return graph;
}