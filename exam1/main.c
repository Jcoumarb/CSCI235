#include <stdio.h>
#include <math.h>
#include "Point.h"
#include "LineSegment.h"
#include "LineSegment.h" // to test header guard

#define HOW_CLOSE 0.01

int close_enough(double val1, double val2)
{
	if (fabs(val1 - val2) <= HOW_CLOSE)
		return 1;
	return 0;
}

int test_thing(char* name, char* thang, double yerthang, double mythang)
{
	printf("Testing that your %s for %s is %f...", thang, name, mythang);
    if (close_enough(yerthang, mythang)) {
        printf("correct\n");
    } else {
        printf("incorrect -- you said it was %f\n", yerthang);
    }
}

int main() {
    LineSegment seg1 = {{-1,0},{0,-1}};

    Point p1 = {0, 0};
    Point p2 = {2, 4};
	Point p3 = {2, 1};
	Point p4 = {5, 2};

    LineSegment seg2 = {p1, p2};
    LineSegment seg3 = {p3, p4};

	char* name1 = "seg1";
	char* name2 = "seg2";
	char* name3 = "seg3";
	
	test_thing(name1, "slope", slope(seg1), -1);
	test_thing(name2, "slope", slope(seg2), 2);
	test_thing(name3, "slope", slope(seg3), (1.0/3.0));

	test_thing(name1, "length", length(seg1), (1.0*sqrt(2)));
	test_thing(name2, "length", length(seg2), (sqrt(20)));
	test_thing(name3, "length", length(seg3), (sqrt(10)));



}
