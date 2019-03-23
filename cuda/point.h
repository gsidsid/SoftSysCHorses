#pragma once

typedef struct {
  double x_;
  double y_;
} Point;

/**
  Calculate the squared distance between two points.

  @param a the first point.
  @param b the second point.
  @return the squared distance between the two points.
 */
double distanceSquared(const Point a, const Point b);

/**
   Vector sum of two points.

   @param a the first point
   @param b the second point
   @return the vector sum of two points
 */
Point add_point_point(const Point a, const Point b);

/**
   Scalar division of a point by an int.

   @param a the point
   @param b the number
   @param c the scalar division point / number.
 */
Point divide_point_int(const Point a, const int b);
