#include "point.h"
#include <math.h>

#include "gpu_distance.h"
#include "hemi/parallel_for.h"

using namespace hemi;

void distanceSquareds(const Point origin, const Point *points,
                      const int num_pts, double *distances) {
    parallel_for(0, num_pts, [distances,origin,points] HEMI_LAMBDA (int i) {
        distances[i] = pow(origin.x_ - points[i].x_, 2) + pow(origin.y_ - points[i].y_, 2);
    });
    deviceSynchronize();
}
