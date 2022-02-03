// #include<stdio.h>
// #include<stdlib.h>

// void printArray(int *array, int n){
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", array[i]);
//     }
//     printf("\n");
// }

// void bubblesort(int *array, int size ){
//     for (int i = 0; i < size -1; i++)           //For loop for no. of Passes - no. of passes = size-1
//     {
//         printf("Pass No. %d\n",i+1 );
//         for (int j = 0; j < size - 1 - i; j++)  //For loop for Comparison in each pass
//         {
//             if (array[j]> array[j+1])
//             {
//                 int temp;
//                 temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//             }
//         }
//     }
// }

// void bubblesortAdaptive(int *array, int size){
//     for (int i = 0; i < size -1; i++)
//     {
//         printf("Pass No. %d\n", i+1);
//         int isSorted = 1;
//         for (int j = 0; j < size -1 -i; j++)
//         {
//             if (array[j]> array[j+1])
//             {
//                 int temp;
//                 temp = array[j];
//                 array[j] = array[j+1];
//                 array[j+1] = temp;
//                 isSorted =0;
//             }
//         }
//         if (isSorted)
//         {
//             return;
//         }
//     }
// }

// int main(){
//     int arr[] = {1,3,75,5,2,4,6};
//     int size = sizeof(arr)/ sizeof(int);
//     printArray(arr, size);
//     // bubblesort(arr, size);
//     bubblesortAdaptive(arr, size);
//     printArray(arr, size);
//     return 0;
// }