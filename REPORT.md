<b>HI, this is Rudrax Dave : Doing the Project Alone: If you find any other with the same situation let me know and will contact him/her to be added to the project group.</b>

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

