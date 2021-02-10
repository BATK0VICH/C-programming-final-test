/*
Check if the matrix is semetric
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#define SIZE 5

void printMatrix(const int (*a)[SIZE]);
void transposeMatrix(int (*a)[SIZE]);
int checkForSemetric(const int (*a)[SIZE]);

int main(void) 
{
	int a[SIZE][SIZE] = {
					{1, 2, 3, 4, 5},
					{6, 7, 8, 9, 1},
					{2, 3, 4, 5, 6},
					{7, 8, 9, 1, 0},
					{1, 2, 3, 4, 5},
					};
				
	printMatrix(a);
	printf("Transposing the matrix:\n");
	transposeMatrix(a);			
	printMatrix(a);
	printf("\n");
	checkForSemetric(a);

	return 0;	
}

void printMatrix(const int (*a)[SIZE]) 
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", a[i][j]);	
		}
		printf("\n");
	}	
}

void transposeMatrix(int (*a)[SIZE])
{
	int tmp = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i+1; j < SIZE; j++)
		{
			tmp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = tmp;
		}
	}		
}

int checkForSemetric(const int (*a)[SIZE])
{
	int count = 0;	
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i+1; j < SIZE; j++)
		{
			if (a[i][j] != a[j][i])
				count++;
		}
	}
	if (count != 0) 
		printf("The Matrix isn't semetric\n");
	else 
		printf("The Matrix is semetric\n");
	return count;
}