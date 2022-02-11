#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void cllTraversal(struct Node* head){
    struct Node* ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr= ptr->next;

    } while (ptr!= head);
}



struct Node* insertAtHead(struct Node* head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p = head;
    while (p->next!= head)
    {
        p =  p->next;
    }
    //At this point p points to the last node of this circular linked list.

    ptr->data = data;
    p->next = ptr;
    ptr->next = head;
    head= ptr;
    return head;
}

int main()
{
    struct Node* head;
    struct Node* a;
    struct Node* b;
    struct Node* c;

    head = (struct Node*)malloc(sizeof(struct Node));
    a = (struct Node*)malloc(sizeof(struct Node));
    b = (struct Node*)malloc(sizeof(struct Node));
    c = (struct Node*)malloc(sizeof(struct Node));

    head->data = 11;
    a->data = 21;
    b->data = 31;
    c->data = 41;

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = head;

    printf("Circular linked list before insertion\n");
    cllTraversal(head);
    head = insertAtHead(head,111111);
    printf("Circular linked list after insertion\n");
    cllTraversal(head);
    return 0;
}



// //by me while revision:
// #include<stdio.h>
// #include<stdlib.h>

// struct Node{
//     int data;
//     struct Node * next;
// };

// void traversal(struct Node *head){
//     struct Node * ptr ;
//     ptr = head;
//     do
//     {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;

//     } while (ptr!=head);
// }

// struct Node * insertAtHead(struct Node *head, int value){
//     struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *p = head;
//     while (p->next != head)
//     {
//         p = p->next;
//     }
//     ptr->data = value;
//     p->next = ptr;
//     ptr->next = head;
//     head = ptr;
//     return head;
// }

// int main(){
//     struct Node *head = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *second = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *third = (struct Node *)malloc(sizeof(struct Node));
//     struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
//     head->data = 11;
//     second->data = 21;
//     third->data = 31;
//     fourth->data = 41;

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = head;

//     traversal(head);
//     head = insertAtHead(head,111);
//     printf("Circular linked list after insertion\n");
//     traversal(head);
//     return 0;
// }