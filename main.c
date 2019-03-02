#include <stdio.h>

#include <parallel_distance.h>

int main() {
   Point a = {.x_ = 0, .y_ = 0};
   Point b = {.x_ = 0, .y_ = 1};
   Point c = {.x_ = 0, .y_ = 2};
   Point d = {.x_ = 0, .y_ = 3};
   Point e = {.x_ = 0, .y_ = 4};
   Point f = {.x_ = 0, .y_ = 5};
   Point g = {.x_ = 0, .y_ = 6};
   Point h = {.x_ = 0, .y_ = 7};
   Point i = {.x_ = 0, .y_ = 8};

   Point o = {.x_ = 0, .y_ = 0};

   Point z[] = {a, b, c, d, e, f, g, h, i};
  double w[9];
  distanceSquareds(o, z, 9, w);
  for (int i = 0; i < 9; ++i)
    printf("%d: %f\n", i, w[i]);
  printf("nthreads: %d\n", NTHREADS);
}
