#include <pthread.h>
#include <math.h>

#include "parallel_distance.h"

#define NTHREADS 8

double normSquared(struct Point point) {
  return pow(point.x, 2) + pow(point.y, 2);
}

double distanceSquared(struct Point a, struct Point b) {
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

void distanceSquareds(struct Point origin, struct Point points[], int num_pts, double* distances) {
  for (int i = 0; i < num_pts; ++i)
    distances[i] = distanceSquared(origin, points[i]);
}
