#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

struct node *createNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalancedFactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    // return n->left->height-n->right->height;
    return getHeight(n->left) - getHeight(n->right);
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;
    y->left = t2;
    x->right = y;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;
    x->right = t2;
    y->left = x;
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return y;
}

struct node *insertion(struct node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }
    if (key < node->key)
    {
        node->left =  insertion(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insertion(node->right, key);
    }
    else
    {
        printf("Duplicate node found , can't insert %d\n");
        return node;
    }
    int bF = getBalancedFactor(node);
    node->height = 1 + max(getHeight(node->right), getHeight(node->left));
    // left left case
    if (bF > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    // right-right case
    if (bF < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // left-right case
    if (bF > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right-left case
    if (bF < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insertion(root, 1);
    root = insertion(root, 2);
    root = insertion(root, 4);
    root = insertion(root, 5);
    root = insertion(root, 6);
    root = insertion(root, 3);

    preOrder(root);
    return 0;
}