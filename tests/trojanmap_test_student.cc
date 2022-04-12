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
