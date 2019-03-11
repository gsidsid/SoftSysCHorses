#include <gtest/gtest.h>
extern "C" {
#include <kmeans.h>
#include <parallel_distance.h>
}

TEST(DistanceTest, POSITIVE) {
  Point a = {.x_ = 0, .y_ = 1};
  Point b = {.x_ = 0, .y_ = 2};
  EXPECT_EQ(1, distanceSquared(a, b));
}

TEST(ParallelDistanceTest, POSITIVE) {
  Point a = {.x_ = 5, .y_ = 5};
  Point b = {.x_ = 5, .y_ = 11};
  Point c = {.x_ = 5, .y_ = -1};
  Point d = {.x_ = 11, .y_ = 5};
  Point e = {.x_ = -1, .y_ = 5};
  Point f = {.x_ = -1, .y_ = -1};

  double distances[6];
  double expected[] = {0, 36, 36, 36, 36, 72};
  Point pts[] = {a, b, c, d, e, f};
  distanceSquareds(a, pts, 6, distances);

  for (int i = 0; i < 6; ++i)
    EXPECT_EQ(distances[i], expected[i]);
}

TEST(KMeansTest, POSITIVE) {
  Point a = {.x_ = -1, .y_ = -2};
  Point b = {.x_ = -3, .y_ = -2};
  Point c = {.x_ = -1, .y_ = -4};
  Point d = {.x_ = -3, .y_ = -4};
  Point e = {.x_ = 10, .y_ = 5};
  Point f = {.x_ = 10, .y_ = 7};
  Point g = {.x_ = 6, .y_ = 5};
  Point h = {.x_ = 6, .y_ = 7};

  Point points[] = {a, b, c, d, e, f, g, h};
  Point *centers = kmeans(points, 8, 2);

  Point expected_center_a = {.x_ = -2, .y_ = -3};
  Point expected_center_b = {.x_ = 8, .y_ = 6};

  bool equality_1 = expected_center_a.x_ == centers[0].x_ &&
                    expected_center_a.y_ == centers[0].y_ &&
                    expected_center_b.x_ == centers[1].x_ &&
                    expected_center_b.y_ == centers[1].y_;

  bool equality_2 = expected_center_a.x_ == centers[1].x_ &&
                    expected_center_a.y_ == centers[1].y_ &&
                    expected_center_b.x_ == centers[0].x_ &&
                    expected_center_b.y_ == centers[0].y_;

  ASSERT_TRUE(equality_1 || equality_2);
}
