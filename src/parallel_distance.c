#include <math.h>
#include <pthread.h>
#include <stdlib.h>

#include "parallel_distance.h"

#define NTHREADS 8

double distanceSquared(struct Point a, struct Point b) {
  return pow(a.x_ - b.x_, 2) + pow(a.y_ - b.y_, 2);
}

void *calc_distances_thraed(void *arg) {
  struct ThreadArgs *thread_args = (struct ThreadArgs *)arg;
  if (thread_args->part_ < NTHREADS - 1)
    for (int i = 0; i < thread_args->base_sz_; ++i) {
      int idx = i + thread_args->part_ * thread_args->base_sz_;
      thread_args->distances_[idx] =
          distanceSquared(thread_args->origin_, thread_args->points_[idx]);
    }
  else
    for (int i = thread_args->num_pts_ - thread_args->base_sz_ - 2;
         i < thread_args->num_pts_; ++i)
      thread_args->distances_[i] =
          distanceSquared(thread_args->origin_, thread_args->points_[i]);
}

void distanceSquareds(struct Point origin, struct Point *points, int num_pts,
                      double *distances) {

  struct ThreadArgs thread_args = {.num_pts_ = num_pts,
                                   .base_sz_ = num_pts / NTHREADS,
                                   .points_ = points,
                                   .distances_ = distances};

  pthread_t threads[NTHREADS];

  for (thread_args.part_ = 0; thread_args.part_ < NTHREADS; ++thread_args.part_)
    pthread_create(&threads[thread_args.part_], NULL, calc_distances_thraed,
                   &thread_args);

  for (int i = 0; i < NTHREADS; ++i)
    pthread_join(threads[i], NULL);
}
