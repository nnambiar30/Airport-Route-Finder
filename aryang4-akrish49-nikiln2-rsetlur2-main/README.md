# aryang4-akrish49-nikiln2-rsetlur2

Final Project CS 225 Fall 2021

#### Contributers

* Aadarsh Krishnan akrish49
* Aryan Gupta aryang4
* Nikil Nambiar nikiln2
* Rahul Setlur rsetlur2

### About the Project

This Project uses OpenFlights airports data set as well as routes to build a graph using the airports as vertices and the routes as edges. We were able to solve the shortest path using the A* algorithm and create a minimal spanning tree using Kruskal's algorithm. We also included the breadth first search traversal. 

### Important Links
* [Presentation Link](https://youtu.be/7yFfYb4Aq78)
* [Presentation Slides](https://docs.google.com/presentation/d/1y-j1duEPX8_8OU0EjAWA1oZF-ugl7xV6LuU20jqHfA8/edit?usp=sharing)

### Data
* [Data Source](https://openflights.org/data.html)
The data was formatted in the following manner:

##### airports.dat

Airport | Name | City | Country | IATA | ICAO | Latitude | Longitude | Altitude | Timezone | DST | Tz database time zone | Type | Source 
--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|--------|
Int | String | String | String | String | String | Float | Float | Int | Int | String | String | String | String | 

##### routes.dat

Airline | Airline ID | Source Airport | Source Aiport ID | Destination Airport | Destination Airport ID | Codeshare | Stops | Equipment
--------|--------|--------|--------|--------|--------|--------|--------|--------|
Int | Int | String | Int | String | Int | String | Int | String |

### Structure

The output file contains the statistics (created in main.cpp) of valid airports from Chicago O'Hare airport (ORD), as well as the BFS traversal.
Data is located in the data folder, and test data is located in the tests_data folder inside tests (tests/tests_data/).
All documentation is in documents folder.
The graph is created in the airport class from reading in a file.
All headers and c++ files are in the folder root, save those used in testing.

### Running the Project

The executable can be made with 'make' in the root.
This will generate an executable named 'cs225_project' which will run main.cpp.
The test executable can be made with 'make test' in the root.
This will generate an executable named 'test', which will then allow the tests to be run with "./test".
