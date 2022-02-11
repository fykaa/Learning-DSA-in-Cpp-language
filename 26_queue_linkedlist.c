/* // CREATING QUEUE (first in first out) USING LINKED LIST
// this is one of the most important concepts asked in interviews

Linked lists are chain-like structures with nodes having two parts, an integer variable to hold data and another node pointer to hold the address of the next node. 
 The last node points to NULL. And the first node is called the head.

Moving to the basics of a queue, a queue represents a line or sequence of elements where the elements follow the FIFO discipline. 
The element inserting the first gets removed the first. We maintained two index variables, f, and r, to mark the beginning and the end of the queue. 

Since we are implementing this queue using a linked list, the index variables are no longer integers. 
These become the pointers to the front and the rear nodes.


Enqueue in a queue linked list:

Enqueuing in a queue linked list is very much similar to just inserting at the end in a linked list. 
As we discussed this thoroughly in our past lectures, you should not find this difficult. Inserting a new node at the end requires you to follow few steps:
   1. Check if there is a space left in the heap for a new node.
   2. If there is, create a new node n, assign it memory in heap, and fill its data with the new value the user has given.
   3. Point the next member of this new node n to NULL, and point the next member of the r to n. And make r equal to n. And we are done.
   4. There is one exception here. When we insert the first element, both f and r are pointing to NULL. So, instead of just making r equal to n, we make f equal to n as well. This marks the beginning of the list.

Dequeue in a queue linked list:

Dequeuing in a queue linked list is very much similar to deleting the head node in a linked list. Deleting the head node from the list requires you to follow few steps:
    1. Check if the queue list is already not empty using the isEmpty function.
    2. If it is, return -1. Else create a new node ptr and make it equal to the f node. And don’t forget to store the data of the f node in some integer variable.
    3. Make the f equal to the next member of f, and free the node ptr. Return the value you stored.


Condition for isEmpty:
The only condition for the queue linked list to be empty is that the f node is NULL, which means there is no beginning, hence no element.

Condition for isFull:
Queues implemented using linked lists never usually become full until the space in the heap memory is exhausted. 
Therefore, the only condition for the queue linked list to be full is that the new node becomes NULL when created.


*/

#include <stdio.h>
#include <stdlib.h>

// Creating Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Creating a Front and Rare Pointing Node
// here we are making these two nodes GLOBAL element
struct Node *f = NULL;
struct Node *r = NULL;

void linkedlistTraversal(struct Node *ptr)
{
    if (f == NULL)
    {
        printf("NO ELEMENT\n");
    }
    else
    {
        printf("Printing Elements of Linked list: ");
        while (ptr != NULL)
        {
            printf("%d, ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n\n");
    }
}
void enqueue(int value)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    // struct Node *n-- YAHA STAR aaya kyuki ham is NODE n ko ek POINTER banana chahte hai
    //(struct Node*)--YAHA star aaya BECAUSE WE ARE TYPECASTING THIS NODE IN A STRUCT NODE STAR POINTER!!!!!!!!!!!!
    // sizeof(struct Node);-- YAHA no star because hame structure ka size lena hai (pointer ka nahi)

    if (n == NULL) // that is abb aap node banarahe ho to vo nahi bann raha hai/ NULL bann raha hai
    {
        printf("Queue is Full\n");
    }
    else
    {
        n->data = value;
        n->next = NULL;
        if (f == NULL)
        {              // this is the case where there exists NO elements yet in the LL QUEUE isliye we won't be able to say ki r->next ye hai, f ka next vo hai .         {
            f = r = n; // SO, IN THE CASE WHERE THERE DIDNT EXISTED ANY ELEMENT ALREADY IN THE QUEUE, THE FRONT RARE AND N Nodes are all pointing at N.
        }
        else
        {
            r->next = n;
            r = n;
        }
        printf("Enqueued element %d\n", n->data);
    }
}

int dequeue()
{
    int value = -1;       // this is done so that agar kuch return nahi hua (in case of empty queue) toh atleast -1 return hojaye depicting ki queue is empty. and if queue is not empty toh change toh ham khud hi karege
    struct Node *ptr = f; // doing this JUST so that we can free the deleted data from the memory after deleting it ! toh dequeue karne ke baad we can free element at ptr(now front)
    if (f == NULL)
    {
        printf("Can't pop because queue is empty\n");
    }
    else
    {
        f = f->next;
        value = ptr->data;
        free(ptr);
        printf("Dequeued elememt %d\n", value);
        return value;
    }
}

int main()
{
    linkedlistTraversal(f);

    enqueue(23);
    enqueue(53);

    linkedlistTraversal(f);

    dequeue(); // prooves FIRST IN FIRST OUT, i.e. we made a queue
    dequeue();

    linkedlistTraversal(f);
    return 0;
}