/*
Count Sort is one of the fastest methods of all. 
We will discuss constraints later, which would make you wonder why we don't use just this. 
We will do all the analysis, but before that, let’s see what count sort is. 
The below figure shows the array given.

1)The algorithm first asks you to find the largest element from all the elements in the array 
    and store it in some integer variable max. Then create a count array of size max+1. 
    This array would count the no. of occurrences of some number in the given array. 
    We will have to initialize all count array elements with 0 for that to work.
2)After initializing the count array, traverse through the given array, and increment the value 
    of that element in the count array by 1. By defining the size of the count array as the maximum element
    in the array, you ensure that each element in the array has its own corresponding index in the 
    count array. After we traverse through the whole array, we’ll have the count of each element in the array.
3)Now traverse through the count array, and look for the nonzero elements. 
    The moment you find an index with some value other than zero, fill in the sorted array 
    the index of the non-zero element until it becomes zero by decrementing it by 1 every 
    time you fill it in the resultant array. And then move further. This way, you create a sorted array. 

Time Complexity of Count Sort: 
    Calculating the time complexity of the count sort algorithm is one of the easiest jobs to do. 
    If you carefully observe the whole process, we only ran two different loops, one through the given array
    and one through the count array, which had the size equal to the maximum element in the given array. 
    If we suppose the maximum element to be m, then the algorithm's time complexity becomes O(n+m), 
    and for an array of some huge size, this reduces to just O(n), which is the most efficient by far
    algorithm. 
  
However, there is a negative point as well. The algorithm uses extra space for the count array.  
And this linear complexity is reachable only at the cost of the space the count array takes.


*/


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
    int max = INT_MIN; //Initialising max to any VERY small no. so that any no. bigger than this will be present in the array
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