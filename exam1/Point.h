#ifndef POINT_H
#define POINT_H

typedef struct point {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2);

#endif
