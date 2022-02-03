//INSERTION METHOD OF SORTING AN ARRAY

/*
TIPS:
If Size of Array = n
Fixed No. of Passes = n-1
Possible No. of Comparison = n(n-1)/2
Worst Case Complexity = O(n2)
Best Case Complexity  = O(n)
Insertion mathod OF SORTING is STABLE AND ADAPTIVE by nature!


CODE EXPLANATION:
DRY RUNNING THE CODE WE WROTE ABOVE FOR BETTER UNDERSTANDING!!
-1  0  1  2  3  4  5  6
    02 01 03 04 84 48 05

    02|01 03 04 84 48 05    ----> i=1, key=01, j=0
    02|02 03 04 84 48 05    ----> i=1, key=01, j=-1         
    01|02 03 04 84 48 05    ----> 1st PASS COMPLETE

    01 02|03 04 84 48 05    ----> i=2, key=03, j=1
    01 02|03 04 84 48 05    ----> 2nd PASS COMPLETE

    01 02 03|04 84 48 05    ----> i=3, key=04, j=2
    01 02 03|04 84 48 05    ----> 3rd PASS COMPLETE

    01 02 03 04|84 48 05    ----> i=4, key=84, j=3
    01 02 03 04|84 48 05    ----> 4th PASS COMPLETE

    01 02 03 04 84|48 05    ----> i=5, key=48, j=4
    01 02 03 04 84|84 05    ----> i=5, key=48, j=3
    01 02 03 04 48|84 05    ----> 5th PASS COMPLETE

    01 02 03 04 48 84|05    ----> i=6, key=05, j=5
    01 02 03 04 48 84|84    ----> i=6, key=05, j=4
    01 02 03 04 48 48|84    ----> i=6, key=05, j=3
    01 02 03 04 05 48|84    ----> 6th PASS COMPLETE

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

void insertionSort(int *arr, int size){
    int key, j;
    //Loop for Passes:
    for (int i = 1; i <= size-1; i++)           //starting i from 1 because LEFT side par 0th index pr start mein sirf ek element hai, and ONE  element toh sorted hi kehlaayega
    {
        printf("Pass No. %d\n", i);
        key = arr[i];                   //this will hold the element to be INSERTED on Left (sorted) array while Sorting
        j = i-1;
        //Loop for Comparison in Each Pass
        while (j>=0 && arr[j]> key)     //don't write arr[i] because vo comparison k saath saath change hote rahega , and key won't change
        {
            arr[j+1]= arr[j];           //You have to Change the element at J+1 (not at i) kyuki here one shift sorting horahi hai
            j--;
        }
        arr[j+1] = key;
    }
}


int main(){
    int arr[] = {2,1,3,4,84,48,05};
    int size  = sizeof(arr)/sizeof(int);
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}