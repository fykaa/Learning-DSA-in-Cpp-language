// //VERY IMPORTANT
//     //using linear search you transverse the whole array , which hence requires more time , and increases time complexity, WHEREAS in binary search you keep reducing the search to half and hence time complexity reduces from n to logn

// #include<stdio.h>
// int binarysearch(int arr[], int size, int element){
//     int low, mid, high;
//     low = 0;
//     high = size - 1;
    
//     while (low<=high)
//     {
//         mid = (low+high)/2;
//         if (arr[mid]== element)
//         {
//             return mid;
//         }
//         if (element>arr[mid])
//         {
//             low = mid+1;
//         }
//         else{
//             high = mid-1;
//         }
//     }
//     return -1;      //worst case , jab poore array meinn na mile, i.e. O(logn)
// }
// int main()
// {
//     int arr[]={1,2,3,4,5,6,7,8,9,10,11,34,38,39,47,57,76,96,99};
//     int size = sizeof(arr)/sizeof(int);
//     int element = 2, index;
//     // printf("The size of array is %d", size);
//     index = binarysearch(arr, size, element);
//     printf("element %d is at index %d", element, index);
//     return 0;
// }




//by me while revising:
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    } 
    printf("\n");
}

int binarySearch(int *arr, int size , int element){
    int low = 0;
    int high = size-1;
    
    while (low<= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (element>arr[mid])
        {
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
    
}

int main(){
    int a[] = {2,4,6,7,84,5,3,2,88,5,3,9,2};
    int elm = 9;
    int size = sizeof(a)/sizeof(int);
    printArray(a, size);
    printf("The element %d is present at index %d\n",elm, binarySearch(a, size, elm));
    return 0;
}