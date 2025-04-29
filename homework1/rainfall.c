#include <stdio.h>
#include <stdlib.h>

int main (){

	printf("Enter daily rainfall totals, one per line, use 'T' for\ntrace, use '-1' to quit:\n");
	float total = 0.0;
	char input[10];
	int index = 0;
	char ch;

	while(1){

		while(1){	//This loop puts the user input from one line into an array
			ch = getchar();
			if(ch == '\n'){
				break;
			}
			input[index++] = ch;
		}
		input[index++] = '\0';	//this null terminates the string of user inputs

		if(input[0] == '-' && input[1] == '1'){	//this checks if the quit button has been pressed
			input[0] = '\0';	//a few values need to be reset here because the code breaks and it doesn't reset at the bottom of the while loop
			input[1] = '\0';
			index = 0;
			break;
		}

		else if(input[0] == 'T'){	//this checks if the trace button bas been pressed
			total += 0;
		}

		else{				//this converts the characters to a float and adds it to total if 0 <= num < 10
			float num = atof(input);
			if(num >=0 && num < 10){
				total += num;
			}
		}

		for(int i = 0; i < 10; i++){ //this resets the input array at the end of each interation
			input[i] = '\0';
		}

		index = 0;
	}

	printf("Total rainfall: %.2f\n", total);
}
