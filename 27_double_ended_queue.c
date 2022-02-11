/*
QUEUE - Insertion from Rear & Deletion from Front
DE Queue - Insertion from Rear OR Front SIDE / Deletion from Rear or Front SIDE !

We had certain characteristics in normal queues, which I would like to summarize here:
1.A queue is very similar to the real-life queue, where you stand in the last and wait for your turn.
2.Similarly, the elements get inserted from one end and exit from the other. 
3.We had two pointers cum index variables to maintain the two ends of this queue.
4.We followed the FIFO principle throughout the lectures.

And now, in DEQueue, we don’t follow the FIFO principle. As the name suggests, this variant of the queue is double-ended. 
This means that unlike normal queues where insertion could only happen at the rear end, and deletion at the front end, 
these double-ended queues have the freedom to insert and delete elements from the end of their choice.


Double-ended queues, hence, have the following characteristics:
They don't follow the FIFO discipline.
Insertion can be done at both the ends of the queue.
Deletion can also be done from both ends of the queue.
You would assume the implementation part of double-ended queues to be on the tough side, but believe me, it is straightforward to consume. 
I’ll use illustrations to make you understand things better.

Operations of DE QUEUE :
isempty
isfull
peek
enqueuefront()
enqueuerear()
dequeuefront()
dequeueread()

Types of DE QUEUE :
1. Restricted Input DE Queue- insertion at front is not allowed
2. Restricted Output DE Queue- deletion rear not allowed

*/


// this code is totally written by me
        //here i am facing a problem ONLY in printing the element dequeued at rear, vo value nahi bata paa raha\other wise all good :

#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isrearFull(struct queue *q){
    if (q->r == q->size -1)       //i.e. when last element is at size-1 (i.e. last) index
    {
        return 1;
    }
    return 0;
}

int isfrontFull(struct queue *q){
    if (q->f == -1)       //i.e.when front is pointing at -1 (which means front end par bhi element insert karne ki jagah nahi hai)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *s){
    if (s->f == s->r)
    {
        return 1;
    }
    return 0;
}

void enqueuefront(struct queue *q, int value){
    if (isfrontFull(q))
    {
        printf("Front side is Full , can't add at front\n");
    }
    else{
        q->f--;
        q->arr[q->f] = value;
        printf("Enqued %d at Front\n", q->arr[q->f]);
    }
}

void enqueuerear(struct queue *q, int value){
    if (isrearFull(q))
    {
        printf("Rear side is Full , can't add %d at rear\n" , value);
    }
    else{
        q->r++;
        q->arr[q->r] = value;
        printf("Enqued %d at Rear\n", q->arr[q->r]);
    }
}

int dequeuefront(struct queue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("Front side is Empty , can't remove from front\n");
    }
    else{
        q->f++;
        value = q->arr[q->f];
        printf("Dequeued %d at Front\n", value);
    }
    return value;
}

int dequeuerear(struct queue *q){
    int value = -1;
    if (isEmpty(q))
    {
        printf("Rear side is Empty , can't remove from Rear end\n");
    }
    else{
        q->r--;
        value = q->arr[q->r];
        printf("Dequeued %d at Rear\n", value);
    }
    return value;
}
int main(){
    struct queue q ;
    q.size = 2; //can accept only 2 elements
    q.f = -1;
    q.r = -1;
    q.arr = (int*)malloc(q.size* sizeof(int));
    //ENQUEUE DEQUEUE AT REAR:
    enqueuerear(&q, 12);
    enqueuerear(&q, 76);
    enqueuerear(&q, 87);
    dequeuerear(&q);
    dequeuerear(&q);
    enqueuerear(&q, 98);
    enqueuerear(&q, 66);
    enqueuerear(&q, 96);
    dequeuerear(&q);
    dequeuerear(&q);
    dequeuerear(&q);
    //queue is empty now
    printf("\n\n");
    //ENQUEUE DEQUEUE AT FRONT:

    enqueuerear(&q, 98);    //ye rear pr add krre ham
    enqueuerear(&q, 66);

    dequeuefront(&q);   //you see here that element 98 (jo ki frontal side par tha vo pehle dequeue hua)
    dequeuefront(&q);
    dequeuefront(&q);

    enqueuefront(&q, 12);
    enqueuefront(&q, 76);
    enqueuefront(&q, 87);
    return 0;
}