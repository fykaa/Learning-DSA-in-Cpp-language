#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;       //size of queue
    int f;          //this will store Insertion end ka index 
    int r;          //this will store Deletion end ka index
    int *arr;       //Here is that WE ARE CREATING QUEUE using arrays
};

int isFull(struct Queue *s){
    if (s->r == s->size-1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *s){
    if (s->f == s->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int value){
    if (isFull(q))      //yaha &q mat likho because already * form mein jaaraha hai!!!
    {
        printf("Queue Overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if (isEmpty(q))     //yaha &q mat likho because already * form mein jaaraha hai!!!
    {
        printf("Queue Underflow\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main(){
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size* sizeof(int));
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue is not Empty anymore\n");
    }
    
    //Enqueue few elements
    enqueue(&q, 23);        //&q use kiya because enqueue function ek address accept karraha hai!! and original Queue we created is not a pointer hence hame & likhna padega!
    // enqueue(&q, 33);
    // enqueue(&q, 233);
    // enqueue(&q, 422);
    // enqueue(&q, 983);
    // enqueue(&q, 73);
    // enqueue(&q, 63);

    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue is not Empty anymore\n");
    }
    

    printf("Dequeuing element %d\n", dequeue(&q));

    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("Queue is not Empty anymore\n");
    }

    return 0;
}

//enable error squiggels