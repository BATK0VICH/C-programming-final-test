/*
Calculate the result of the multiplication of all negative elements in the array
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int* const arr, const int size);
void printArray(const int* const arr, const int size);
int multiplyNegative(const int* const arr, const int size);

int main(void)
{
    int n = 0;
    do 
    {
        printf("How many elements you want to be in the array? n = ");
        scanf("%d", &n);
    } while(n <= 0);

    int* arr = NULL;
    arr = (int*)malloc(n * sizeof(int));
    if (arr != NULL) 
    {
    fillArray(arr, n);
    printArray(arr, n);

    int result = multiplyNegative(arr, n);
    if (result == 0)
        printf("Couldn't multiply\n");
    else
        printf("Result of negative multiplication: %d", multiplyNegative(arr, n));
    }
    
    free(arr);
    return 0;
}

void fillArray(int* const arr, const int size)
{
    //setting range for the array
    const int min = -100;
    const int max = 100;

    time_t t = 0;
    srand((unsigned) time(&t));

    for (int i = 0; i < size; ++i)
    {
        arr[i] = (rand() % (max + 1 - min) + min);
    }
}

void printArray(const int* const arr, const int size) 
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

//multiples all negative elements
int multiplyNegative(const int* const arr, const int size)
{
    //if we initialize to 0, the calculations will not make sense
    int result = 1;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
            result *= arr[i];
        else
            continue;
    }
    if (result == 1)
        return 0;
    else
        return result;
}