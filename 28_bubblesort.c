/*
Bubble Sort Algorithm


Bubble sort intends to sort an array using (n-1) passes where n is the array's length. 
And in one pass, the largest element of the current unsorted part reaches its final position, 
and our unsorted part of the array reduces by 1, and the sorted part increases by 1. 
Take a look at the unsorted array above, and I'll walk you through each pass one by one, so you can feel how it gets sorted.

At each pass, we will iterate through the unsorted part of the array and compare every adjacent pair. 
We move ahead if the adjacent pair is sorted; otherwise, we make it sorted by swapping their positions. 
And doing this at every pass ensures that the largest element of the unsorted part of the array reaches its final position at the end.

1st Pass:
At first pass, our whole array comes under the unsorted part. 
We will start by comparing each adjacent pair. Since our array is of length 6, we have 5 pairs to compare.

PASS 1:
Index 0 & 1
    Index-   00 01 02 03 04 05
    element- 07 11 09 02 17 04
    Since these two( index 0 & 1) are already sorted, we move ahead without making any changes.
Index 1 & 2
    Index-   00 01 02 03 04 05
    element- 07 11 09 02 17 04
    Now since 9 is less than 11, we swap their positions to make them sorted.
Index 2 & 3
    Index-   00 01 02 03 04 05
    element- 07 09 11 02 17 04
    Again, we swap the positions of 11 and 2.
Index 3 & 4
    Index-   00 01 02 03 04 05
    element- 07 09 02 11 17 04
    We move ahead without changing anything since they are already sorted.
Index 4 & 5
    Index-   00 01 02 03 04 05
    element- 07 09 02 11 17 04
    Here, we make a swap since 17 is greater than 4.
    Index-   00 01 02 03 04 05
    element- 07 09 02 11 04 17

NOW in element- 07 09 02 11| 04 17
                  unsorted |sorted
    
    In 2nd pass , We again start from the beginning, with a reduced unsorted part of length 5. Hence the number of comparisons would be just 4.

PASS 2:
Index 0 & 1
    Index-   00 01 02 03 04 05
    element- 07 09 02 11 04 17
    No changes to make
Index 1 & 2
    Index-   00 01 02 03 04 05
    element- 07 09 02 11 04 17
    Yes, here we make a swap, since 9>2.
Index 2 & 3
    Index-   00 01 02 03 04 05
    element- 07 02 09 11 04 17
    Since 9 < 11, we move further.
Index 3 & 4
    Index-   00 01 02 03 04 05
    element- 07 09 02 11 04 17
    And since 11 is greater than 4, we make a swap again. 
    And that would be it for the second pass. 
    Let’s see how close we have reached to the sorted array.
    Index-   00 01 02 03 04 05
    element- 07 02 09 04 11 17

3rd Pass:
We’ll again start from the beginning, and this time our unsorted part has a length of 4; hence no. of comparisons would be 3.


4th Pass:
We just have the unsorted part of length 3, and that would cause just 2 comparisons. So, let’s see them.

5th (last) pass:
We have only one comparison to make here. 
result : 2 4 7 9 11 17


And this is what the Bubble Sort algorithm looks like. We have a few things to conclude and few calculations regarding the complexity of the algorithm to make.


1) Time Complexity of Bubble Sort: If you count the number of comparisons we made, there were (5+4+3+2+1), that is, a total of 15 comparisons. 
    And every time we compared, we had a fair probability of making a swap. 
    So, 15 comparisons intend to make 15 possible swaps.  
    Let us quickly generalize this sum. 
    For length 6, we had 5+4+3+2+1 number of comparisons and possible swaps. 
    Therefore, for an array of length n, we would have (n-1) + (n-2) + (n-3) + (n-4) + . . . . . + 1 comparison 
    and possible swaps.
2) This is a high school thing to find the sum from 1 to n-1, which is n(n-1)/2, 
    and hence our complexity of runtime becomes O(n^2).
3) And if you could observe, we never made a swap when two elements of a pair become equal. 
    Hence the algorithm is a stable algorithm. 
4) It is not a recursive algorithm since we didn’t use recursion here.
5) This algorithm has no adaptive aspect since every pair will be compared, 
    even if the array given has already been sorted. So, no adaptiveness. 
    Although it can be modified to make it adaptive, it's not adaptive by default.
    We’ll see in the next lecture how it can be made adaptive.

Time Complexity-    O(n^2)
Space Complexity-   
Stability-          Stable
Adaptivity-         Not Adaptive
Recursiveness-      Not Recursive

Size = n
No. of Passes = n-1
No. of Comparisons = n(n-1)/2
No. of Possible Swap = n(n-1)/2

*/

#include<stdio.h>
#include<stdlib.h>

void printArray(int *array, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubblesort(int *array, int size ){
    for (int i = 0; i < size -1; i++)           //For loop for no. of Passes - no. of passes = size-1
    {
        printf("Pass No. %d\n",i+1 );
        for (int j = 0; j < size - 1 - i; j++)  //For loop for Comparison in each pass
        {
            if (array[j]> array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void bubblesortAdaptive(int *array, int size){
    for (int i = 0; i < size -1; i++)
    {
        printf("Pass No. %d\n", i+1);
        int isSorted = 1;
        for (int j = 0; j < size -1 -i; j++)
        {
            if (array[j]> array[j+1])
            {
                int temp;
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                isSorted =0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main(){
    int arr[] = {1,3,75,5,2,4,6};
    int size = sizeof(arr)/ sizeof(int);
    printArray(arr, size);
    bubblesort(arr, size);
    // bubblesortAdaptive(arr, size);
    printArray(arr, size);
    return 0;
}