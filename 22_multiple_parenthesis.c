//WOW I MADE THIS MYSELF WHILE LEARNING !! TOTALLY!!!
#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", value);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack underflow ");
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    return 0;
}

int parenthesis(char *exp)
{
    struct Stack *temp_store;
    temp_store->size = 111;
    temp_store->top = -1;
    temp_store->arr = (char *)malloc(temp_store->size * sizeof(char));
    char popper;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(temp_store, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(temp_store))
            {
                return 0;
            }
            popper = pop(temp_store);
            if (!match(popper, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(temp_store))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *express = "{23[2+34(2*3)42]243}";
    if (parenthesis(express))
    {
        printf("PARENTHESIS BALANCED\n");
    }
    else
    {
        printf("PARENTHESIS NOT BALANCED\n");
    }
    return 0;
}