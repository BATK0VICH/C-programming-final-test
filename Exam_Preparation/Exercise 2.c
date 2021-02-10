/*
Find the first minimal element and its index in the random array
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int* const arr, const int size);
void printArray(const int* const arr, const int size);

typedef struct 
{
    int value;
    int index;
} Pair;

Pair findMin(const int* const arr, const int size);
void printPair(const Pair pair);

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
    Pair pair = findMin(arr, n);
    printPair(pair);
    free(arr);
    }
    
}

void fillArray(int* const arr, const int size)
{
    const int min = 10;
    const int max = 99;

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

//finds first minimal array element and its index
Pair findMin(const int* const arr, const int size) 
{
    Pair min;
    min.index = 0;
    min.value = arr[0];
    for (int i = 0; i < size; ++i)
    {
        if (min.value > *(arr + i))
        {
            min.value = *(arr + i);
            min.index = i;
        }
        else if (min.value <= *(arr + i))
            continue;
    }
    return min;
}

void printPair(const Pair pair) 
{
    printf("\nFirst minimum elment:\nValue: %d\nIndex:%d", pair.value, pair.index);
}