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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("\nCannot insert %d already in BST\n", key);
            return;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
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
/*        4
         / \
        2   6
       / \
      1   3

*/
int main()
{
    struct node *root = createNode(4);
    struct node *p1 = createNode(2);
    struct node *p2 = createNode(6);
    struct node *p1l = createNode(1);
    struct node *p1r = createNode(3);

    root->left = p1;
    root->right = p2;
    p1->left = p1l;
    p1->right = p1r;

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
        else
        {
            struct node *n = search(root, key);
            printf("%d is Present in the BST\n", n->data);
        }
    }
    else
    {
        printf("It's Not a BST\n");
    }

    insert(root, 23);
    printf("\n");

    inOrder(root);
    printf("\n");
    insert(root, 5);
    inOrder(root);
    printf("\n");

    printf("\n%d ", root->right->left->data);
    return 0;
}