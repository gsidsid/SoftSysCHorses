#include "point.h"

#include "single_threaded_distance.h"
#include "hemi/parallel_for.h"

using namespace hemi;

__host__ __device__ void distanceSquareds(const Point origin, const Point *points,
                                          const int num_pts, double *distances) {
    parallel_for(0, num_pts, [distances,origin,points] HEMI_LAMBDA (int i) {
        distances[i] = distanceSquared(origin, points[i]);
    });
    deviceSynchronize();
}
