#include "parallel_distance.h"
#include "math.h"

double normSquared(struct Point point) {
  return pow(point.x, 2) + pow(point.y, 2);
}

void distanceSquareds(struct Point points[], int num_pts, double distances[]) {
  for (int i = 0; i < num_pts; ++i) {
    distances[i] = normSquared(points[i]);
  }
}
