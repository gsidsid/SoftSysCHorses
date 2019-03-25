#include <kmeans.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CENTERS 3
#define NUM_PTS NUM_CENTERS*10000

int main() {
  Point points[NUM_PTS];
  FILE *stream = fopen("random_clusters_10000.csv", "r");
  FILE *ostream = fopen("cluster_centers.csv", "w");
  char line[1024];
  double x, y;
  int i = 0;

  while (fgets(line, 1024, stream) && i < NUM_PTS) {
    char *tmp = strdup(line);
    sscanf(tmp, "%lf,%lf\n", &x, &y);

    points[i].x_ = x;
    points[i].y_ = y;

    free(tmp);
    ++i;
  }

  Point *centers = malloc(sizeof(Point) * NUM_CENTERS);
  clock_t start = clock();
  centers = kmeans(points, NUM_PTS, NUM_CENTERS);
  clock_t end = clock();
  double time_spent = (double) (end - start) / CLOCKS_PER_SEC;
  printf("Run time: %lf seconds\n", time_spent);
  for (int i = 0; i < NUM_CENTERS; ++i)
    {
    printf("Center %d: %lf, %lf\n", i, centers[i].x_, centers[i].y_);
    fprintf(ostream, "%lf,%lf\n", centers[i].x_, centers[i].y_);
    }

  free(centers);
}
