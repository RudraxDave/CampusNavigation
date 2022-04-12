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