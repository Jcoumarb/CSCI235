#include <stdio.h>

int main()
{
	printf("Enter characters, one at a time,\nuse ctrl-d to quit:\n");

	char c;
	int Xcount;

	while(c != EOF)
	{
		c = getchar();	//Get character
		getchar();	//discards carraige return

		if(c == 'X')
		{
			Xcount ++;
		}
	}

	printf("You entered X %d times\n",Xcount);	//Displays how many times the user entered the character 'X'
}
