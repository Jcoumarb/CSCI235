#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	FILE *fp;
	//FILE *fopen(char *name, char *mode);

	//Old code for no command line argv
	//char fname[] = "lab6.txt";
	//char *fn = fname;

	if(argv == NULL){
		fprintf(stderr, "Error opening file\n");
		exit(1);
	}

	fp = fopen(argv[1], "r");

	if(fp == NULL){
		fprintf(stderr, "Error opening file\n");
		exit(1);
	}

	//Test of one case
	//char a = getc(fp);

	char a;
	char out[500];
	int index = 0;

	while(1){

		char a =  getc(fp);

		if(a == EOF){
			break;
		}
		out[index++] = a;
	}

	out[index] = 0;

	printf("%s", out);

	fclose(fp);

	exit(0);

}
