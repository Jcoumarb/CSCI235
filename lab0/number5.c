#include <stdio.h>

int above(int nums[], int size, int n)
{
	int count = 0;

	for(int i = 0; i < size; i++)
	{
		if(nums[i] > n)
			count++;
	}

	return count;
}

int main()
{
	int arr1[5];
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	arr1[3] = 4;
	arr1[4] = 10;
	int result1 = above(arr1, 5, 6);

	int arr2[4];
	arr2[0] = 1;
	arr2[1] = 6;
	arr2[2] = 7;
	arr2[3] = 8;
	int result2 = above(arr2, 4, 5);

	printf("The first array contains %d integer(s) greater than 6\n", result1);
	printf("The second array contains %d integer(s) greater than 5\n", result2);
}
