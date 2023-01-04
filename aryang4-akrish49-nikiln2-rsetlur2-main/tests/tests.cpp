#include "../airport.h"
#include "../graph.h"
#include "../bfs.h"
#include "../A_star.h"
#include "../kruskal.h"
#include "catch/catch.hpp"

#include <iostream>

#define airports_file "data/airports.dat"
#define routes_file "data/routes.dat"

airport a = airport();

TEST_CASE("airport constructor") {
    airport airport = ::airport("0", "Airport", "-1", "1");

    REQUIRE(airport.ID_ == "0");
    REQUIRE(airport.name_ == "Airport");
    REQUIRE(airport.latitude_ == "-1");
    REQUIRE(airport.longitude_ == "1");
}

TEST_CASE("find_distance") {

    airport airport1 = airport("1", "1", "-6.081689834590001", "145.391998291");
    airport airport2 = airport("2", "2", "-5.20707988739", "145.789001465");
    airport airport3 = airport("3", "3", "61.1604995728", "-45.4259986877");
    airport airport4 = airport("4", "4", "36.50360107421875", "2.8141698837280273");
    airport airport5 = airport("5", "5", "-25.9971446991", "32.929351806599996");


	REQUIRE(abs(airport1.find_distance(airport1)) == 0);
    REQUIRE(abs(airport1.find_distance(airport2) - 66) < 1);
	REQUIRE(abs(airport2.find_distance(airport1) - 66) < 1);
    REQUIRE(abs(airport4.find_distance(airport3) - 2679) < 1);
    REQUIRE(abs(airport5.find_distance(airport4) - 4739) < 1);
    REQUIRE(abs(airport3.find_distance(airport5) - 7404) < 1);
}

TEST_CASE("Check airports are read from file correctly")
{
    map<string, airport> airports = a.make_airports("tests/test_data/airports_minimal.dat");

    REQUIRE(airports.size() == 5);

    REQUIRE(airports["1"].ID_ == "1");
    REQUIRE(airports["1"].name_ == "\"Chicago O'Hare International Airport\"");
    REQUIRE(airports["1"].latitude_ == "41.9786");
    REQUIRE(airports["1"].longitude_ == "-87.9048");

    REQUIRE(airports["2"].ID_ == "2");
    REQUIRE(airports["2"].name_ == "\"Dallas Fort Worth International Airport\"");
    REQUIRE(airports["2"].latitude_ == "32.896801");
    REQUIRE(airports["2"].longitude_ == "-97.038002");
}


TEST_CASE("Check badly entered airports")
{
    map<string, airport> airports = a.make_airports("tests/test_data/airports_minimal_bad.dat");
    REQUIRE(airports.size() == 2);
}


TEST_CASE("Check good routes are read from file and added correctly")
{
    map<string, vector<string>> routes = a.make_routes("tests/test_data/routes_minimal.dat");
    vector<string> v1{"3","4"};
    vector<string> v2{"3"};
    vector<string> v3{"2","1"};
    vector<string> v4{"2"};
    vector<string> v5{};

    REQUIRE(routes.size() == 5);
    REQUIRE(routes["1"] == v1);
    REQUIRE(routes["2"] == v2);
    REQUIRE(routes["3"] == v3);
    REQUIRE(routes["4"] == v4);
    REQUIRE(routes["5"] == v5);
}

TEST_CASE("Check graph from data") {
    map<string, airport> airports = a.make_airports("tests/test_data/airports_minimal.dat");
    map<string, vector<string>> routes = a.make_routes("tests/test_data/routes_minimal.dat");
    Graph graph = a.make_graph(airports, routes);

    REQUIRE(graph.getVertices().size() == 5);
    REQUIRE(graph.getEdges().size() == 6);
    REQUIRE(graph.edgeExists("1", "3"));
    REQUIRE(graph.edgeExists("1", "4"));
    REQUIRE(graph.edgeExists("2", "3"));
    REQUIRE(graph.edgeExists("3", "1"));
    REQUIRE(graph.edgeExists("3", "2"));
    REQUIRE(graph.edgeExists("4", "2"));

}


TEST_CASE("Check bad routes aren't added to graph") {
	map<string, airport> airports = a.make_airports("tests/test_data/airports_minimal.dat");
    map<string, vector<string>> routes = a.make_routes("tests/test_data/routes_minimal_bad.dat");
    Graph graph = a.make_graph(airports, routes);

    REQUIRE(graph.getEdges().size() == 2);
    REQUIRE(graph.edgeExists("1", "3"));
    REQUIRE(graph.edgeExists("1", "4"));
}

TEST_CASE("bfs") {
    Graph graph(true, 4, 1);

    BFS bfs;
    list<Vertex> bfsOrder = bfs.print("0", graph, "output/bfs.txt");
    
    REQUIRE(bfsOrder.size() == 4);
    REQUIRE(bfsOrder.front() == "0");
    bfsOrder.pop_front();
    REQUIRE(bfsOrder.front() == "1");
    bfsOrder.pop_front();
    REQUIRE(bfsOrder.front() == "3");
	bfsOrder.pop_front();
    REQUIRE(bfsOrder.front() == "2");
}

TEST_CASE("Check A*") {
    map<string, airport> airports = a.make_airports("tests/test_data/airports_minimal.dat");
    map<string, vector<string>> routes = a.make_routes("tests/test_data/routes_minimal.dat");
    Graph graph = a.make_graph(airports, routes);

    A_star shortest = A_star(graph, "1", airports);

    REQUIRE(shortest.distance["1"] == 0);
    REQUIRE(shortest.distance["2"] == 826);
    REQUIRE(shortest.distance["3"] == 135);
    REQUIRE(shortest.distance["4"] == 1739);
    REQUIRE(shortest.distance["5"] > 50000);

    REQUIRE(shortest.distance[shortest.getMax()] == 1739);
    REQUIRE(shortest.distance[shortest.getMin()] == 135);
}

TEST_CASE("Kruskal") {
    map<string, airport> airports = a.make_airports("tests/test_data/airports_minimal.dat");
    map<string, vector<string>> routes = a.make_routes("tests/test_data/routes_minimal.dat");
    Graph graph = a.make_graph(airports, routes);

    kruskal krusk = kruskal(graph);
	krusk.runKruskal();
    
    vector<int> krus = {};
    string everything = "";
    for(unsigned long i = 0; i < krusk.mst.size(); i++) {
        everything += krusk.mst[i].second.first + ":" + krusk.mst[i].second.second + ",";
        krus.push_back(krusk.mst[i].first);
    }
    everything = everything.substr(0,everything.length() - 1);
    
    REQUIRE("1:3,2:3,2:4" == everything);
    REQUIRE(krus[0] == 135);
    REQUIRE(krus[1] == 691);
    REQUIRE(krus[2] == 1231);
}