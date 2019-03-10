#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct point {

        int abs,
            ord;
} Point;

float euclidean_distance(Point *p1, Point *p2) {

      return sqrt((p2->abs - p1->abs)*(p2->abs - p1->abs) + (p2->ord - p1->ord)*(p2->ord - p1->ord));
}

int main() {

    Point *p1,
          *p2;

    p1 = (Point*)malloc(sizeof(Point));
    p2 = (Point*)malloc(sizeof(Point));

    float res;

    printf("First point\n");
    printf("Abs: ");
    scanf("%d", &p1->abs);
    printf("Ord: ");
    scanf("%d", &p1->ord);

    printf("Second point\n");
    printf("Abs: ");
    scanf("%d", &p2->abs);
    printf("Ord: ");
    scanf("%d", &p2->ord);

    res = euclidean_distance(p1,p2);
    printf("Distance = %f", res);

    free(p1);
    free(p2);
 return(0);
};
