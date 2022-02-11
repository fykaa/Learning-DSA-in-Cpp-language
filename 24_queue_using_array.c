/*
Today, we will start a new data structure named queue.
Queue is just like We stand in a queue while waiting for our turn to come.

Unlike stacks, where we followed LIFO( Last In First Out ) discipline,
here in the queue, we have FIFO( First In First Out).

In stacks, we had to maintain just one end, head, where both insertion and deletion used to take place, and the other end was closed.
But here, in queues, we have to maintain both the ends because we have insertion at one end and deletion from the other end.


Queue ADT
Data:
In order to create a queue, we need two pointers,
    one pointing to the insertion end, to gain knowledge about the address where the new element will be inserted to.
    And the other pointer pointing to the deletion end, which holds the address of the element which will be deleted first.
    Along with that, we need the storage to hold the element itself.

Methods:
Here are some of the basic methods we would want to have in queues:
1. enqueue() : to insert an element in a queue.
2. dequeue(): to remove an element from the queue
3. firstVal(): to return the value which is at the first position.
4. lastVal(): to return the value which is at the last position.
5. peek(position):  to return the element at some specific position.
6. isempty() / isfull(): to determine whether the queue is empty or full, which helps us carry out efficient enqueue and dequeue operations.

A queue can be implemented in a number of ways.
    We can use both an 1)Array and a 2)Linked list and even a 3)Stack, and not just that, but by 4)Any ADT.


A queue is a collection of elements with certain operations following FIFO (First in First Out) discipline.
    We insert at one end and delete from the other.
    And this is what you have to keep in mind for now.




//ENQUEUE:
    Here, we’ll maintain an index variable, backInd, to store the index of the rearmost element.
    So, when we insert an element, we just increment the value of the backInd and insert the element at the current backInd value.

//DEQUEUE:
    since a queue follows the FIFO discipline, we can only remove the element at the zeroth index, as that is the element inserted first in the queue.
    So, now we will remove the element at the zeroth index and shift all the elements to its adjacent left.
    But this removal of the zeroth element and shifting of other elements to their immediate left features O(n) time complexity. (cause we are shifting literally all elements to left after deleting which is time consuming)

STEPS:

1. Insertion( enqueue ):
    Increment backInd by 1.
    Insert the element
    Time complexity: O(1)

2. Deletion( dequeue ):
    Remove the element at the zeroth index
    Shift all other elements to their immediate left.
    Decrement backInd by 1
    Time complexity: O(n)

3. Here, our first element is at index 0, and the rearmost element is at index backInd (r).

4. Condition for queue empty: backInd = -1.

5. Condition for queue full: backInd = size-1.

/////////////////////////////////////////////////////////////////

Can there be a better way to accomplish these tasks? The answer is yes.
We can use another index variable called frontInd f, which stores the index of the cell JUST before the first element.
We’ll maintain both these indices to bring about all our operations. Let’s now enlist the changes we’ll see after we introduce this new variable:


STEPS
1. Insertion( enqueue ):
    Increment backInd by 1.
    Insert the element
    Time complexity: O(1)

2. Deletion( dequeue ):
    Remove the element at the zeroth index( no need for that in an array )
    Increment frontInd by 1.
    Time complexity: O(1)

3. Our first element is at index frontInd +1, and the rearmost element is at index backInd.

4. Condition for queue empty: frontInd = backInd.

5. Condition for queue full: backInd = size-1.

Now, we were able to achieve both operations in constant run time O(1). And the new dequeue operation goes as follow:
*/
#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size; // size of queue
    int f;    // f is for front end ->this will store Deletion end ka index
    int r;    // r is for rarer/backend ->this will store Insertion end ka index
    int *arr; // Here is that WE ARE CREATING QUEUE using arrays
};

int isFull(struct Queue *s)
{
    if (s->r == s->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *s)
{
    if (s->f == s->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q)) // yaha &q mat likho because already * form mein jaaraha hai!!!
    {
        printf("Queue Overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;     // a basically stores the "value of element at index of frontInd"
    if (isEmpty(q)) // yaha &q mat likho because already * form mein jaaraha hai!!!
    {
        printf("Queue Underflow\n");
    }
    else
    {

        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

// traversal function by me:
void traversal(struct Queue *q)
{
    for (int i = q->f + 1; i < q->r + 1; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not Empty anymore\n");
    }

    // Enqueue few elements
    enqueue(&q, 23); //&q use kiya because enqueue function ek address accept karraha hai!! and original Queue we created is not a pointer hence hame & likhna padega!
    enqueue(&q, 33);
    enqueue(&q, 233);
    enqueue(&q, 422);
    enqueue(&q, 983);
    enqueue(&q, 73);
    enqueue(&q, 63);

    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not Empty anymore\n");
    }

    printf("Dequeuing element %d\n", dequeue(&q));

    printf("Dequeuing element %d\n", dequeue(&q));
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not Empty anymore\n");
    }
    traversal(&q);
    return 0;
}
