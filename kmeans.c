#include <parallel_distance.h>
#include <stdio.h>

int main() {
  struct Point x = {.x=1, .y=2};
  struct Point y = {.x=0, .y=1};
  struct Point z[] = {x, y};
  double w[2];
  distanceSquareds(x, z, 2, w);
  for (int i = 0; i < 2; ++i)
    printf("%d: %f\n", i, w[i]);
  /* printf("%lf\n", distanceSquared(x, y)); */
}
