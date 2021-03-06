#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

#include <point.h>

#include "parallel_distance.h"

void *calc_distances_thread(void *arg) {
  const ThreadArgs *thread_args = (ThreadArgs *)arg;
  const int part = thread_args->part_;
  // Unlock the thread
  sem_post(thread_args->mutex);

  int idx;

  if (part < thread_args->rem_)
    for (int i = 0; i <= thread_args->base_sz_; ++i) {
      idx = i + part * (thread_args->base_sz_ + 1);
      thread_args->distances_[idx] =
          distanceSquared(thread_args->origin_, thread_args->points_[idx]);
    }
  else
    for (int i = 0; i < thread_args->base_sz_; ++i) {
      idx = thread_args->rem_ * (thread_args->base_sz_ + 1) +
            (part - thread_args->rem_) * thread_args->base_sz_ + i;
      thread_args->distances_[idx] =
          distanceSquared(thread_args->origin_, thread_args->points_[idx]);
    }

  pthread_exit((void *)arg);
}

void distanceSquareds(const Point origin, Point *points,
                      const int num_pts, double *distances) {
  sem_t mutex;

  ThreadArgs thread_args = {.num_pts_ = num_pts,
                            .base_sz_ = num_pts / NTHREADS,
                            .rem_ = num_pts % NTHREADS,
                            .points_ = points,
                            .distances_ = distances,
                            .origin_ = origin,
                            .mutex = &mutex};

  pthread_t threads[NTHREADS];

  sem_init(thread_args.mutex, 0, 1);

  int rc;

  for (int i = 0; i < NTHREADS; ++i) {
    sem_wait(thread_args.mutex);
    thread_args.part_ = i;
    rc = pthread_create(threads + thread_args.part_, NULL,
                            calc_distances_thread, &thread_args);
  }

  for (int i = 0; i < NTHREADS; ++i) {
    rc = pthread_join(threads[i], NULL);
  }

  sem_destroy(thread_args.mutex);
}
