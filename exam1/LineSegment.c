#include "LineSegment.h"
#include <math.h>
#include "Point.h"
#include <stdio.h>

double length(struct LineSegment line){

	return distance(line.p1, line.p2);
}
double slope(struct LineSegment line){

	double x1 = line.p1.x;
	double y1 = line.p1.y;
	double x2 = line.p2.x;
	double y2 = line.p2.y;

	double deltax = x1 - x2;
	double deltay = y1 - y2;

	double answer = deltay/deltax;

	return answer;
}
