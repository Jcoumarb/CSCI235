#include <stdio.h>
#include <stdlib.h>

int convert(char c){
	if(c - 65 < 0){ //handles numbers
		return c - 48;
	}else{		//handles letters
		return c - 55;
	}
}

int readHex(){
	int first = -1;
	int second = -1;
int count = 1;
	for(int i = 0; i < 3; i++){
		char c = getchar();

		if(c == '\n'){
			continue;
		}

		if(count ==1){
			first = convert(c);
			count =2;
		}else if(count ==2){
			second = convert(c);
			count++;
		}

		if(count ==3) break;
	}

	int result;

	if(second == -1){
		result = first;
	}else{
		result = first*16 + second;
	}

	return result;
}

int main(){

	printf("Enter the first int as a two-character hex value: ");
	int a = readHex();

	printf("Enter the second int as a two-character hex value: ");
	int b  = readHex();

	printf("a is %d & b is %d", a, b);
	int c = a + b;

	char nums[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	char firstPlace;
	char secondPlace;

	for(int i = 0; i < 15; i++){	//handles finding out first digit
		if(c < convert(nums[i])){
			firstPlace = nums[i-1];
			break;
		}else if (i == 15){
			firstPlace = nums[i];
			break;
		}

		if(c == convert(nums[i])){
			firstPlace = nums[i];
			break;
		}

	}

	c -= convert(firstPlace); //decrements number

	if(c == 0){
		printf("The sum is: 0%c\n", firstPlace);
	}else{
		for(int i = 0; i < 15; i++){    //handles finding out second digit
                	if(c < convert(nums[i])*16){
                        	secondPlace = nums[i-1];
                        	break;
                	}else if (i == 15){
                        	secondPlace = nums[i];
                        	break;
                	}

                	if(c == convert(nums[i])*16){
                        	secondPlace = nums[i];
                        	break;
                	}

        	}

		c -= convert(secondPlace);	//decrements number

		if(c != 0){
			printf("The sum is: XX\n");
		}else{
			printf("The sum is: %c%c\n", secondPlace, firstPlace);
		}
	}
}
