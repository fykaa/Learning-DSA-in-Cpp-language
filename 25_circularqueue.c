/*CIRCULAR QUEUE
    In linear queue Dequeuing leaves vacant spaces behind, hence space is not utilised efficiently and can't be reused!
    In circular queues, we mainly focus on the point that we don’t increment our indices linearly. 
    Linearly increasing indices cause the case of overflow when our index reaches the limit, which is size-1. 
    In linear increment, i becomes i+1.
    But in a circular increment ; i becomes (i+1)%size. 
    This gives an upper cap to the maximum value making the index repeat itself

    Linear Increment:   0,1,2,3,4,5,6,7,8,9,........
    Circular Increment: 0,1,2,3,4,0,1,2,3,4,0...    //This allows the leftover spaces to be used again
    (for size 5)

    //i.e. if now i = 1 then next postion will be 
            // = (i+1)%size 
            // = (1+1)%6        (TAKING SIZE 6)
            // = 2%6 = 2  // matlab 1 ke baad 2...
            // (i+1)%size
            // (1+1)%6 = 2
            // (2+1)%6 = 3
            // (3+1)%6 = 4
            // (4+1)%6 = 5
            // (5+1)%6 = 0  SO HERE YOU GO AGAIN ON THE INDEX 0 AND HENCE THIS Way you creaet a circular loop where space is used more effeciently
            // (6+1)%6 = 1
            // (7+1)%6 = 2


*/

#include<stdio.h>
#include<stdlib.h>

struct circular_queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull( struct circular_queue *q){
    if ( (q->r+1)% q->size == q->f) //IMPORTANT :  == q->f NOT q->size-1
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct circular_queue *q){
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circular_queue  *q, int value){
    if (isFull(q))
    {
        printf("Queue Overflow, can't insert %d\n", value);
    }
    else{
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = value;
        printf("Enqued element %d \n", value);
    }
}


int dequeue(struct circular_queue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
    }
    else{
        q->f = (q->f + 1)% q->size;
        value = q->arr[q->f];
    }
    return value;
}
int main(){
    struct circular_queue q;
    q.size = 3;         //size is 3 matlab sirf 2 elements daal sakte ho
    q.f = q.r = 0;          //WATCH YAAA!! 
                                //here starting mein hi f ko 0 rakhna hoga kyuki abb in circular queue you wont have -1 
                                // if you do q.f = -1; and keep adding elements TOH QUEUE KABHI FULL HI NAHI HOGI !!!!
                                    //KYUKI  if q.f = -1 then       (q->r+1)% q->size WILL NEVER BE EQUAL to q->f (which is condition for isFull)
                                    // FOR detailed explanation watch last 5 minutes of C code for Circular Queue & operations on circular queue.
                    
    q.arr = (int*)malloc(q.size* sizeof(int));
// FIRST COME FIRST LEAVE
    enqueue(&q, 12);
    enqueue(&q, 56);
    enqueue(&q, 98);        //ye toh OVERFLOW KAR GAYA           
    printf("Dequeing element %d\n", dequeue(&q));
    printf("Dequeing element %d\n", dequeue(&q));
    enqueue(&q, 74);        //look now you're able to add in the queue unlike in Linear Queue , after dequeing you can reuse the spaces in the queue
    enqueue(&q, 97);
    return 0;
}