/*MERGE SORT
here we merge Two Already Sorted Arrays
eg. a = {1,5,9,16}        b = {2,3,4,4,6,7,90,91}
then c = {1, 2, 3, 4, 4, 5, 6, 7, 9, 16, 90, 91}


I would like to give you the reason why we call it the merge sort algorithm. 
In this algorithm, we divide the arrays into subarrays and subarrays into more subarrays 
until the size of each subarray becomes 1. Since arrays with a single element are always 
considered sorted, this is where we merge. Merging two sorted subarrays creates another 
sorted subarray. I’ll show you first how merging two sorted subarrays works.

Procedure:
And we apply merging on them. Then the first job would be to create another array C 
with size being the sum of both the raw arrays’ sizes. Here the sizes of A and B are 5 and 4, 
respectively. So, the size of array C would be 9.
Now, we maintain three index variables i, j, and k. i looks after the 
first element in array A, j looks after the first element in array B, and k looks after 
the position in array C to place the next element in.
Initially, all i, j, and k are equal to 0.
Now, we compare the elements at index i of array A and index j of array B and see which one is smaller. Fill in the smaller element at index k of array C and increment k by 1. Also, increment the index variable of the array we fetched the smaller element from.
Here, A[i] is greater than B[j]. Hence we fill C[k] with B[j] and increase k and j by 1.
We continue doing step 5 until one of the arrays, A or B, gets empty.
Here, array B inserted all its elements in the merged array C.
 Since we are only left with the elements of element A, we simply put them in the merged array as they are. This will result in our final merged array C.




*/
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    } 
    printf("\n");
}

void mergeSort(int *a, int *b, int *c, int sizea, int sizeb){
    int i, j, k;
    i = j = k = 0;

    while (i<sizea && j<sizeb)
    {
        if (a[i]<b[j])
        {
            c[k]= a[i];
            i++; k++;
        }
        else{
            c[k]= b[j];
            j++; k++;
        }
    }
    while(i<sizea)
    {
        c[k]= a[i];
        k++; i++;
    }
    while(j<sizeb){
        c[k] = b[j];
        k++; j++;
    }
}


int main(){
    int a[]= {2,3,4,4,6,7,90,91};
    int sizeOfa = sizeof(a)/sizeof(int);
    int b[]= {1,5,9,16};
    int sizeOfb = sizeof(b)/sizeof(int);
    int c[sizeOfb+sizeOfa];

    mergeSort(a, b, c,sizeOfa, sizeOfb);
    printArray(c, sizeOfa+sizeOfb);
    return 0;
}


// // // MERGE SORT FOR MERGING IN A SINGLE ARRAYY!!!!!:

// // #include<stdio.h>
// // #include<stdlib.h>

// // void printArray(int *array, int size){
// //     for (int i = 0; i < size; i++)
// //     {
// //         printf("%d ", array[i]);
// //     }
// //     printf("\n");
// // }

// // void mergeSA(int *A, int low, int mid , int high){
// //     int i , j , k;
// //     k = 0;
// //     i = low;
// //     j = mid+1;
// //     int B[high+1];
// //     while (i<mid && j<high)
// //     {
// //         if (A[i]<A[j])
// //         {
// //             B[k]= A[i];
// //             i++; k++;
// //         }
// //         else{
// //             B[k] = A[j];
// //             j++; k++;
// //         }
// //     }
// //     while (i<=mid)
// //     {
// //         B[k] = A[i]; 
// //         k++; i++;
// //     }
// //     while (j<high)
// //     {
// //         B[k] = A[j];
// //         k++; j++;
// //     }
// //     printArray(B, high);
// // }

// // int main(){
// //     int arr[] = {7,8,18,19,22,1,6,9,11};
// //     int size = sizeof(arr)/sizeof(int);

// //     printArray(arr, size);
// //     mergeSA(arr, 0, 4, size);
    
// //     return 0;
// // }


// //RECURSIVE MERGE SORT!     //do it again this is NOT GETTING answer!

// #include<stdio.h>
// #include<stdlib.h>

// void printArray(int *arr, int size){
//     for (int i = 0; i < size; i++)
//     {
//         printf("%d ", arr[i]);
//     } 
//     printf("\n");
// }



// void merge(int *A, int low, int mid , int high){
//     int i , j , k;
//     k = 0;
//     i = low;
//     j = mid+1;
//     int B[high+1];
//     while (i<mid && j<high)
//     {
//         if (A[i]<A[j])
//         {
//             B[k]= A[i];
//             i++; k++;
//         }
//         else{
//             B[k] = A[j];
//             j++; k++;
//         }
//     }
//     while (i<=mid)
//     {
//         B[k] = A[i]; 
//         k++; i++;
//     }
//     while (j<high)
//     {
//         B[k] = A[j];
//         k++; j++;
//     }
//     // printArray(B, high);
// }


// void msRecursive(int A[], int low, int high){
//     int mid;
//     if (low<high)
//     {
//         mid = (low+high)/2;
//         msRecursive(A, low, mid);
//         msRecursive(A, mid+1, high);
//         merge(A, low, mid, high);
//     }
// }

// int main(){
//     int A[]= {7,1,2,8};
//     int size = sizeof(A)/sizeof(int);
//     printArray(A, size);
//     msRecursive(A, 0, size);
//     return 0;
// }