#include <stdio.h>

int is_palindrome(char str[]);

int main(){

	char charTest[] = "element";
	char charTest2[] = "racecar";
	char charTest3[] = "hannah";

	if(is_palindrome(charTest)){
		printf("%s is a palindrome\n", charTest);
	}else{
		printf("%s is not a palindrome\n", charTest);
	}

	if(is_palindrome(charTest2)){
		printf("%s is a palindrome\n", charTest2);
	}else{
		printf("%s is not a palindrome\n", charTest2);
	}

	if(is_palindrome(charTest3)){
		printf("%s is a palindrome\n", charTest3);
	}else{
		printf("%s is not a palindrome\n", charTest3);
	}

	return 0;
}

int is_palindrome(char str[]){
	int counter = 0;
	int intBoolean = 1;

	while(str[counter] != '\0'){	//iterates to find the length of the array (word size)
		counter++;
	}

	char strCopy[counter];	//creates new array of the same length that the orignal word will be transposed on to but reverse
	int countDown = counter - 1;

	for(int i = 0; i<counter; i++){

		strCopy[i] = str[countDown];	//these two lines are putting the contents of str into strCopy backwards
		countDown--;

		if(strCopy[i] != str[i]){	//checks if the characters of the arrays match and handle accordingly
			intBoolean = 0;
		}
	}

	return intBoolean;
}
