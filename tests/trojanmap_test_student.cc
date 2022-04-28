#include "gtest/gtest.h"
#include "src/lib/trojanmap.h"


TEST(TrojanMapTest, TEST1) {
  TrojanMap m;
  
  auto names = m.Autocomplete("Sh");
  std::unordered_set<std::string> gt = {"Shall Gas", "Shell"}; 
  int success = 0;
  for (auto& n: names) {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0){
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
  
  names = m.Autocomplete("sh");
  success = 0;
  for (auto& n: names) {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0){
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
  
  names = m.Autocomplete("sH"); 
  success = 0;
  for (auto& n: names) {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0){
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
  
  names = m.Autocomplete("SH"); 
  success = 0;
  for (auto& n: names) {
    EXPECT_EQ(gt.count(n) > 0, true) << n + " is not in gt.";
    if (gt.count(n) > 0){
      success++;
    }
  }
  EXPECT_EQ(success, gt.size());
}

TEST(TrojanMapStudentTest, TEST2) {
  TrojanMap m;
  

  auto position = m.GetPosition("The Sonshine Shop Thrift Store");
  std::pair<double, double> gt1(34.0383026, -118.2917671);
  std::cout<<position.second<<std::endl;
  EXPECT_EQ(position, gt1);

  position = m.GetPosition("Just Ride LA");
  std::pair<double, double> gt2(34.0339943, -118.2648737);
  EXPECT_EQ(position, gt2);

  position = m.GetPosition("Ralphs");
  std::pair<double, double> gt3(34.0317653, -118.2908339);
  EXPECT_EQ(position, gt3);

  position = m.GetPosition("CVS Pharmacy");
  std::pair<double, double> gt4(34.0234847, -118.2793109);
  EXPECT_EQ(position, gt4);

  position = m.GetPosition("IndiaSpices");
  std::pair<double, double> gt5(-1, -1);
  EXPECT_EQ(position, gt5);
}


TEST(TrojanMapTest, Test3) {
  TrojanMap m;
  EXPECT_EQ(m.CalculateEditDistance("horse", "ros"), 3);
  EXPECT_EQ(m.CalculateEditDistance("cat", "cut"), 1);
  EXPECT_EQ(m.CalculateEditDistance("sunday", "saturday"), 3);
}


TEST(TrojanMapTest, Test4) {
  TrojanMap m;
  
  std::string r1 = "Starbucks";
  EXPECT_EQ(m.FindClosestName("Storbucks"), r1);
  EXPECT_EQ(m.FindClosestName("Stooooorbucks"), r1);
  EXPECT_EQ(m.FindClosestName(" Storrrrrrrbucks"), r1);

  std::string r3 = "CAVA";
  EXPECT_EQ(m.FindClosestName("CAVAS"), r3);

  std::string r2 = "Chevron";
  EXPECT_EQ(m.FindClosestName("Chevrrron"), r2);


}

// Phase 2
// Test CalculateShortestPath_Dijkstra function
TEST(TrojanMapTest, TESTDijkstra) {
  TrojanMap m;
  
  // Test from Ralphs to Chick-fil-A
  auto path = m.CalculateShortestPath_Dijkstra("Ralphs", "Chick-fil-A");
  std::vector<std::string> gt{
      "2578244375","4380040154","4380040153","4380040152","4380040148","6818427920","6818427919",
      "6818427918","6818427892","6818427898","6818427917","6818427916","7232024780","6813416145",
      "6813416154","6813416153","6813416152","6813416151","6813416155","6808069740","6816193785",
      "6816193786","123152294","4015203136","4015203134","4015203133","21098539","6389467809",
      "4015203132","3195897587","4015203129","4015203127","6352865690","6813379589","6813379483",
      "3402887081","6814958394","3402887080","602606656","4872897515","4399697589","6814958391",
      "123209598","6787673296","122728406","6807762271","4399697304","4399697302","5231967015",
      "1862347583","3233702827","4540763379","6819179753","6820935900","6820935901","6813379556",
      "6820935898","1781230450","1781230449","4015405542","4015405543","1837212104","1837212107",
      "2753199985","6820935907","1837212100","4015372458","6813411588","1837212101","6814916516",
      "6814916515","6820935910","4547476733"}; // Expected path
  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
  
  // Reverse the input from Ralphs to Chick-fil-A
  path = m.CalculateShortestPath_Dijkstra("Chick-fil-A", "Ralphs");
  std::reverse(gt.begin(),gt.end()); // Reverse the path

  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
}

TEST(TrojanMapStudentTest, TESTDijkstra2) {
  TrojanMap m;
  
  // Test from KFC to Ralphs
  auto path = m.CalculateShortestPath_Dijkstra("KFC", "Ralphs");
  std::vector<std::string> gt{"3088547686","4835551100","4835551097","4835551101","4835551096","2613117890","6807554573","6787803640","7298150111","7477947679","6813416163","122814440","7200139036","7882624618","6813416166","6807536642","6807320427","6807536647","6813416171","6813416123","3398621888","6804883324","5690152756","6816193695","3398621887","3398621886","6816193694","6816193693","6816193692","4015442011","6787470576","6816193770","123230412","452688931","452688933","6816193774","123408705","6816193777","452688940","123318563","6813416129","6813416130","7645318201","6813416131","8410938469","6805802087","4380040167","4380040158","4380040154","2578244375"}; // Expected path
  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
  
  // Reverse the input from Ralphs to KFC
  path = m.CalculateShortestPath_Dijkstra("Ralphs", "KFC");
  std::reverse(gt.begin(),gt.end()); // Reverse the path

  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
}


// // Test CalculateShortestPath_Bellman_Ford function
TEST(TrojanMapTest, TESTBellman_Ford) {
  TrojanMap m;
  
  // Test from Ralphs to Chick-fil-A
  auto path = m.CalculateShortestPath_Bellman_Ford("Ralphs", "Chick-fil-A");
  std::vector<std::string> gt{
      "2578244375","4380040154","4380040153","4380040152","4380040148","6818427920","6818427919",
      "6818427918","6818427892","6818427898","6818427917","6818427916","7232024780","6813416145",
      "6813416154","6813416153","6813416152","6813416151","6813416155","6808069740","6816193785",
      "6816193786","123152294","4015203136","4015203134","4015203133","21098539","6389467809",
      "4015203132","3195897587","4015203129","4015203127","6352865690","6813379589","6813379483",
      "3402887081","6814958394","3402887080","602606656","4872897515","4399697589","6814958391",
      "123209598","6787673296","122728406","6807762271","4399697304","4399697302","5231967015",
      "1862347583","3233702827","4540763379","6819179753","6820935900","6820935901","6813379556",
      "6820935898","1781230450","1781230449","4015405542","4015405543","1837212104","1837212107",
      "2753199985","6820935907","1837212100","4015372458","6813411588","1837212101","6814916516",
      "6814916515","6820935910","4547476733"}; // Expected path
  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
  
  // Reverse the input from Ralphs to Chick-fil-A
  path = m.CalculateShortestPath_Bellman_Ford("Chick-fil-A", "Ralphs");
  std::reverse(gt.begin(),gt.end()); // Reverse the path

  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
}

// Test CalculateShortestPath_Bellman_Ford function
TEST(TrojanMapStudentTest, TESTBellman_Ford2) {
  TrojanMap m;
  
  // Test from KFC to Ralphs
  auto path = m.CalculateShortestPath_Bellman_Ford("KFC", "Ralphs");
  std::vector<std::string> gt{
      "3088547686","4835551100","4835551097","4835551101","4835551096","2613117890","6807554573","6787803640","7298150111","7477947679","6813416163","122814440","7200139036","7882624618","6813416166","6807536642","6807320427","6807536647","6813416171","6813416123","3398621888","6804883324","5690152756","6816193695","3398621887","3398621886","6816193694","6816193693","6816193692","4015442011","6787470576","6816193770","123230412","452688931","452688933","6816193774","123408705","6816193777","452688940","123318563","6813416129","6813416130","7645318201","6813416131","8410938469","6805802087","4380040167","4380040158","4380040154","2578244375"}; // Expected path
  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
  
  // Reverse the input from Ralphs to KFC
  path = m.CalculateShortestPath_Bellman_Ford("Ralphs", "KFC");
  std::reverse(gt.begin(),gt.end()); // Reverse the path

  // Print the path lengths
  std::cout << "My path length: "  << m.CalculatePathLength(path) << "miles" << std::endl;
  std::cout << "GT path length: " << m.CalculatePathLength(gt) << "miles" << std::endl;
  EXPECT_EQ(path, gt);
}


// Test cycle detection function
TEST(TrojanMapTest, TESTCycle) {
  TrojanMap m;
  
  std::vector<double> square1 = {-118.299, -118.264, 34.032, 34.011};
  auto sub1 = m.GetSubgraph(square1);
  bool result1 = m.CycleDetection(sub1, square1);
  EXPECT_EQ(result1, true);


  std::vector<double> square4 = {-118.320, -118.290, 34.030, 34.030};
  auto sub4 = m.GetSubgraph(square4);
  bool result2 = m.CycleDetection(sub4, square4);
  EXPECT_FALSE(result2);

}



// // Test cycle detection function
TEST(TrojanMapTest, TESTTopoSort) {
  TrojanMap m;
  
  //Case 1: Using input vector
  std::vector<std::string> location_names = {"Ralphs", "Chick-fil-A", "KFC"};
  std::vector<std::vector<std::string>> dependencies = {{"Ralphs","KFC"}, {"Ralphs","Chick-fil-A"}, {"KFC","Chick-fil-A"}};
  auto result = m.DeliveringTrojan(location_names, dependencies);
  std::vector<std::string> gt ={"Ralphs", "KFC","Chick-fil-A"};
  EXPECT_EQ(result, gt);

  //Case 2: Read input from csv file
  // std::string base_path = "/home/rudrax/TrojanMap/final-project-RudraxDave";
  // std::string dependencies_filename = base_path + "/input/topologicalsort_dependencies.csv";
  // std::string locations_filename = base_path + "/input/topologicalsort_locations.csv";
  // location_names = m.ReadLocationsFromCSVFile(locations_filename);
  // dependencies = m.ReadDependenciesFromCSVFile(dependencies_filename);
  // result = m.DeliveringTrojan(location_names, dependencies);
  // gt ={"Target","Ralphs","Chick-fil-A","Chipotle","KFC"};
  // EXPECT_EQ(result, gt);
}

// Ralphs
// KFC
// Chick-fil-A

// Source, Destination
// Ralphs,Chick-fil-A
// Ralphs,KFC
// Chick-fil-A,KFC