## TrojanMap

![Trojan Map](/Report_files/0001.jpg)


<b>This project focuses on using data structures in C++ and implementing various graph algorithms to build a map application.</b>

https://docs.google.com/presentation/d/1t7qml6PQMXKnuVG7zzQRfYxsKp-AA2mYpbaw0YApjbA/edit?usp=sharing

<b>Phase 1 submission:</b>

    High-level overview of your design (Use diagrams and pictures for your data structures).

<pr>
<b>Phase 1</b>
 We can See that we have implemented Functions of :
      1. Implementation of Auto complete: 5 points. (Phase 1)
      2. Implementation of GetPosition: 5 points. (Phase 1)
      3. Implementation of EditDistance: 10 points. (Phase 1)

      *-> Auto complete:  * Autocomplete: Given a parital name return all the possibe locations with partial name as the prefix. The function should be case-insensitive.

    Assumed the names of nodes as the locations. As we typed the location's partial name, a list of possible locations with the full name will be returned. Here uppercase and lower case are treated as the same character by using std::tolower.

    To check if the input name matches the name in the database. We need first to call std::substring to compare the two strings' size. The time complexity for this function is O(n) where n is the number of nodes.


      Using: 
      -> for (auto id : data) 
            ids = id.second.name;
            std::transform(ids.begin(), ids.end(), ids.begin(), ::tolower);
            if (name == ids.substr(0, name.size())) {
                  results.push_back(id.second.name);

      *-> GET POSITION:  * GetPosition: Given a location name, return the position. If id does not exist, return (-1, -1).
      USING GET- lONGITUDE AND GET lATITUDE:



    Given a non-duplicate location name, return the latitude, longitude, and mark the map's locations. If the location does not exist, return (-1, -1).

    To check if the input_name is on the map, we need to loop through all the map elements and use an if_loop to filter satisfied elements as the output. The time complexity of this function is O(n) where n is the number of nodes.

    Helper functions GetLat and GetLon are used to extract values of latitude and longitude, respectively.


      -> for (auto id : data) { //for each original name in database
            if (name == id.second.name) { //check if the input name is in the database
            results.first = GetLat(id.first);//Insert Latitude as first param
            results.second = GetLon(id.first);//Insert Longitude as second param
            break;

      *-> Edit Distance: CalculateEditDistance: Calculate edit distance between two location names
      -> USING: for(int i=1;i<=n;i++)
                  {
                  for(int j=0;j<=m;j++)
                  {
                        if(j==0)
                        D[i%2][j] = i; 
                  else if(a[j-1] == b[i-1]){
                        D[i%2][j] = D[(i-1)%2][j-1];
                  }
                  else{
                        D[i%2][j]=1 + std::min(D[(i-1)%2][j],std::min(D[i%2][j-1],D[(i-1)%2][j-1]));
                        }
                  }
                  }
                  return D[n%2][m];

    Detailed description of each function and its time complexity.
    Time spent for each function.
    Discussion, conclusion, and lessons learned.
</pr>

<b>Phase 2 submission:</b>


    High-level overview of your design .
<pr>
<b>Phase 2</b>

std::vector<std::string> TrojanMap::DeliveringTrojan(std::vector<std::string> &locations,
                                                     std::vector<std::vector<std::string>> &dependencies){


bool TrojanMap::inSquare(std::string id, std::vector<double> &square)

std::vector<std::string> TrojanMap::GetSubgraph(std::vector<double> &square)

bool TrojanMap::hasCycle(std::string current_id,std::unordered_map<std::string, bool> &visited, std::string parent_id)

bool TrojanMap::CycleDetection(std::vector<std::string> &subgraph, std::vector<double> &square)

void TrojanMap::CreateGraphFromCSVFile()

Given 2 locations A and B on the map, find the best route from A to B.


std::vector<std::string> TrojanMap::CalculateShortestPath_Dijkstra(

std::vector<std::string> TrojanMap::CalculateShortestPath_Bellman_Ford


</pr>

<b>Phase 3 submission:</b>


    High-level overview of your design .
<pr>
<b>Phase 3</b>

  std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_Brute_force(
      std::vector<std::string> location_ids);
  
  std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_Backtracking(
      std::vector<std::string> location_ids);
  
  std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_2opt(
      std::vector<std::string> location_ids);


    2-opt may not always find the best result, and it needs a base case to implement greedy nearest neighbor algorithms.
    2-opt is way faster than the brute force in terms of run time, especially if the input N is greater than 10.
    The time complexity of this function is O(n*x), where x is the times of non_improvments defined by users.

      I randomly selected N points in the map and run the program

  std::vector<std::string> FindNearby std::stringstd::string, double, int);



</pr>

Conclusion

In this project, I constructed a backend map application for users to navigate around the USC campus. I used some basic STL libraries such as queue, array, list, and iterator, etc. I implemented graph search algorithms, classical sorting algorithms, generated reasonable Google unit tests, and further demonstrated the traveling salesperson computation with animations.

Video Demo

## TrojanMap

## Link to Video Presentation: 
https://youtu.be/-G0MUh26K04
## Link to Powerpoint Presentation (with output screenshots and analysis):
https://docs.google.com/presentation/d/1t16SYcLkj1K3Tr0aivf_P7Nl5cnczn5R/edit?userstoinvite=maitreyee0123@gmail.com&actionButton=1#slide=id.p2

This project focuses on using data structures in C++ and implementing various graph algorithms to build a map application.

## The Data Structure

Each point on the map is represented by the class **Node** shown below and defined in [trojanmap.h](src/lib/trojanmap.h).

## PHASE 1

## Pre-requisites Installation

The below packages and libraries were installed on the Ubuntu Operating System:
- OpenCV
- cmake libgtk2.0-dev pkg-config
- libcanberra-gtk3-module
- libncursesw5-dev

## Functions 

## 1. Autocomplete

- Function:

std::vector<std::string> Autocomplete(std::string name);

- Description:
The node names were considered as the locations. A function was implemented to enter the partial name of the location and obtain a list of possible locations with partial name as prefix as the output. The input string was filtered for non-alphabet characters and was converted to lower case prior to performing a substring operation to compare the entered prefix string and obtain all the strings starting with the entered prefix.

- Time Complexity:
The time complexity of this function is O(n), where n is the total number of nodes with a name. The first time that the user executes this function, it will require O(n*) to initialize the hashmap, where n* is the total number of nodes in the map.

- Runtime:
On a Dell Inspiron 15 7000 series laptop with i7 processor, it takes 2 ms to search for "Us".

## 2. Find Position

- Functions:

std::pair<double, double> GetPosition(std::string name);

    Traverse all nodes in the given data until we find the input name. If we find the name, record its latitude and longitude using GetLat() and GetLon(). Else we ouput (-1, -1).
    Time Complexity: O(n), where n is the number of nodes in the give map.

double GetLat(std::string id);

    Given location's id, return its latitude.
    Time Complexity: O(1).

double GetLon(std::string id);

    Given location's id, return its longitude.
    Time Complexity: O(1).

- Description:
The user enters the full name of a location and the program returns the latitude and longitude as the output on the terminal, and also marks the given locations on the popup map window. There are no duplicated location names stored in the map. If the location does not exist, then the output is no result match on the terminal.

- Time Complexity:
The time complexity of this function is O(n). The first time that the user executes this function, it will require O(n*) to initialize the hashmap, where n* is the total number of nodes in the map.

- Runtime:
On a Dell Inspiron 15 7000 series laptop with i7 processor, it takes 1 ms to search for "USC Village Gym".

## PHASE 2

## 3. Calculate Shortest Path Between Two Places

- Functions:

std::vector<std::string> CalculateShortestPath_Dijkstra(std::string &location1_name,
                                               std::string &location2_name);

    Each time we add the nearest unvisited location into the set of visited locations. Update shortest distance of this location’s neighbors and its predecessor map. This continues until the location is the destination. It traverses the predecessor map and output is the shortest path. If we traverse neighbors that we can obtain and do not meet the destination, that means the start node cannot arrive at the destination. In this case, we return an empty path.
    Time Complexity: O(n^2), where n is the number of nodes in the given map.

std::vector<std::string> CalculateShortestPath_Bellman_Ford(std::string &location1_name,
                                               std::string &location2_name);

    Each time update the shortest distance and the predecessor map by adding the intermediate edge by one. This contiinues until we traverse all nodes. If the destination has been updated, we traverse the predecessor map and output is the shortest path, else it means the start point cannot arrive at the destination and we return an empty path.
    Time Complexity: O(n + m), where n is the number of nodes, m is the number of edges in the given map.

std::vector<std::string> GetNeighborIDs(std::string id);

    Given the location's name, return its neighbors.
    Time Complexity: O(1).

- Description:
User types in two locations A and B, the program returns the best route from A to B on the terminal and shows the path on the popup map window. The distance between 2 points is the euclidean distance using latitude and longitude. User can choose to use Dijkstra algorithm or Bellman-Ford algorithm. If there is no path, it returns an empty vector.

- Time Complexity:
For Dijkstra: The function use minheap to implement Dijkstra algorithm. The time complexity of this function is O(n^2), n is the total number of nodes.
For Bellman-Ford: The time complexity of this function is O(n + m), where m is the total number of edges in the map and n is the total number of nodes.

- Runtime:
On a Dell Inspiron 15 7000 series laptop with i7 processor:
Dijkstra takes 60 ms to search for the shortest path from Ralphs to Trader Joe's.
Bellman-Ford takes 6232 ms to search for the shortest path from Ralphs to Trader Joe's.

## 4. Travelling Trojan (TSP)

- Functions:

void TrojanMap::TSP_helper(std::vector<std::vector<double>> &weights, std::vector<std::string> &location_ids,
    std::vector<std::vector<std::string>> &path, double &min_dist,
    std::vector<int> &current_path, double curr_dist, std::unordered_set<int> &seen, bool bruteforce);

    DFS algorithm to find the minimum cost given the start location.
    Time Complexity: O(n!), where n is the number of locations.

std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_Brute_force(std::vector<std::string> &location_ids);

    We create an adjacent matrix with rows and columns to be locations reindexed. We try all permutations of the path and find the minimum cost. For each time when we get a better path, we push back this path to our final result. It returns  the minimum cost and the result vector.
    Time Complexity: O(n!), where n is the number of nodes in the input.
    Runtime: 59 ms

std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_Backtracking(std::vector<std::string> location_ids);

    We create an adjacent matrix with rows and columns to be locations reindexed. We implement DFS to try all permutations of the path and find the minimum cost. For each time when we get a better path, we push back this path to our final result. It returns the minimum cost and the result vector.
    Time Complexity: O(n!), where n is the number of nodes in the input.
    Runtime: 20 ms

std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_2opt(std::vector<std::string> &location_ids);

    We use two for loops to obtain a sub part in the location ids vector and reverse this sub part. If the updated vector's path length is smaller, we update things similar to Brute Force and go back to start again. This is repeated until no improvement is made.
    Time Complexity: O(n^2), where n is the number of locations.
    Runtime: 0 ms

## 5. Cycle Detection

- Functions:

bool CycleDetection(std::vector<std::string> &subgraph, std::vector<double> &square);

    We create a map named visited that has all nodes in the given area and another map named predecessor of the child node and its parent node. We traverse all nodes in the visited map and check if a cycle is formed or not. The result is returned as a boolean value, true or false.
    Time Complexity: O(n + m), where n is the number of nodes in the map and m is the number of edges in the given area.

bool TrojanMap::CycleDetection_Helper(std::string current_id, std::unordered_map<std::string, bool> &visited, std::string parent_id, std::vector<double> &square, std::unordered_map<std::string, std::vector<std::string>> &predecessors, std::vector<std::string> &cycle_path);

    We mark the current node as true in the visited map. We traverse the curent node's neighbouring nodes and record the current node as predecessor node of the neighbouring nodes. If the neighbour is in the area and it has not been visited, we use recursion. If the neighbor is in the area and it has been visited and it is not the parent node, that means there exists a cycle, then we return true, Else we return false.
    Time Complexity: O(n + m), where n is the number of nodes in the given area, m is the number of edges in the given area.

- Description:
The user types in four geographical parameters to form a square-shaped region in the map, then the program detects if there is a cycle in the given region or not and shows the result in the terminal.

- Time Complexity:
The time complexity of this function is O(n + m), where m is the total number of edges in the given region and n is the total number of nodes in the map.

- Runtime:
On a Dell Inspiron 15 7000 series laptop with i7 processor, the function takes 0 ms to search for the region {-118.290919, -118.282911, 34.02235, 34.019675}.

## 6. Topological Sort

- Functions:

void TrojanMap::TopologicalSort_helper(std::string &loc, std::unordered_map<std::string, std::vector<std::string>> &dependency, std::unordered_map<std::string, bool> &visited, std::vector<std::string> &res);

std::vector<std::string> DeliveringTrojan(std::vector<std::string> &locations, std::vector<std::vector<std::string>> &dependencies);

    The input is a set of locations and corresponding dependencies and the output is a topological sorted path. This program can visualize the results on the map and is implemented using double-ended queue DFS. It will plot each location name and also some arrowed lines to demonstrate a feasible route.

- Time Complexity:
The time complexity of this function is O(n + m), where m is the total number of edges in the given files and n is the total number of nodes in the given files.

- Runtime:
On a Dell Inspiron 15 7000 series laptop with i7 processor, the function takes 2 ms to search for the input files.

## 7. Find Nearby

- Function:

std::vector<std::string> TrojanMap::FindNearby(std::string attributesName, std::string name, double r, int k);

    Given an attribute name C, a location name L and a number r and k, we find at most k locations in attribute C on the map near L (not including L) within the range of r and return a vector of string ids. The order of locations is from the nearest to the farthest.

- Time Complexity: 
The time complexity of this function is O(n^2), where n is the total number of nodes given.

- Runtime:
On a Dell Inspiron 15 7000 series laptop with i7 processor, the function takes 5 ms.

## Runtime of all implemented functionalities

Autocomplete:                   O(n)
Finding the Position:           O(n)
Calculate the Shortest Path: 
Dijkstra:                       O(n^2)
Bellman Ford:                   O(n*m)
Travelling Trojan (TSP)
Brute Force:                    O(n!)
Backtracking:                   O(n!)
2 - Opt:                        O(n^2)
Cycle Detection:                O(n+m)
Topological Sort:               O(n+m)
Find Nearby:                    O(n^2)

where, n: Number of nodes in the map, m: Number of edges in the map

## Inferences

- Shortest Path: The runtime is higher for Bellman Ford than Dijkstra. Therefore, Dijkstra is a better choice for computing the shortest path in the Trojan Map application.

- Google Maps: The output map path of the Shortest Path algorithms was compared with that of Google Maps for the same pair of locations and was found to be the same.

- TSP: The runtime is the least for 2-opt, higher than that for Backtracking and is the highest for Brute Force. Therefore, the 2-opt approach is the best suited algorithm for a large number of nodes.

- DFS: Depth First Search is the algorithm that was the basis for many applications implemented in this project, including Travelling Salesperson, Cycle Detection and Topological Sort.


## Conclusion: 

- Usage of different data structures can improve the efficiency of the program while also reducing the runtime.

- This project provided an opportunity to learn and practice many important data structures and graph algorithms in software programming, including DFS, Bellman Ford, Dijkstra and recursive algorithms.

- The project also enabled to learn the skill of designing algorithms and debugging the program codes using unit testing.

- The future scope of this project:
    - Implementing 3-opt approach for the Travelling Salesperson problem
    - Broadening the scope of the map to cover a larger geographical area
    - Improving the efficiency of the implemented algorithms

