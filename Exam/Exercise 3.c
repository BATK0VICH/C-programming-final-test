/*
Check the singularity of the matrix, find sum of all negative elements
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <time.h>

#define SIZE 5

void printMatrix(const int (*a)[SIZE]);
void fillMatrix(int (*a)[SIZE]);

//finds sum of all negative elements
int findSumOfMin(const int (*a)[SIZE]);
//Checks the singularity of the matrix
int checkIdentity(const int (*a)[SIZE]);

int main(void) 
{
	int a[SIZE][SIZE] = {
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0},
					};

	fillMatrix(a);			
	printMatrix(a);
	printf("\n");
	printf("The sum of all negative elements in the matrix: %d\n", findSumOfMin(a));

	int singularity = checkIdentity(a);
	if (singularity == 1)
		printf("The matrix is singular\n");
	else
		printf("The matrix isn't singular\n");
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

void fillMatrix(int (*a)[SIZE])
{
	//setting range for the array
    const int min = -100;
    const int max = 100;

    time_t t = 0;
    srand((unsigned) time(&t));

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			a[i][j] = (rand() % (max + 1 - min) + min);	
	}	
}

int findSumOfMin(const int (*a)[SIZE])
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (a[i][j] < 0)
				sum += a[i][j];
		}	
	}
	return sum;	
}

int checkIdentity(const int (*a)[SIZE])
{
	//0 for false and 1 for true
	unsigned short int diagonal = 1, singularity = 1, zeroth = 1; 

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (a[i][j] != 0)
			{
				if (i!=j)
					singularity = 0;
			}
			if (i == j && a[i][j]!= 1)
				singularity = 0;
		}
	}
	if (singularity == 1)
		return singularity;	
	return 0;
}