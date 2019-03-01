#include <gtest/gtest.h>
extern "C" {
#include <parallel_distance.h>
}

TEST(DistanceTest, POSITIVE) {
  struct Point a = {.x_ = 0, .y_ = 1};
  struct Point b = {.x_ = 0, .y_ = 2};
  EXPECT_EQ(1, distanceSquared(a, b));
}
