#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size)
{
    printf("Array[%d]: ", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int size){
    int indOfmin, temp;
    for (int i = 0; i < size-1; i++)
    {
        indOfmin = i;
        for (int j = i+1; j < size; j++)
        {
            if (arr[j] <arr[indOfmin])
            {
                indOfmin = j;
            }
        }
        temp =arr[i];
        arr[i] = arr[indOfmin];
        arr[indOfmin] = temp; 
    }
    
}

int main(){
    
    int arr[] = {90, 0002, 31, 93, 33, 402};
    int size = sizeof(arr) / sizeof(int);

    printArray(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}