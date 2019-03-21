#include <point.h>

#include "single_threaded_distance.h"

void distanceSquareds(const Point origin, const Point *points,
                      const int num_pts, double *distances) {

  for (int i = 0; i < num_pts; ++i)
    distances[i] = distanceSquared(origin, points[i]);
}
