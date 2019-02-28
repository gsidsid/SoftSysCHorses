struct Point {
  double x_;
  double y_;
};

struct ThreadArgs {
  int num_pts_;
  int base_sz_;
  struct Point origin_;
  struct Point *points_;
  double *distances_;
  int part_;
};

/**
 * Calculate the squared distance between two points.
 *
 * @param a the first point.
 * @param b the second point.
 * @return the squared distance between the two points.
 * */
double distanceSquared(struct Point a, struct Point b);

/**
 * Function that gets passed to pthread_create.
 *
 * @param args n
 */
void *calc_distances_thread(void *arg);
void distanceSquareds(struct Point origin, struct Point points[], int num_pts, double distances[]);
