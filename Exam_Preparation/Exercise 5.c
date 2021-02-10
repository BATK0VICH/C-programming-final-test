/*
Sort the matrix
UTM FCIM TI
Dronov Dmitrii
*/
#include <stdio.h>
#define n 5
#define m 8

void quickSort(int matrix[n][m], int low, int high, int row);
void printMatrix(int matrix[n][m]);
void swap(int* a, int* b);
int partition(int arr[], int low, int high);

int main() 
{
    int B[n][m] = {
                {1, 2, 3, 4, 5, 9, 0, 7},
                {6, 7, 8, 9, 1, 4, 3, 2},
                {2, 3, 4, 5, 6, 8, 5, 1},
                {7, 8, 9, 1, 0, 5, 2, 8},
                {1, 2, 3, 4, 5, 1, 8, 2}
                };
    
    printf("Initial matrix:\n");
    printMatrix(B);

    quickSort(B, 0, m-1, 0);

    printf("Sorted matrix:\n");
    printMatrix(B);
}

void quickSort(int matrix[n][m], int low, int high, int row)
{
    if (low < high) 
    { 
        int pi = partition(matrix[row], low, high); 
  
        quickSort(matrix, low, pi - 1, row); 
        quickSort(matrix, pi + 1, high, row); 
    }
    if (row < n)
    {
        quickSort(matrix, 0, m-1, row + 1);
    }
}

void printMatrix(int matrix[n][m]) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%i  ", matrix[i][j]);
        }
        printf("\n");
    }
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 