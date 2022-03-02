#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root){
    static struct node* prev = NULL;
    if (root!=NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev!=NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(6);
    struct node *p1l = createNode(1);
    struct node *p1r = createNode(3);

    p->left = p1;
    p->right = p2;
    p1->left = p1l;
    p1->right = p1r;

    inOrder(p);
    printf("\n");
    printf("%d ", isBST(p));
    return 0;
}
