/*
QUEUE - Insertion from Rear & Deletion from Front
DE Queue - Insertion from Rear OR Front SIDE / Deletion from Rear or Front SIDE !

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
2. Restricted Output DE Queue- deletion read not allowed

*/


// this code is totally written by me
        //here i am facing a problem in :

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