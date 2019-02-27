#include <pthread.h>

#include "math.h"
#include "parallel_distance.h"

#define NTHREADS 8

double normSquared(struct Point point) {
  return pow(point.x, 2) + pow(point.y, 2);
}

void distanceSquareds(struct Point points[], int num_pts, double distances[]) {
  pthread_t threads[NTHREADS];
  int thread_args[NTHREADS];

  for (int i = 0; i < num_pts; ++i) {
    distances[i] = normSquared(points[i]);
  }
}
