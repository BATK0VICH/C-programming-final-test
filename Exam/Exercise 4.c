/*
Calculate same words in a string
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertToLowerCase(char* str);

int main(void) 
{
	const int bufSize = 128;
	char* str = (char*)malloc(bufSize * sizeof(char));
	if (str == NULL)
		abort();

	printf("Please, input a string:\n");
	fgets(str, bufSize, stdin);
	convertToLowerCase(str);

	char tokens[64][32] = {"", ""};
	
	//first token
	char* token = strtok(str, " ");
	strcpy(tokens[0], token);
	printf("%s\n", tokens[0]);
	
	//all other tokens
	int i = 1;
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		strcpy(tokens[i], token);
		printf("%s\n", tokens[i]);
		++i;
	}

	int counter = 0;
	for (int j = 0; j < i; ++j)
	{
		if (strcmp(tokens[j], tokens[j+1]) == 0)
			++counter;
	}
	printf("Simillar words: %d", counter);
	free(token);
	free(str);
	return 0;
}

void convertToLowerCase(char* str)
{
	for (int i = 0; str[i] != '\0'; ++i)
		str[i] = tolower(str[i]);
	return;
}