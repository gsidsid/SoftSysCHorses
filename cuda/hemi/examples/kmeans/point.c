#include <math.h>

#include "point.h"

Point add_point_point(const Point a, const Point b) {
  Point c = {.x_ = a.x_ + b.x_, .y_ = a.y_ + b.y_};
  return c;
}

Point divide_point_int(const Point a, const int b) {
  Point c = {.x_ = a.x_ / b, .y_ = a.y_ / b};
  return c;
}
