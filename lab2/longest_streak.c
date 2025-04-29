#include <stdio.h>
#include "longest_streak.h"

int longest_streak(int arr[], int size){

	if(size == 0){	// base case check for size 0 array
		return 0;
	}else{
		int maxStreak = 0;	//stores largest streak number till now
		int currStreak = 0;	//stores streak of current number
		int currNum = -1;	//stores current number

		for(int i = 0; i < size; i++){

			if(arr[i] != currNum){		// checks if the streak is over
				currNum = arr[i];	//changes to new number
				currStreak = 1;		//resets curr streak
			}else{
				currStreak ++;		//if the streak isn't broken, it will add to the streak
			}

			if(currStreak > maxStreak){	//Checks if the maxStreak has been exceeded 
				maxStreak = currStreak;
			}
		}

		return maxStreak;
	}
}
/*
int main(){

	int test [] = {1, 2, 3, 2, 4, 4, 4, 2, 1, 1};

	int result = longest_streak(test, 10);

	printf("the longest streak is %d\n", result);
}
*/
