#include <stdlib.h>
#include <string.h>

#include <parallel_distance.h>
#include <point.h>

#include "kmeans.h"

void kmeans_iteration(Point *points, Point *centers, int num_pts,
                      int num_centers) {
  double distances[num_centers][num_pts];

  for (int i = 0; i < num_centers; ++i)
    distanceSquareds(centers[i], points, num_pts, distances[i]);

  int min_idxs[num_pts];

  for (int i = 0; i < num_pts; ++i) {
    min_idxs[i] = 0;
    for (int j = 1; j < num_centers; ++j)
      if (distances[min_idxs[i]][i] > distances[j][i])
        min_idxs[i] = j;
  }

  int cluster_size[num_centers];
  Point cluster_total[num_centers];

  for (int i = 0; i < num_pts; ++i) {
    cluster_size[i] = 0;
    Point tmp = {0};
    cluster_total[i] = tmp;
  }

  for (int i = 0; i < num_pts; ++i) {
    cluster_size[min_idxs[i]]++;
    cluster_total[min_idxs[i]] =
        add_point_point(cluster_total[min_idxs[i]], points[i]);
  }

  for (int i = 0; i < num_centers; ++i)
    centers[i] = divide_point_int(cluster_total[i], cluster_size[i]);
}

Point *kmeans(Point *points, int num_pts, int num_centers) {
  Point *centers_a = malloc(sizeof(Point) * num_centers);
  memcpy(centers_a, points, sizeof(Point) * num_centers);

  Point centers_b[num_centers];
  kmeans_iteration(points, centers_b, num_pts, num_centers);

  int current_center = 0;
  int center_change;

  do {
    if (current_center)
      kmeans_iteration(points, centers_b, num_pts, num_centers);
    else
      kmeans_iteration(points, centers_a, num_pts, num_centers);

    current_center = current_center ? 0 : 1;

    center_change = 0;

    for (int i = 0; i < num_centers; ++i)
      center_change += distanceSquared(centers_a[i], centers_b[i]);

  } while (center_change < 0.1);

  return centers_a;
}
