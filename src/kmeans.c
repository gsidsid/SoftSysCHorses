#include <stdlib.h>

#include <parallel_distance.h>

struct KMeansArgs {
  struct Point *points_;
  struct Point *centers_;
  int num_pts_;
  int num_centers_;
};

struct Point add_point(const struct Point a, const struct Point b) {
  struct Point c = {.x_ = a.x_ + b.x_, .y_ = a.y_ + b.y_};
  return c;
}

void kmeans_iteration(struct KMeansArgs kmeans_args) {
  double distances[kmeans_args.num_centers_][kmeans_args.num_pts_];

  for (int i = 0; i < kmeans_args.num_centers_; ++i)
    distanceSquareds(kmeans_args.centers_[i], kmeans_args.points_,
                     kmeans_args.num_pts_, distances[i]);

  int min_idxs[kmeans_args.num_pts_];

  for (int i = 0; i < kmeans_args.num_pts_; ++i) {
    min_idxs[i] = 0;
    for (int j = 1; j < kmeans_args.num_centers_; ++j)
      if (distances[min_idxs[i]][i] > distances[j][i])
        min_idxs[i] = j;
  }
}
