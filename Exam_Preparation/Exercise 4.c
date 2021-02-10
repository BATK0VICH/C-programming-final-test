/*
Count words in a string
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	const int bufSize = 128;
	char* str = (char*)malloc(bufSize * sizeof(char));
	if (str == NULL)
		abort();

	printf("Please, input a string:\n");
	fgets(str, bufSize, stdin);
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ') 
			count++;
	}
	
	printf("In given string %d words", count+1);
	free(str);
}

