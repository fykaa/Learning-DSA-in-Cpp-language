// INSERTION METHOD OF SORTING AN ARRAY

/*

Insertion Sort Algorithm
Suppose you were to stand in a queue where people are already sorted on the basis of the amount of money they have.
 Person with the least amount is standing in the front and the person with the largest sum in his pocket stands last.
 example: 6k 9k 10k 12k
Problem arises when you suppose you have ₹8000 in your pocket,
and you want to be a part of this queue.
You don’t know where to stand.
So, now you start from the last and keep asking the person standing there
whether he has more money than you or less money than you.
If you find someone with more money, you simply ask him/her to shift backward.
And the moment you find a person having less money than you, you stand just behind him/her.
So, after doing all this, you find a position in the 2nd place in the queue.
The final situation is:
6k 8k 9k 10k 12k
  you| shifted

so We would keep comparing two numbers,
 and if we find a number greater than the number we want to insert, we shift it backward.
 And the moment we find a number smaller,
 we insert the element at the vacant space just behind the smaller number.

Insert Sort Algorithm:
Let’s just take an array, and use the insertion sort algorithm to sort its elements in increasing order.
Consider the given array below:
0 1 2  3  4
7 2 91 77 3
And what have we already learned?
We have learned to put an arbitrary element inside a sorted array,
using the insertion method we saw above.
And an array of a single element is always sorted.
So, what we have now is an array of length 5 with a subarray of length 1 already sorted.

Moving from the left to the right, we will pluck the first element from the unsorted part,
 and insert it in the sorted subarray.
 This way at each insertion, our sorted subarray length would increase by 1 and unsorted subarray length decreases by 1.
 Let’s call each of these insertions and the traversal of the sorted subarray to find the best position, a pass.

TIPS:
Time Complexity:
Worst Case Complexity = O(n2)
Best Case Complexity  = O(n)
Space Complexity-   
Stability-          Stable
Adaptivity-         Adaptive
Recursiveness-      Not Recursive

If Size of Array = n
Fixed No. of Passes = n-1
Possible No. of Comparison = n(n-1)/2
Insertion method OF SORTING is STABLE AND ADAPTIVE by nature!


// CODE EXPLANATION:
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
#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int size)
{
    printf("Array[%d]: ", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int size)
{
    int key, j;
    // Loop for Passes:
    for (int i = 1; i <= size - 1; i++) // starting i from 1 because LEFT side par 0th index pr start mein sirf ek element hai, and ONE  element toh sorted hi kehlaayega
    {
        printf("Pass No. %d\n", i);
        key = arr[i]; // this will hold the element to be INSERTED on Left (sorted) array while Sorting
        j = i - 1;
        // Loop for Comparison in Each Pass
        while (j >= 0 && arr[j] > key) // don't write arr[i] because vo comparison k saath saath change hote rahega , and key won't change
        {
            arr[j + 1] = arr[j]; // You have to Change the element at J+1 (not at i) kyuki here one shift sorting horahi hai
            j--;
        }
        arr[j + 1] = key;       //so with every pass key will be shifted to its correct position!
    }
}

int main()
{
    int arr[] = {2, 1, 3, 4, 84, 48, 05};
    int size = sizeof(arr) / sizeof(int);
    printArray(arr, size);
    insertionSort(arr, size);
    printArray(arr, size);
    return 0;
}