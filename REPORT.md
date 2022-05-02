## TrojanMap

![Trojan Map](/Report_files/0001.jpg)

<b>This project focuses on using data structures in C++ and implementing various graph algorithms to build a map application.</b>

## The Data Structure

Each point on the map is represented by the class **Node** shown below and defined in [trojanmap.h](src/lib/trojanmap.h).


## PHASE 1 submission:

Device Specs: ASUS ROG STRIX: intel i5 9th Generation

## Using Ubuntu on Oracle Virtual Box: 
Oracle VM Box Version: 6.1.0

## Installations

The below packages and libraries were installed on the Ubuntu Operating System:
- OpenCV
- cmake libgtk2.0-dev pkg-config
- libcanberra-gtk3-module
- libncursesw5-dev

## Description of the project:
![Description](/Report_files/0002.jpg)

## Functions
 We can See that we have implemented Functions of :

      1. Implementation of Auto complete: 5 points. (Phase 1)

      2. Implementation of GetPosition: 5 points. (Phase 1)

      3. Implementation of EditDistance: 10 points. (Phase 1)

## 1. Autocomplete

- Function:
![Autocomplete](/Report_files/0006.jpg)

std::vector<std::string> Autocomplete(std::string name);

- Description:
The node names were considered as the locations. Assumed the names of nodes as the locations. As we typed the location's partial name, a list of possible locations with the full name will be returned. Here uppercase and lower case are treated as the same character by using std::tolower.

To check if the input name matches the name in the database. We need first to call std::substring to compare the two strings' size. The time complexity for this function is O(n) where n is the number of nodes.

- Time Complexity:
The time complexity of this function is O(n), where n is the total number of nodes with a name. The first time that the user executes this function, it will require O(n*) to initialize the hashmap, where n* is the total number of nodes in the map.

-Ubuntu Virtual Box Runtime: 
Ex: 'Sh' -> 21ms 

## 2. Find Position

- Functions:
![GetPosition](/Report_files/0007.jpg)

std::pair<double, double> GetPosition(std::string name);

double GetLat(std::string id);

    Given location's id, return its latitude.
    Time Complexity: O(1).

double GetLon(std::string id);

    Given location's id, return its longitude.
    Time Complexity: O(1).

- Description:
Given a location name, returns the position. If id does not exist, return (-1, -1).USING GET-lONGITUDE AND GET lATITUDE:

Given a non-duplicate location name, return the latitude, longitude, and mark the map's locations. If the location does not exist, return (-1, -1).

To check if the input_name is on the map, we need to loop through all the map elements and use an if_loop till filter satisfied elements as the output. 

Helper functions GetLat and GetLon are used to extract values of latitude and longitude, respectively.

- Time Complexity:
The time complexity of this function is O(n) where n is the number of nodes.

-Ubuntu Virtual Box Runtime: 
Ex: 'Rolphs' ->  Ralphs -> 15ms

Edit Distance: CalculateEditDistance: Calculate edit distance between two location names

![Edit Distance](/Report_files/0008.jpg)

## PHASE 2

Implementation of shortest path: 15 points. (Phase 2)

    Bellman-Ford implementation
    Dijkstra implementation
    Plot two paths, and measure and report time spent by two algorithms.

Implement of Cycle detection: 10 points. (Phase 2)

    Boolean value and draw the cycle if there exists one.

Topological Sort: 10 points. (Phase 2)

    Check whether there exist a topological sort or not
    Return the correct order and plot those point on the map



## 3. Calculate Shortest Path Between Two Places

- Functions:

std::vector<std::string> CalculateShortestPath_Dijkstra(std::string &location1_name,
                                               std::string &location2_name);

    Each time we add the nearest unvisited location into the set of visited locations. Update shortest distance of this location’s neighbors and its predecessor map. This continues until the location is the destination. It traverses the predecessor map and output is the shortest path. If we traverse neighbors that we can obtain and do not meet the destination, that means the start node cannot arrive at the destination. In this case, we return an empty path.
    Time Complexity: O(n^2), where n is the number of nodes in the given map.

DJIKSTRA

![Djikstra](/Report_files/0009.jpg)

