#include <stdio.h>

int main(){

	int x = 70;

	char y [3];
	y[0] = 'a';
	y[1] = 't';
	y[2] = 'e';
	y[3] = 'w';

	int z = 19;

	printf("x: %d, x address: %p\n", x, &x);
	printf("y: %s, y address: %p\n", y, &y);
	printf("z: %d, z address: %p\n", z, &z);
	printf("y[3] test: %c\n", y[3]);
}
