#include <stdio.h>

#include <kmeans.h>
#include <parallel_distance.h>

int main() {
  Point a, b, c, d, e, f, g, h;
  a.x_ = 0;
  a.y_ = 0;
  b.x_ = 1;
  b.y_ = 0;
  c.x_ = 2;
  c.y_ = 0;
  d.x_ = 3;
  d.y_ = 0;
  e.x_ = 10;
  e.y_ = 0;
  f.x_ = 11;
  f.y_ = 0;
  g.x_ = 12;
  g.y_ = 0;
  h.x_ = 13;
  h.y_ = 0;

  Point points[] = {a, b, c, d, e, f, g, h};
  Point *centers = kmeans(points, 8, 2);

  for (int i = 0; i < 2; ++i)
    printf("Final center %lu %d: %f, %f\n", sizeof(Point), i, centers[i].x_,
           centers[i].y_);
}
