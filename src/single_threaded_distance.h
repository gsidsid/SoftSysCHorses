#pragma once

#include <point.h>

/**
   Calculate the distance between a group of points and an origin.

   @param origin the origin used to calculate vector length.
   @param points the points with which to compute norms.
   @param num_pts the amount of points to calculate the distance to.
   @param distances the buffer to put the acquired distances into.
   The order of distances which populate the buffer will be respective
   to the order of the order of the input points.
 */
void distanceSquareds(const Point origin, const Point *points,
                      const int num_pts, double *distances);
