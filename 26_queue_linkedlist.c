//CREATING QUEUE (A structure which adds element at front , and removes elements from behind) USING LINKED LIST
    //this one of the most important concepts asked in interviews

#include<stdio.h>
#include<stdlib.h>

//Creating Linked List
struct Node{
    int data;
    struct Node *next;
};

//Creating a Front and Rare Pointing Node
    //here we are making these two nodes GLOBAL element
struct Node *f = NULL;
struct Node *r = NULL;

void linkedlistTraversal(struct Node *ptr){
    if (f == NULL)
    {
        printf("NO ELEMENT\n");
    }
    else{
        printf("Printing Elements of Linked list: ");
        while(ptr != NULL){
            printf("%d, ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}
void enqueue(int value){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
                                                                            //struct Node *n-- YAHA STAR aaya kyuki ham is NODE n ko ek POINTER banana chahte hai
                                                                            //(struct Node*)--YAHA star aaya BECAUSE WE ARE TYPECASTING THIS NODE IN A STRUCT NODE STAR POINTER!!!!!!!!!!!!
                                                                            //sizeof(struct Node);-- YAHA no star because hame structure ka size lena hai (pointer ka nahi)

    if (n == NULL)      //that is abb aap node banarahe ho to vo nahi bann raha hai/ NULL bann raha hai
    {
        printf("Queue is Full\n");
    }
    else{
        n->data= value;
        n->next = NULL;
        if (f==NULL){        //this is the case where there exists NO elements yet in the LL QUEUE isliye we won't be able to say ki r->next ye hai, f ka next vo hai .         {
            f = r = n;          //SO, IN THE CASE WHERE THERE DIDNT EXISTED ANY ELEMENT ALREADY IN THE QUEUE, THE FRONT RARE AND N Nodes are all pointing at N.
        }
        else{
            r->next = n;
            r = n;
        }
        printf("Enqueued element %d\n", n->data);
    }
}

int dequeue(){
    int value = -1;     //this is done so that agar kuch return nahi hua (in case of empty queue) toh atleast -1 return hojaye depicting ki queue is empty. and if queue is not empty toh change toh ham khud hi karege
    struct Node *ptr = f;   //doing this JUST so that we can free the deleted data from the memory after deleting it ! toh dequeue karne ke baad we can free element at ptr(now front)
    if (f == NULL)
    {
        printf("Can't pop because queue is empty\n");
    }
    else{
        f = f->next;
        value = ptr->data;
        free(ptr);
        printf("Dequeued elememt %d\n", value);
        return value;
    }
}


int main(){
    linkedlistTraversal(f);

    enqueue(23);
    enqueue(53);
    
    linkedlistTraversal(f);

    dequeue();  //prooves FIRST IN FIRST OUT
    dequeue();

    linkedlistTraversal(f);
    return 0;
}