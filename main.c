#include <stdio.h>

#include <parallel_distance.h>

int main() {
  struct Point a = {.x_ = 0, .y_ = 0};
  struct Point b = {.x_ = 0, .y_ = 1};
  struct Point c = {.x_ = 0, .y_ = 2};
  struct Point d = {.x_ = 0, .y_ = 3};
  struct Point e = {.x_ = 0, .y_ = 4};
  struct Point f = {.x_ = 0, .y_ = 5};
  struct Point g = {.x_ = 0, .y_ = 6};
  struct Point h = {.x_ = 0, .y_ = 7};
  struct Point i = {.x_ = 0, .y_ = 8};

  struct Point o = {.x_ = 0, .y_ = 0};

  struct Point z[] = {a, b, c, d, e, f, g, h, i};
  double w[9];
  distanceSquareds(o, z, 9, w);
  for (int i = 0; i < 9; ++i)
    printf("%d: %f\n", i, w[i]);
  printf("nthreads: %d\n", NTHREADS);
}
