#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int max_search(int A[], int size)
{
    int max = INT_MIN; //Initialising max to a VERY small no. so that any no. bigger than this will be present in the array
    for (int i = 0; i < size; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    printf("Max element in the Array is %d", max);
    printf("\n");
    return max;
}
void countSort(int *A, int size)
{ //A is Given Array
    int max = max_search(A, size);
    int *B = (int *)malloc((max + 1) * sizeof(int)); //B is Count Array, we made it to the size of the maxm element present in the array
    for (int i = 0; i < max + 1; i++)                //@ important debug- don't forget max+1 because if greatest element is 9 then the array should have atleast 10 size to start from 0 !!
    {
        B[i] = 0; //Initially making all element in B equal to 0;
    }
    int x;
    for (int j = 0; j < size; j++)
    {
        x = A[j];
        B[x] = B[x] + 1;
        //B[A[j]]= B[A[j]]+1;       //can also use this instead of creating a integer x
    }
    int i = 0;
    int j = 0;
    while (i <= max)
    {
        if (B[i] > 0)
        {
            A[j] = i;
            j++;
            B[i] = B[i] - 1;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int A[] = {11, 3, 2, 2, 5, 7, 3, 2, 7, 9, 5, 3, 2, 2, 0};
    int size = sizeof(A) / sizeof(int);
    printArray(A, size);
    countSort(A, size);
    printArray(A, size);
    return 0;
}