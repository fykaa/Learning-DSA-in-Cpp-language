//WAY 1
// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node *next;
// };

// void linkedListTraversal(struct Node *top){
//     struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr  = top;
//     while (ptr != NULL)
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("\n");
// }

// int isEmpty(struct Node *top){
//     if (top == NULL)
//     {
//         return 1;
//     }
//     return 0;
// }

// int isFull(struct Node *top){
//     struct Node *s = (struct Node*)malloc (sizeof(struct Node));
//     if (s == NULL)
//     {
//         return 1;
//     }
//     return 0;
// }

// struct Node* push(struct Node *top, int value){
//     if (isFull(top))
//     {
//         printf("Overflow\n");
        
//     }
//     else{
//         struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//         ptr->data = value;
//         ptr->next = top;
//         return ptr;
//     }
// }

// int pop(struct Node **top){
//     if (isEmpty(*top))
//     {
//         printf("empty\n");
//     }
//     else{
        
//         struct Node *s = *top;
//         int value = s->data;
//         *top = s->next;
//         free(s);
//         return value;
//     } 
// }

// int main(){
//     struct Node *top = NULL;
//     top = push(top, 23);
//     top = push(top, 32);
//     top = push(top, 86);
//     top = push(top, 82);

//     linkedListTraversal(top);
//     printf("POPPED OUT %d from the LINKED LIST STACK\n", pop(&top));  
//     linkedListTraversal(top);    
//     return 0;
// }


//WAY 2
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* top = NULL;        //created a global variable

void traversal(struct Node *top){
    struct Node *ptr = top;
    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}
int isEmpty(struct Node *top){
    if (top == NULL)
    {
        return 1;
    }
    else{
        return 0;
    }   
}

int isFull(struct Node *top){
    struct Node *n  = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node* push(struct Node * top, int value){
    if (isFull(top))
    {
        printf("Stack Overflow\n");
    }
    else{
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = value;
        ptr->next = top;
        return ptr;
    }
}

int pop(struct Node * top2){        //changed name of the variable
    if (isEmpty(top2))
    {
        printf("Stack Underflow\n");
    }
    else{
        struct Node *n = top2;
        int c = n->data;
        top = n->next;
        free(n);
        return c;
    }
    
}

int main(){
    top = push(top, 34);
    top = push(top, 43);
    top = push(top, 98);
    top = push(top, 29);
    traversal(top);
    printf("lets pop %d \n", pop(top));
    traversal(top);

    return 0;
}