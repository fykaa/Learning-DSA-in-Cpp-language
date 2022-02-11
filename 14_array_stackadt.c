// //ADT (hidden details)  = SET OF VALUES+ SET OF OPERATIONS

// //-- MEMORY LAYOUT--> CODE+ INITIALISED/UNITIALISED DATA + STACK + HEAP



// // STACK ADT
//     //-Stack as Array           (folder mein file 14 to 17)
//     //-Stack as Linked List     (file 18 se dekh)

// //CODING STACK IN ARRAY


// #include<stdio.h>
// #include<stdlib.h>
// struct Stack{
//     int size;   //No. of elements Array can have
//     int top;    //Index of Last(topmost) element in the Array
//     int* arr;   //Int* because we're gona request this array in heap
// };

// int isEmpty(struct Stack *ptr){
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     return 0;
// }
// int isFull(struct Stack *ptr){
//     if (ptr->top == (ptr->size - 1))
//     {
//         return 1;
//     }
//     return 0;
// }
// int main()
// {
//     // struct Stack *s;    //with NOT using *s 
//     // s.size = 6;
//     // s.top = -1;
//     // s.arr = (int*)malloc(s.size*sizeof(int));  

//     struct Stack *s;    //Using *s helps us to do CALL BY REFERENCE and pass this pointer to a function!
//     s->size = 6;
//     s->top = -1;
//     s->arr = (int*)malloc(s->size*sizeof(int));
    
//     if (isEmpty(s))
//     {
//         printf("Empty Stack\n");
//     }
//     else{
//         printf("Stack Not Empty\n");
//     }
//     if (isFull(s))
//     {
//         printf("Stack FULL\n");
//     }
//     else{
//         printf("Stack not full\n");
//     }
//     return 0;
// }





/*THIS CONTAINS ALL THE OPERATIONS WE LEARNT IN STACK ARRAY:
1. isEmpty
2. isFull
3. push
4. pop
5. peek
6. stackTop
7. stackBottom

*/
#include<stdio.h>
#include<stdlib.h>
//creating Stack
struct Stack{
    int size;
    int top;
    int*arr;
};

//checks if stack is Empty
int isEmpty(struct Stack *ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

//checks if stack is full
int isFull(struct Stack *ptr){
    if (ptr->top == (ptr->size -1))
    {
        return 1;
    }
    return 0;
}

//Put elements in stack
void push(struct Stack *ptr, int value){
    if (isFull(ptr))
    {
        printf("Stack Overflow for %d\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]= value;
    }
}

//remove element from stack
int pop(struct Stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

//gives value at a position in the stack
int peek(struct Stack *ptr, int i){
    int arrayIndex = ptr->top -i+1;
    if (arrayIndex <0)      //to check if this peeking position is not at an index of the array that doesn't exists i.e. index below 0
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return ptr->arr[arrayIndex];
    }
}

//gives the last inserted (topmost element) of stack
int stackTop(struct Stack *ptr){
    return ptr->arr[ptr->top];
}

//gives the first inserted (bottommost element) of stack
int stackBottom(struct Stack *ptr){
    return ptr->arr[0];
}


int main(){
    
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));

    s->top = -1;
    s->size = 5;
    s->arr = (int*)malloc(s->size * sizeof(int));

    printf("Before Pushing, FULL: %d\n", isFull(s));  //if full then 1, else 0
    printf("Before Pushing, EMPTY: %d\n", isEmpty(s)); //if empty then 1, else 0
    push(s, 56);    //bottom element
    push(s, 566);
    push(s, 57);
    push(s, 58);
    push(s, 59);    //top element
    push(s, 22);
    printf("\n");

    printf("After Pushing FULL: %d\n", isFull(s));  
    printf("After Pushing EMPTY: %d\n", isEmpty(s));

    printf("Popped %d from the stack ", pop(s)); 

    printf("Hence %d is NOW the topmost element\n", s->arr[s->top]);

    printf("The element at Index %d is %d \n", 3, peek(s, 3));

    printf("The topmost element is %d\n", stackTop(s));
    printf("The bottom element is %d", stackBottom(s));
    return 0;
}