/*
QUICK SORT

The QuickSort algorithm is quite different from the ones we have studied so far. 
Here, we use the divide and conquer method to sort our array in pieces reducing our effort and space complexity of the algorithm. 
There are two new concepts you must know before you jump into the core. 

First is the divide and conquer method. 
As the name suggests, Divide and Conquer divides a problem into subproblems and solves them at their levels, 
giving the output as a result of all these subproblems.

Second is the partition method in sorting. 
In the partition method, we choose an element as a pivot and try pushing all the elements smaller than the pivot 
element to its left and all the greater elements to its right. We thus finalize the position of the pivot element. 
QuickSort is implemented using both these concepts. And I’ll help you master them very soon.

Suppose we are given an array of integers, and we are asked to sort them using the quicksort algorithm, 
then the very first task you would do is to choose a pivot. Pivots are chosen in various ways, 
but for now, we’ll consider the first element of every unsorted subarray as the pivot. Remember this while we proceed.

index                       0 1 2 3 4 5 6 7 8 9
Unsorted Array              2 4 3 9 1 4 8 7 5 6 

In the quicksort algorithm, every time you get a fresh unsorted subarray, you do a partition on it.  
Partition asks you to first choose an element as a pivot. And as already decided, 
we would choose the first element of the unsorted subarray as the pivot. 
We would need two more index variables, i and j. Below enlisted is the flow of our 
partition algorithm we must adhere to. We always start from step 1 with each fresh partition call.

1) Define i as the low index, which is the index of the first element of the subarray, and j as the high index, which is the index of the last element of the subarray.
2) Set the pivot as the element at the low index i since that is the first index of the unsorted subarray.
3) Increase i by 1 until you reach an element greater than the pivot element.
4) Decrease j by 1 until you reach an element smaller than or equal to the pivot element.
5) Having fixed the values of i and j, interchange the elements at indices i and j.
6) Repeat steps 3, 4, and 5 until j becomes less than or equal to i.
7) Finally, swap the pivot element and the element at the index j.

This was the partitioning algorithm. Every time you call a partition, the pivot element gets its final position. 
A partition never guarantees a sorted array, but it does guarantee that all the smaller elements are located to 
the pivot’s left, and all the greater elements are located to the pivot’s right.

Now let's look at how the array we received at the beginning gets sorted using partitioning and divide and conquer recursively for smaller subarrays.
Firstly, the whole array is unsorted, and hence we apply quicksort on the whole array.
Now, we apply a partition in this array. Applying partition asks you to follow all the above steps we discussed.

                            i                 j
                            0 1 2 3 4 5 6 7 8 9
Unsorted Array              2 4 3 9 1 4 8 7 5 6
                           current Unsorted Array
Keep increasing i until we reach an element greater than the pivot, and keep decreasing j until we reach an element smaller or equal to the pivot.

                              i     j
                            0 1 2 3 4 5 6 7 8 9
Unsorted Array              2 4 3 9 1 4 8 7 5 6 
Swap the two elements and continue the search further until j crosses i or becomes equal to i.

                              j i
                            0 1 2 3 4 5 6 7 8 9
Unsorted Array              2 1 3 9 4 4 8 7 5 6 
                        pivot was at ind 0
As j crossed i while searching, we followed the final step of swapping the pivot element and the element at j.

                            0 1 2 3 4 5 6 7 8 9
Unsorted Array              1 2 3 9 1 4 8 7 5 6 
                here    pivot is at ind 1

And this would be the final position of the current pivot even in our sorted array. 
As you can see, all the elements smaller than 2 are on the left, and the rest greater than 2 are on the right.
Here comes the role of divide and conquer. We separate our focus from the whole array to just the subarrays, which are not sorted yet. 
 Here, we have subarrays {1} and {3, 9, 4, 4, 8, 7, 5, 6} unsorted. So, we make a call to quicksort on these two subarrays.
Now since the first subarray has just a single element, we consider it sorted. Let’s now sort the second subarray. Follow all the partition steps from the beginning.

Now, our new pivot is the element at index 2. And i  and j  are 2 and 9, respectively, 
marking the start and the end of the subarray. Follow steps 3 and 4.

for more notes refer notes ;p

*/


#include<stdio.h>
#include<stdlib.h>

void printArray(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int *arr, int low , int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    int temp;

    do
    {
        while (arr[i]<=pivot)       //i.e. jabtak arr[i] ki value pivot se kam ya equal hai aage badhte jaao!! Jaise hi arr[i] Greator than pivot hogi rukk jaao
        {
            i++;
        }
        while (arr[j]>pivot)        //i.e. jabtak arr[j] ki value pivot se zyada hai move krte raho, jaise hi EQUAL ya lesser value then pivot mila RUKK jao
        {
            j--;
        }
        if (i<j)                //IMPORTANT if i<j 
        {
            temp = arr[i];
            arr[i]= arr[j];
            arr[j] = temp;
        }
    } while (i<j);      //jabtak i<j hai tabtak i and j ko iss tarah swap karte raho! toh by the end ALL ELEMENTS greator than pivot will be at RIGHT and less than pivot will be at LEFT4
    //BUT all these elements are still at Right of pivot 
    //So now once j>i: we'll shift pivot such That all greator than pivot will be right OF PIVOT and lesser than pivot will be left OF PIVOT 
    
    if (i>j)            //IMPORTAnt IT IS : IF i>j
    {
        temp = arr[low];        //dont swap(pivot, arr[j]) because hame pivot ko thodi change krna hai hame toh uss index pr present element ko swap krna hai
        arr[low] = arr[j];     //swapping 'element at pivot' with j (less than pivot)
        arr[j] = temp;
    }
    return j;       //that is returning the index jaha ABHI PIVOT wala element swap hone ke baad baitha hai/ basically, j = partial sort ke baad pivot ka index
}


void quickSort(int *arr, int low, int high){
    int pivotIndex;
    // printArray(arr, 7);   //to see how it is working
    if (low<high)   //jaise hi low and high index same hogaye it means only one element left in the array Hence, stop sorting further
    {
        pivotIndex = partition(arr, low, high);     //ek baar partition krke we achieved the following:
                                                            //Elements less than pivot on its left 
                                                            //Elements greator than pivot on its right
                                                            //They are not sorted yet, they are just arranged as above form , this is called Partial Sort, when we repeat this it eventually sorts whole array
        quickSort(arr, low, pivotIndex-1);      //Sorts Left sub Array
        quickSort(arr, pivotIndex+1, high);     //Sorts Right sub Array
    }
    

    
}

int main(){
    int arr[] = {2,42,1,32,23,3,9};
    int size = sizeof(arr)/sizeof(int);
    printArray(arr, size);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
    return 0;
}