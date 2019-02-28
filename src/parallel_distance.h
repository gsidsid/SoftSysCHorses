struct Point {
  double x;
  double y;
};

double normSquared(struct Point point);
double distanceSquared(struct Point a, struct Point b);
void distributeJobs(int njobs, int nthreads, int *jobs_per_thread);
void distanceSquareds(struct Point origin, struct Point points[], int num_pts, double distances[]);
