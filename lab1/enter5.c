#include <stdio.h>

int main(){

	int vals[5];

	printf("Enter five digits, one at a time:\n");

	for(int i = 0; i<5; i++){
		int n = getchar() - '0';	//converts asci to decimal that we want to handle
		getchar();	//discards carraige return character from reader

		if(n>0 && n<10){	//checks that user has input correct data and handles
			vals[i] = n;
		}else{
			vals[i] = 0;
		}
	}

	for(int j = 0; j<5; j++){
		printf("vals[%d]=%d, square=%d\n", j, vals[j], (vals[j]*vals[j]));
	}
}
