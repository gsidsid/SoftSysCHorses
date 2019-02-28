#include <parallel_distance.h>
#include <stdio.h>

int main() {
  struct Point x = {.x_=1, .y_=2};
  struct Point y = {.x_=0, .y_=1};
  struct Point o = {.x_=0, .y_=0};
  struct Point z[] = {x, y};
  double w[2];
  distanceSquareds(o, z, 2, w);
  for (int i = 0; i < 2; ++i)
    printf("%d: %f\n", i, w[i]);
  /* printf("%lf\n", distanceSquared(x, y)); */
}
