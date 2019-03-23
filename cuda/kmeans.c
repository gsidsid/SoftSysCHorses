#include <stdlib.h>
#include <string.h>

#include <single_threaded_distance.h>
#include <point.h>

#include "kmeans.h"

void kmeans_iteration(Point *points, Point *centers, int num_pts,
                      int num_centers) {
  double distances[num_centers][num_pts];

  // Compute distances of all points from all centers
  for (int i = 0; i < num_centers; ++i)
    distanceSquareds(centers[i], points, num_pts, distances[i]);

  // Store the index of the closest center to all points
  int min_idxs[num_pts];

  for (int i = 0; i < num_pts; ++i) {
    min_idxs[i] = 0;
    for (int j = 1; j < num_centers; ++j)
      if (distances[min_idxs[i]][i] > distances[j][i])
        min_idxs[i] = j;
  }

  int cluster_size[num_centers];
  Point cluster_total[num_centers];

  // Initialize arrays as 0;
  for (int i = 0; i < num_centers; ++i) {
    cluster_size[i] = 0;
    Point tmp = {0};
    cluster_total[i] = tmp;
  }

  // Add up the points in each cluster
  for (int i = 0; i < num_pts; ++i) {
    cluster_size[min_idxs[i]]++;
    cluster_total[min_idxs[i]] =
        add_point_point(cluster_total[min_idxs[i]], points[i]);
  }

  // Average the points in each cluster
  for (int i = 0; i < num_centers; ++i)
    if (cluster_size[i] != 0)
      centers[i] = divide_point_int(cluster_total[i], cluster_size[i]);
}

Point *kmeans(Point *points, int num_pts, int num_centers) {
  Point *centers = malloc(sizeof(Point) * num_centers);
  memcpy(centers, points, sizeof(Point) * num_centers);

  Point centers_prev[num_centers];
  memcpy(centers_prev, points, sizeof(Point) * num_centers);

  double center_change;

  do {
    kmeans_iteration(points, centers, num_pts, num_centers);
    center_change = 0;

    for (int i = 0; i < num_centers; ++i)
      center_change += distanceSquared(centers[i], centers_prev[i]);

    memcpy(centers_prev, centers, sizeof(Point) * num_centers);
  } while (center_change > 1e-8);

  return centers;
}
