#include "Point.h"

#ifndef  LINESEGMENT_H
#define LINESEGMENT_H

struct LineSegment{
	Point p1;
	Point p2;
};
typedef struct LineSegment LineSegment;
double length(struct LineSegment line);
double slope(struct LineSegment line);

#endif
