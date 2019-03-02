#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#include "parallel_distance.h"

double distanceSquared(const Point a, const Point b) {
  return pow(a.x_ - b.x_, 2) + pow(a.y_ - b.y_, 2);
}

void *calc_distances_thread(void *arg) {
  const ThreadArgs *thread_args = (ThreadArgs *)arg;
  const int part = thread_args->part_;
  sem_post(thread_args->mutex);

  if (part < thread_args->rem_)
    for (int i = 0; i <= thread_args->base_sz_; ++i) {
      const int idx = i + part * (thread_args->base_sz_ + 1);
      thread_args->distances_[idx] =
          distanceSquared(thread_args->origin_, thread_args->points_[idx]);
    }
  else
    for (int i = 0; i < thread_args->base_sz_; ++i) {
      const int idx = thread_args->rem_ * (thread_args->base_sz_ + 1) +
                      (part - thread_args->rem_) * thread_args->base_sz_ + i;
      thread_args->distances_[idx] =
          distanceSquared(thread_args->origin_, thread_args->points_[idx]);
    }

  pthread_exit(NULL);
}

void distanceSquareds(const Point origin, const Point *points,
                      const int num_pts, double *distances) {
  sem_t mutex;

  ThreadArgs thread_args = {.num_pts_ = num_pts,
                                   .base_sz_ = num_pts / NTHREADS,
                                   .rem_ = num_pts % NTHREADS,
                                   .points_ = points,
                                   .distances_ = distances,
                                   .mutex = &mutex};

  pthread_t threads[NTHREADS];

  sem_init(thread_args.mutex, 0, 1);

  for (int i = 0; i < NTHREADS; ++i) {
    sem_wait(thread_args.mutex);
    thread_args.part_ = i;
    pthread_create(&threads[thread_args.part_], NULL, calc_distances_thread,
                   &thread_args);
  }

  for (int i = 0; i < NTHREADS; ++i)
    pthread_join(threads[i], NULL);

  sem_destroy(thread_args.mutex);
}