std::vector<std::string> CalculateShortestPath_Bellman_Ford(std::string &location1_name,
                                               std::string &location2_name);

    Each time update the shortest distance and the predecessor map by adding the intermediate edge by one. This contiinues until we traverse all nodes. If the destination has been updated, we traverse the predecessor map and output is the shortest path, else it means the start point cannot arrive at the destination and we return an empty path.
    Time Complexity: O(n + m), where n is the number of nodes, m is the number of edges in the given map.

BELLMAN FORD

![BellFord](/Report_files/0010.jpg)    

std::vector<std::string> GetNeighborIDs(std::string id);

    Given the location's name, return its neighbors.
    Time Complexity: O(1).

- Description:
User types in two locations A and B, the program returns the best route from A to B on the terminal and shows the path on the popup map window. The distance between 2 points is the euclidean distance using latitude and longitude. User can choose to use Dijkstra algorithm or Bellman-Ford algorithm. If there is no path, it returns an empty vector.

- Time Complexity:
For Dijkstra: Uses Greedy: and The Time Complexity will be O(V* Log(E)
where V is Vertices and E are Edges.
For Bellman-Ford: Uses Dynamic Programming: and The Time Complexity will be O(V*E) where V is Vertices and E are Edges.

- Ubuntu Virtual Box Runtime:
Ex: KFC to Ralphs
Distance Measured: 0.95274 Miles

Djikstra: 156ms
Bellman Ford: 18621ms

Conclusion: Djikstra is Faster, and BellMan Ford takes atleast 80-100 Times Djikstra'S Time
The runtime is higher for Bellman Ford than Dijkstra. Therefore, Dijkstra is a better choice for computing the shortest path in the Trojan Map application.

Inferences: Google Maps: The output map path of the Shortest Path algorithms was compared with that of Google Maps for the same pair of locations and was found to be the same.

## 4. Cycle Detection

![Cycle Detection](/Report_files/0018.jpg) 

- Functions:

bool CycleDetection(std::vector<std::string> &subgraph, std::vector<double> &square);
  // Given a subgraph specified by a square-shape area, determine whether there is a
  // cycle or not in this subgraph.

    We create a map named visited that has all nodes in the given area and another map named predecessor of the child node and its parent node. We traverse all nodes in the visited map and check if a cycle is formed or not. The result is returned as a boolean value, true or false.
    Time Complexity: O(V+E), where V is the number of nodes in the map and E is the number of edges in the given area.

  // Check whether the id is in square or not
  bool inSquare(std::string id, std::vector<double> &square);

  bool hasCycle(std::string current_id,std::unordered_map<std::string, bool> &visited, std::string parent_id);

  // Get the subgraph based on the input
  std::vector<std::string> GetSubgraph(std::vector<double> &square);

    We mark the current node as true in the visited map. We traverse the curent node's neighbouring nodes and record the current node as predecessor node of the neighbouring nodes. If the neighbour is in the area and it has not been visited, we use recursion. If the neighbor is in the area and it has been visited and it is not the parent node, that means there exists a cycle, then we return true, Else we return false.
    Time Complexity: O(n + m), where n is the number of nodes in the given area, m is the number of edges in the given area.

- Description:
The user types in four geographical parameters to form a square-shaped region in the map, then the program detects if there is a cycle in the given region or not and shows the result in the terminal.

- Time Complexity:
O(V+E), where V is the number of nodes in the map and E is the number of edges in the given area.

- Ubuntu Virtual Box Runtime:
Ex: left Bound Longitude: -118.299
    right Bound Longitude: -118.264
    upper Bound Latitude: 34.032
    lower Bound Latitude: 34.011

    Time Taken: 4ms

std::vector<std::string> TrojanMap::DeliveringTrojan(std::vector<std::string> &locations,
                                                     std::vector<std::vector<std::string>> &dependencies){

void TrojanMap::CreateGraphFromCSVFile()

Inference:
- DFS: Depth First Search is the algorithm that was the basis for Cycle Detection.

## 5. Topological Sort

- Functions:

  void TravellingTrojan_helper(std::vector<std::string> &location_ids,std::vector<std::vector<double>> &weights,std::vector<std::vector<std::string>> &path,double &minDist,std::vector<int> &currentPath,double currDist,std::unordered_set<int> &seen, bool is_bruteforce);

  // Given CSV filename, it read and parse locations data from CSV file,
  // and return locations vector for topological sort problem.
  std::vector<std::string> ReadLocationsFromCSVFile(std::string locations_filename);
  
  // Given CSV filenames, it read and parse dependencise data from CSV file,
  // and return dependencies vector for topological sort problem.
  std::vector<std::vector<std::string>> ReadDependenciesFromCSVFile(std::string dependencies_filename);

  // Given a vector of location names, it should return a sorting of nodes
  // that satisfies the given dependencies.
  std::vector<std::string> DeliveringTrojan(std::vector<std::string> &location_names,
                                            std::vector<std::vector<std::string>> &dependencies);

  void TopologicalSort(std::string &location, std::unordered_map<std::string, std::vector<std::string>> &dependency_map, std::unordered_map<std::string, bool> &visited, std::vector<std::string> &result);  

TopoLogical Sort

  ![TopoSort](/Report_files/0019.jpg)      

    The input is a set of locations and corresponding dependencies and the output is a topological sorted path. This program can visualize the results on the map and is implemented using double-ended queue DFS. It will plot each location name and also some arrowed lines to demonstrate a feasible route.

- Time Complexity:
O(V+E), where V is the number of nodes in the map and E is the number of edges in the given area.

- Ubuntu Virtual Box Runtime:
Ex: Locations File 3 Values: Locations.csv
    Dependencies File 3 Values in it: Dependencies.csv

    Time Taken: 0ms

Inference:
- DFS: Depth First Search is the algorithm that was the basis for Topological Sort.

## PHASE 3
 
 Implementation of Travelling Trojan: (Phase 3)

    Brute-force: 5 points.
    Brute-force enhanced with early backtracking: 5 points.
    2-opt: 10 points.
    Animated plot: 5 points.

FindNearby points: 10 points. (Phase 3)

    Return the correct ids and draw the points.

Video presentation and report: 10 points. (Phase 3)
Creating reasonable unit tests: 10 points.

    Three different unit tests for each item.

## 6. Travelling Trojan (TSP)

- Functions:

void TrojanMap::TSP_helper(std::vector<std::vector<double>> &weights, std::vector<std::string> &location_ids,
    std::vector<std::vector<std::string>> &path, double &min_dist,
    std::vector<int> &current_path, double curr_dist, std::unordered_set<int> &seen, bool bruteforce);

    DFS algorithm to find the minimum cost given the start location.
    Time Complexity: O(n!), where n is the number of locations.

![TSPRuntimes](/Report_files/0013.jpg)    

std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_Brute_force(std::vector<std::string> &location_ids);

    We create an adjacent matrix with rows and columns to be locations reindexed. We try all permutations of the path and find the minimum cost. For each time when we get a better path, we push back this path to our final result. It returns  the minimum cost and the result vector.

  - Time Complexity: O(n!), where n is the number of nodes in the input.

  - Ubuntu Virtual Box Runtime:
  Ex: Input = 8 locations

    Time Taken: 38ms

std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_Backtracking(std::vector<std::string> location_ids);

    We create an adjacent matrix with rows and columns to be locations reindexed. We implement DFS to try all permutations of the path and find the minimum cost. For each time when we get a better path, we push back this path to our final result. It returns the minimum cost and the result vector.

  - Time Complexity: O(n!), where n is the number of nodes in the input.

  - Ubuntu Virtual Box Runtime:
  Ex: Input = 8 locations

    Time Taken: 14ms

std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_2opt(std::vector<std::string> &location_ids);

    We use two for loops to obtain a sub part in the location ids vector and reverse this sub part. If the updated vector's path length is smaller, we update things similar to Brute Force and go back to start again. This is repeated until no improvement is made.

  - Time Complexity: O(n^2), where n is the number of locations.

  - Ubuntu Virtual Box Runtime:
  Ex: Input = 8 locations

    Time Taken: 0ms

Conclusion: 2-opt is better for larger values, Backtracking isfastest for Smaller and Medium inputs.
    2-opt may not always find the best result, and it needs a base case to implement greedy nearest neighbor algorithms.
    2-opt is way faster than the brute force in terms of run time, especially if the input N is greater than 10.
    The time complexity of this function is O(n*x), where x is the times of non_improvments defined by users.

Inferences: TSP: The runtime is the least for 2-opt, higher than that for Backtracking and is the highest for Brute Force. Therefore, the 2-opt approach is the best suited algorithm for a large number of nodes.


## 7. Find Nearby

- Function:

std::vector<std::string> TrojanMap::FindNearby(std::string attributesName, std::string name, double r, int k);

    Given an attribute name C, a location name L and a number r and k, we find at most k locations in attribute C on the map near L (not including L) within the range of r and return a vector of string ids. The order of locations is from the nearest to the farthest.

FIND NEARBY

![Find Nearby](/Report_files/0020.jpg)     

- Time Complexity: 
The time complexity of this function is O(m * n)

- Ubuntu Virtual Box Runtime:
  Ex: Input Attribute: Library
      Input Location: Leavey Library
      Input Radius: 10
      Input k: 5

    Time Taken: 359ms

## Map UI using NCurses - Extra Creds
 Extra credit items: Maximum of 20 points:
    Create dynamic and animated UI using ncurses: 10 points
 
Creation of the Animated & dynamic User Interface

- The First UI which Pops Up in the Terminal when the program is executed
- This is the given MAP- Which we have to use for our functions and get required outputs.
We have to select the Number from 1 – 8 for the execution of desired functions



## Some Major Algorithms Implemented and Learnt

Dijkstra algorithm
Bellman-Ford algorithm
Brute-force (i.e. generating all permutations, and returning the minimum)
Brute-force enhanced with early backtracking
2-opt Heuristic & 3-opt (Tried)
Topological Sort
DFS

## Runtime of all implemented functionalities

Autocomplete:                   O(n)
Finding the Position:           O(n)

Calculate the Shortest Path: 
Dijkstra:                       O(V*log(E))
Bellman Ford:                   O(V*E)
Cycle Detection:                O(V+E)
Topological Sort:               O(V+E)

Travelling Trojan (TSP)
Brute Force:                    O(n!)
Backtracking:                   O(n!)
2 - Opt:                        O(n^2)
x - opt:                        O(n^x)
Find Nearby:                    O(m * n)


## Conclusion: 

Conclusion

In this project, I constructed a backend map application for users to navigate around the USC campus. I used some basic STL libraries such as queue, array, list, and iterator, etc. I implemented graph search algorithms, classical sorting algorithms, generated reasonable Google unit tests, and further demonstrated the traveling salesperson computation with animations.

- To improve the efficiency of the program we can try different Algorithms, Diff Data Structures and Libraries which will also reduce the runtime.

- The Use of GITHUB and GIT to implement and present our code and work on vast number of problems while the same was a new and Learning Experience.

- Trojan Map Project gave us an application based learning to learn and practice C++, and its many important data structures.

- Graph algorithms in software programming, including DFS, Bellman Ford, Dijkstra and recursive algorithms, and various others are now imprinted correctly and usage based learning was obtained.


## The future scope of this project:

- 3- opt Implementation and using other optimization techniques.
- Genetic algorithm implementation for Travelling Trojan:
- To cover a larger geographical area ex: LA County- can be done to broaden the scope of the project and handle bigger dataset.
- Improving the UI and Making it more User Friendly so it can be used as an Alternative for los Angeles, CA-90007 Residents.
- Web Appplications, Or Further Applications to improve and make it for all.

## Link to Video Presentation: 
https://youtu.be/CioX3-m47sk

[![TrojanMap RDX](https://img.youtube.com/vi/CioX3-m47sk/0.jpg)](https://www.youtube.com/watch?v=CioX3-m47sk)

## Link to Powerpoint Presentation (with output screenshots and analysis):
https://docs.google.com/presentation/d/1t7qml6PQMXKnuVG7zzQRfYxsKp-AA2mYpbaw0YApjbA/edit?usp=sharing

![Thank You](/Report_files/0021.jpg)
