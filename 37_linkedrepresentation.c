/*
We have another method to represent binary trees called the linked representation of binary trees. 
Don’t confuse this with linked lists you have studied. 
And the reason why I am saying that is because linked lists are lists that are linear data structures.

#Linked Representation of Binary Trees:

This method of representing binary trees using linked nodes is considered the most efficient method of representation. 
For this, we use doubly-linked lists.

Using links makes the understanding of a binary tree very easy. 
It actually makes us visualize the tree even. Suppose we have a binary tree of 3 levels.


Now if you remember a doubly linked list helped us traversing both to the left and the right. 
And using that we would create a similar node here, pointing both to the left and the right child node. 
Follow the below representation of a node here in the linked representation of a binary tree.

<---2--->     =    * 2 *

You can see how closely this representation resembles a real tree node, unlike the array representation where 
all the nodes succumbed to a 2D structure.  And now we can very easily transform the whole tree into its linked 
representation which is just how we imagined it would have looked in real life.
    STRUCT NODE:
                 *          2           *
            (node * left) (int data) (node * right)
So, this was the representation of the binary tree we saw above using linked representation. 
And what are these nodes? These are structures having three structure members, first a data element to store the 
data of the node, and then two structure pointers to hold the address of the child nodes, one for the left, and the other for the right.

And let me show you that struct Node definition part in C language:
struct node{
    int data;
    struct node* left;
    struct node* right;
};


#Understanding the code snippet below:
1) Code Snippet 1:  Creating the struct Node
2) Code Snippet 2:  Creating the function createNode
3) Code Snippet 3:  Implementing binary trees in C
4) Code Snippet 4:  Using createNode to create nodes.


*/

#include<stdio.h>
#include<malloc.h>
//  Creating the struct Node
struct node{
    int data;
    struct node* left;
    struct node* right;
};
// Creating the function createNode
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

int main(){
    /*
    // Constructing the root node
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct node *p1;
    p1 = (struct node *) malloc(sizeof(struct node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct node *p2;
    p2 = (struct node *) malloc(sizeof(struct node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */
   
//    Implementing binary trees in C
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}