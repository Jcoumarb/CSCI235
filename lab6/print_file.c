#include <stdio.h>

int main(){

	FILE *fp;
	//FILE *fopen(char *name, char *mode);

	char fname[] = "lab6.txt";
	char *fn = fname;

	char mode = 'r';
	char *m = &mode;


	fp = fopen(fn, m);

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

}
