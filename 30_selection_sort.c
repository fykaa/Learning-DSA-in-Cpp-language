/*
SELECTION SORT

Size = n
No. of Passes = n-1
Comparisons Done in Pass No. x = n-x
Total No. of comparisons done = n(n-1)/2        --> O(n2)
Maximum possible SWAPS = n-1    
Minimum possible swaps = 0


Selection Sort is NOT STABLE NOR ADAPTIVE eg. (arr []= {7,8,8,1,8})
Benefit of Selection Sort is REQUIRES MINIMUM NO. OF SWAPS

*/



#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size){
    printf("Array[%d]: ", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size){
    int indexOfMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        printf("Pass No. %d\n", i+1);
        indexOfMin = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[indexOfMin]> arr[j])
            {
                indexOfMin = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin]= temp;
    }
}

int main(){
    int arr[] = {90,0002,31,93,33,402};
    int size = sizeof(arr)/sizeof(int);

    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}
