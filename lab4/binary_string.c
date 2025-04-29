#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

unsigned binary_to_unsigned(char* str){

	int size = 0;
	char* start = &str[0];//iterator to get through array

	while(*start != '\0'){	//this loop find the 'size' or the length of the binary number
		size++;
		start =  &str[size];
	}

	unsigned numPower = size - 1; //sets exponent of the first place
	unsigned num = 0; //stores answer as it is added up

	for(int i = 0; i < size; i++){	//loops for the length of the binary number and adds up all the place values and assigns to num

		if(str[i] == '0'){
			num += 0;
		}

		if(str[i] == '1'){
			num += pow(2, numPower);
		}

		numPower--;
	}

	return num;
}

char* unsigned_to_binary(unsigned x){

	char* binary = (char*) malloc(32*sizeof(char));

	unsigned num = x;

	if(num  == 0){

		binary[0] = '0';
		binary[1] = 0;

		return binary;
	}else{

		unsigned numPower = 0;		// finds highest place value that fits into
		bool largestFound =  false;
		while(!largestFound){
			if(pow(2, numPower) >= x){
				break;
			}
			numPower++;
		}

		if(pow(2, numPower) > x){
			numPower--;
		}

		unsigned checker = pow(2, numPower);
		int index = 0;
		unsigned size = numPower;

		binary[index++] = '1'; //The first place is always  1 because we stopped at this value intentionally
		while(size !=0){

			numPower--;

			if((checker + pow(2, numPower)) <= num){
				checker += pow(2, numPower);
				binary[index] = '1';
			}else{
				binary[index] = '0';
			}

			index++;
			size--;
		}

		binary[index] = '\0';

		return binary;

	}
}

char* add_binary(char* str1, char* str2){

	int size1 = 0;
	int size2 = 0;
	int bigger = 0;
	char* first = &str1[0];
	char* second = &str2[0];

	while(*first != '\0'){
		size1++;
		first = &str1[size1];
	}

	while(*second != '\0'){
		size2++;
		second = &str2[size2];
	}

	if(size1 > size2){
		bigger = size1;
	}

	if(size2 > size1){
		bigger = size2;
	}

	if(size1 == size2){
		bigger = size1;
	}

	first = &str1[--size1];
	second = &str2[--size2];

	char sum [32];	//instantiation of output array and setting all values to char zero

	int index = 31;
	int carry = 0;

	int finalSize = bigger;

	while(bigger > -1){

		int current  = 0;

		if(*first == '1' && size1 > -1){
			current += 1;
		}

		if(*second == '1' && size2 > -1){
			current += 1;
		}

		if((current + carry) == 0){	//case of zeros in all categories
			sum[index--] = '0';
			carry = 0;
		}else if((current + carry) == 1){	// case of 1 is supposed to be input
			sum[index--] = '1';
			carry = 0;
		}else if((current + carry) == 2){
			sum[index--] = '0';
			carry = 1;
		}else if((current + carry) == 3){
			sum[index--] = '1';
			carry = 1;
		}

		first = &str1[--size1];

		second = &str2[--size2];
		bigger --;
	}

	char* out = malloc(bigger*sizeof(char));
	int finalStart = 0;
	for(int i = 0; i < 32; i++){

		finalStart = i;

		if(out[i] == '1'){
			break;
		}
	}

	for(int i = 0; i < finalSize; i++){
		if(i == (finalSize-1)){
			out[i] = 0;
		}
		out[i] = sum[finalStart++];
	}
	return out;
}
int main(){

	char str1[] = "1101";
	char* strp1 = str1;
	char str2[] = "101";
	char* strp2 = str2;

	printf("%s\n", add_binary(strp1, strp2));


}
