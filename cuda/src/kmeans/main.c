#include <stdio.h>

#include "kmeans.h"
#include "single_threaded_distance.h"

int main() {
  Point a = {.x_ = 0, .y_ = 0};
  Point b = {.x_ = 1, .y_ = 0};
  Point c = {.x_ = 2, .y_ = 0};
  Point d = {.x_ = 3, .y_ = 0};
  Point e = {.x_ = 10, .y_ = 0};
  Point f = {.x_ = 11, .y_ = 0};
  Point g = {.x_ = 12, .y_ = 0};
  Point h = {.x_ = 13, .y_ = 0};

  Point points[] = {a, b, c, d, e, f, g, h};
  Point *centers = kmeans(points, 8, 2);


  for (int i = 0; i < 2; ++i)
    printf("Final center %lu %d: %f, %f\n", sizeof(Point), i, centers[i].x_, centers[i].y_);
}
