// #include<stdio.h>
// int linearsearch(int arr[], int element, int size){
//     for (int i = 0; i <=size; i++)  //so here this is Linear search AS VALUE OF i is increasing linearly from 0 to size hence checking each element one after other!!!
//     {
//         if (arr[i]==element)
//         {
//             return i;
//         }
//     }
//     return -1;       //worst case , jab poore array meinn na mile, i.e. O(n)
// }
// int main()
// {
//     int arr[100]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21};
//     int size = sizeof(arr)/sizeof(int);
//     int element, capacity = 100, index ;
//     printf("You want to find element?\n");
//     scanf("%d", &element);
//     index =  linearsearch(arr, element, size);
//     printf("Element %d is at index %d\n", element, index);
//     return 0;
// }


//BY ME
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    } 
    printf("\n");
}

int search(int *arr, int element , int size){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}


int main(){
    int A[] = {2,423,42,5,67,8,4,63,5,9,8,0,62,41,231,2,31,};
    int size = sizeof(A)/sizeof(int);
    printArray(A, size);
    printf("The element %d is present at %d index in the array\n", 5, search(A, 5, size));
    return 0;
}