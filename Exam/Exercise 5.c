/*
Find the shortest string
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findShortest(const char* const str1, const char* const str2);

int main(void) 
{
    const int bufSize = 128;
	char* str = (char*)malloc(bufSize * sizeof(char));
	if (str == NULL)
		abort();

	printf("Please, input a string:\n");
	fgets(str, bufSize, stdin);

    char* str2 = (char*)malloc(bufSize * sizeof(char));
    if (str2 == NULL)
		abort();

	printf("Please, input a second string:\n");
	fgets(str2, bufSize, stdin);
    
    findShortest(str, str2);
    free(str);
    free(str2);
    return 0;
}

void findShortest(const char* const str1, const char* const str2)
{
    int str1Lenght = strlen(str1);
    int str2Lenght = strlen(str2);

    if (str1Lenght == str2Lenght)
        printf("Strings are equal.\n");
    else if (str1Lenght < str2Lenght)
        printf("First string is shorter.\n");
    else
        printf("Second string is shorter.\n");
}