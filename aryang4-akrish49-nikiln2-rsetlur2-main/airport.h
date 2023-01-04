#pragma once
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include "graph.h"

using namespace std;

class airport {
	public:
		string ID_;
		string name_;
		string latitude_;
		string longitude_;


		airport();

		airport(string ID, string name, string latitude, string longitude);

		double rad(double dec);

		double hav(double a, double b);

		int find_distance(airport other);

		map<string, airport> make_airports(string file_name);

		map<string, vector<string>> make_routes(string file_name);

		Graph make_graph(map<string, airport> airports, map<string, vector<string>> routes);
};