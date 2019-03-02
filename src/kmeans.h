#include <parallel_distance.h>
#include <point.h>

/**
   Updates the location of the centers of clusters.

   @param points the points to divide into clusters
   @param centers the current guess of where the centers of the
   clusters are. The guess is updated in this function.
   @param num_pts the amount of points
   @param num_centers the amount of clusters.
 */
void kmeans_iteration(Point *points, Point *centers, int num_pts,
                      int num_centers);

Point *kmeans(Point *points, int num_pts, int num_centers);
