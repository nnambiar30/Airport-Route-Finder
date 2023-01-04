CS 225

Final Project Proposal(rsetlur2, nikiln2, akrish49, aryang4)

https://docs.google.com/document/d/1JYSf5cEvQfU-K2L0fevVF2Z03ML_sD9KJggGpUqvE8U/edit


Leading Question: 
	Our idea for our Final Project is to make a connecting flight program. The goal of this program is to calculate the shortest flight between two airport terminals. This problem is commonly occurring for frequent travelers who are short on time. Our project will be deemed a success if it is able to quickly and accurately calculate the shortest flight, without fail or bugs, and is able to handle the necessary edge cases needed for full functionality. Similar implementations of this solution are seen in modern GPS systems, like Google Maps, thus we will implement a solution with similar functionality.



Data Acquisition and Processing:

For our project, our group is using the OpenFlights data set, contained at the link here: https://openflights.org/data.html . 

We will store the data in our GitHub, and all data processing will be pushed onto that folder the data is stored in. This allows us to directly call and access the data from one repository.

To prevent errors we will only fill our data structures from the file airports.dat with airports that contain a complete airport id values, latitude, and longitude. By doing this we will make sure that we only have airports with proper locations and an id to access these values. 

We will then use airlines.dat to obtain the route data by obtaining the source airline id and the destination airport id. In order to create a route on the graph, the airport id must exist in the data structure created from the last step. 

After we have all valid airports and routes, we can use the following graph algorithms. 

Graph Algorithms:

Traversal: We will be using Breadth First Search Traversal





Algorithm 1: Kruskal’s Algorithm	

Kruskal’s Algorithm finds a minimum spanning tree of a connected graph using a greedy algorithm approach where each iteration it adds the next lowest weight-edge value that will not form a cycle. It continues through this process until all the nodes are included. The weight of each edge will be the distance between the two nodes. The target time complexity is O(E log (E)) where E is the number of edges.

		 							
									
Algorithm 2: A* Search
The A* Search algorithm is a path-search algorithm that we are implementing to find the shortest path between the two airports. A* Search makes use of heuristic values to make educated guesses about which airport will yield the shortest path. Our heuristic value will be the straight-line distance from the current airport to the final airport which will be calculated using their coordinates. Our methods will take in the starting airport and the end airport and output the shortest route between the two. The target running time complexity is O(bd) where bd is the branching factor (number of successors per state).
				
		


Timeline:

Now - November 13th: Plan out implementation and write out documentation. Also acquire dataset and process as deemed necessary. Ensure that graph algorithms can be used with our given dataset. Theorize possible downfalls or struggles we will experience and plan how we can mitigate them.	

November 13th -November 29th: Implement one algorithm, fully process dataset to be used, document progress and ensure functionality of code written so far. Aim for roughly 60% completion before mentor meeting. 


November 29th - December 1st (Meet with mentor) - Have 2 algorithms implemented and tested, make sure it works with the data set 

December 13th(Due date) -  Have all algorithms implemented, tested and finalized according to all of our specifications. Complete the presentation and the report and have those ready for submission.


