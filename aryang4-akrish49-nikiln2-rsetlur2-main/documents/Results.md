Results:

Our final project’s goal was to process and leverage the data provided by OpenFlights to build a graph that models all airports and their corresponding routes. This graph is traversed by BFS, utilized in A* Search to find the shortest path between two airports, and utilize Kruskal’s to create a minimum spanning tree. One additional feature is a statistics method, which will return notable data pertaining to a user specified airport and the routes it serves.

We start by building the graph. In order to do this, we first read the data from our airports and routes dataset and build a map from it. This map uses the airport ID as the key and the value being a proprietary data structure called airport which we generate for every airport. Not every airport can be included, as some in the dataset lack all the necessary information, and as such it will not be included. After reading the airports from the file, we move on to the routes, which are also added if and only if there is the necessary information, being source and destination. These nodes are iterated over and added to the graph. The distance is used to weight the graph edges, and this value is calculated using the Haversine formula.

The first goal was to implement our traversal, being BFS. BFS ( Breadth First Search) is a traversal algorithm which traverses the graph layer by layer. When using BFS for graphs, key things to watch out for are loops and cycles, which will lead to an infinite loop while traversing. To overcome this challenge, we created a visited data structure to ensure each node is counted only once. We also decided to use a queue to aid in our traversal, which we use to push each iterated node. As we traverse through the graph, or more specifically the adjacency list, we check to see if the node is visited, if not we continue to traverse while pushing the node onto our queue. At the end, we print out our nodes in BFS order.

Our next goal was to use to implement a searching algorithm, which in this case was A* search. This algorithm aims to find the shortest path between two airports, utilizing a heuristic to speed up the search. This algorithm is essentially an upgraded version of Djikstras, as it follows the same basic function, while implementing a heuristic. A heuristic is essentially an educated guess the algorithm uses to find the next shortest node without having to check each neighboring one like Djisktra’s. 


![Source : Compare A* with Dijkstra algorithm](https://i.ytimg.com/vi/g024lzsknDo/maxresdefault.jpg)
	
This visualization shows how much more efficient A* is, and that is the methodology behind why we wanted to use A* rather than Dijkstra's. The biggest challenge came with determining and implementing a proper heuristic. We ended up using straight-line distance as our heuristic. This greatly sped up our computation speed, as there are a large number of connecting airport nodes for each airport, and by not checking every possible one, we skip out on many wasted calculations.

Finally, our last goal was to implement Kruskal’s algorithm. Kruskal’s algorithm is an algorithm that finds a minimum spanning tree(MST) of the edges of a graph. Kruskal’s works by sorting the edges by weight, then it picks what the smallest edge is, and then it adds it to the MST. One important thing to note is that a cycle can’t be formed otherwise the edge isn’t added to the MST.  The way that Kruskal’s works in our project is that we implement Disjoint Set operations like the find operation and the union operation. We then sorted the graph by increasing weight and created the minimum spanning tree. When implementing the algorithm, the biggest challenge that we had was verifying that the MST was correct and verifying that our data structures would build the correct maps.

Below we have screenshots of each algorithm being run and their results:

![image](https://media.github-dev.cs.illinois.edu/user/9885/files/89cbcf4f-b7a7-4fec-a82a-8a0b1ce8ed88)
BFS

![image](https://media.github-dev.cs.illinois.edu/user/9885/files/a0829e50-e21b-4bbf-b563-de66112383ed)
A*

![image](https://media.github-dev.cs.illinois.edu/user/9885/files/c865d97d-82cd-4e38-bf6b-72d375d72a64)
Kruskal's

