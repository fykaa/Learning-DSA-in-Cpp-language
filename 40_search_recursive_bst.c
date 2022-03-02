#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }

        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

int main()
{
    struct node *root = createNode(50);
    struct node *l = createNode(40);
    struct node *r = createNode(60);
    struct node *ll = createNode(20);
    struct node *lr = createNode(45);
    struct node *rl = createNode(55);
    struct node *rr = createNode(70);

    root->left= l;
    root->right= r;
    l->left= ll;
    r->left= rl;
    l->right=lr;
    r->right=rr;

    int key;
    printf("Value of key is :\n");
    scanf("%d", &key);

    if (isBST(root))
    {
        printf("Yes , it is a  BST\n");
        if (search(root, key) == NULL)
        {
            printf("No %d this is NOT present in bst", key);
        }
        else{
        struct node* n = search(root, key);
        printf("%d is Present in the BST\n", n->data);
        }
        
    }
    else
    {
        printf("It's Not a BST\n");
    }

    return 0;
}