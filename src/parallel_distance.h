#include <semaphore.h>

struct Point {
  double x_;
  double y_;
};

struct ThreadArgs {
  int num_pts_;
  int base_sz_;
  int rem_;
  struct Point origin_;
  struct Point *points_;
  double *distances_;
  int part_;
  sem_t *mutex;
};

/**
 * Calculate the squared distance between two points.
 *
 * @param a the first point.
 * @param b the second point.
 * @return the squared distance between the two points.
 */

double distanceSquared(const struct Point a, const struct Point b);

/**
 * Function that gets passed to pthread_create.
 *
 * @param args a pointer to the internal function arguments.
 * @return pointer to exit status
 */
void *calc_distances_thread(void *arg);

/**
 * Calculate the distance between a group of points and an origin.
 *
 * @param origin the origin used to calculate vector length.
 * @param points the points with which to compute norms.
 * @param num_pts the amount of points to calculate the distance to.
 * @param distances the buffer to put the acquired distances into.
 * The order of distances which populate the buffer will be respective to the
 * order of the order of the input points.
 */
void distanceSquareds(const struct Point origin, const struct Point *points,
                      const int num_pts, double *distances);
