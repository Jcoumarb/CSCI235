#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comment out the following line to make showstring print nothing
#define DEBUG 1
// Changing it to #define DEBUG 0 does not work. Why not?

void showstring(char* buf, int size)
{
#ifdef DEBUG
	// First line (you will always see something)
	printf("Your string contains: \n");
	// Second line -- your string
	for (int i = 0; i < size; i++)
	{
		if (buf[i] == 0)
			printf("0");
		else
			printf("%c", buf[i]);
	}
	printf("\n");
	// Third line, for indexing into your string
	for (int i = 0; i < size; i++)
		printf("%d", i%10);
	printf("\n");
#endif
}


int main(int argc, char *argv[])
{
	//showstring("Welcome to Lab6!", 16);

	if(argv == NULL){							//error handling of no command line arguments
		fprintf(stderr, "Error with string param or file name\n");
		exit(1);
	}


	char *find = argv[1];
	int fsize = 0;

	while(1){	//finds the length of the word that is being searched for, 'find'

		fsize++;

		if(find[fsize] == 0){
			break;
		}
	}

	FILE *fp = fopen(argv[2], "r");	//file opening and error handling
	if(fp == NULL){
		fprintf(stderr, "Error with string param or file name\n");
		exit(1);
	}

	char *ch;
	char line[255];


	while(1){	//loops through each line checking if it contains 'find'

		ch = fgets(line, 255, fp);	// grabs info from line

		if(ch == NULL){	//breaks loop at EOF
			break;
		}

		int lsize = 0;

		while(1){	//finds the character length of the line

			lsize++;

			if(line[lsize] == 0){
				break;
			}
		}

		line[lsize - 1] = '$';	// drops the meta character in the last index of the line string
		lsize --;

		int currentStart = 0;
		int found = 0;

		while(1){

			if(currentStart > lsize){
				break;
			}

			if(line[currentStart] == find[0]){
				int localFound = 1;

				for(int i = 0; i < fsize; i++){
					if(line[currentStart + i] != find[i]){
						localFound = 0;
					}
				}
				if(localFound == 1){
					found = 1;
					break;
				}
			}

			currentStart ++;
		}

		if(found == 1){
			printf("%s\n", line);
		}
	}

	fclose(fp);
	exit(0);


}
