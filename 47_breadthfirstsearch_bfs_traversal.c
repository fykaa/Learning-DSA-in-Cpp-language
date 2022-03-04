// Breadth First Search (BFS) Traversal using Queue Data Structures
    // This method invvolves two data sets -
        // 1) EXPLORATION
        // 2) VISITED

#include <stdio.h>
#include <stdlib.h>

// Creating Queue for EXPLORATION
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("Sorry, this queue is full can't insert %d\n", value);
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty queue, can't dequeue\n");
        return -1;
    }
    else
    {
        q->f++;
        int val = q->arr[q->f]; // VERY VERY VERY IMP DEBUG! PROGRAM WON'T RUN if you put this line of code ABOVE q->f++; !!!!!
        return val;
    }
}

int main()
{
    // Initialising Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // BFS Implementation
    int node;
    int i = 0; // you can start from ANY NODE (i.e. 1, 2, 3 ,5,6 etc values of node) as root
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};     //@creating this array for keeping track of which elements are already visited and printed to avoid printing same node again
    int a[7][7] = {                             //@creating Graph using a adjacency matrix (using Multidimensional array) i.e. a matrix that stores the vertices and edges of the Graph
      // 0  1  2  3  4  5  6
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    printf("%d ", i);
    visited[i] = 1;                             //@so because i is already printed we made iTH position 1 in visited arrray so that it won't be printed again
    enqueue(&q, i); // Enqueue i for exploration    //i.e. abb i ke connected nodes will be visited using adjacency matrix
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);     //i.e. jo element dequque hogi it will be stored in node for exploration! i.e. abb iss node ke connected elements ko visit kiya jaayega
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}