#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *s){
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *s){
    if (s->top == s->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, char value){
    if (isFull(s))
    {
        printf("STACK FULL\n");
    }
    else{
        s->top++;
        s->arr[s->top]= value;
    }
}

char pop(struct stack *s){
    if (isEmpty(s))
    {
        printf("Empty stack underfow\n");
    }
    else{
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int isOperator(char element){
    if (element == '+' || element == '-' || element == '*' || element == '/')
    {
        return 1;
    }
    else{
        return 0;
    }
}

char stackTop(struct stack *s){
    char val = s->arr[s->top];
    return val;
}
int precedence(char element){
    if (element == '*' || element == '/')
    {
        return 3;
    }
    else if (element == '+' || element == '-') 
    {
        return 2;
    }
    else{
        return 0;
    }
}

char* infotopo(char *infix){
    struct stack *store = (struct stack *)malloc (sizeof(struct stack));
    store->size = 100;
    store->top = -1;
    store->arr = (char *)malloc (store->size*sizeof(char));
    int i = 0;
    int j = 0;
    char* postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(store)))
            {
                push(store, infix[i]);
            }
            else{
                postfix[j] = pop(store);
                j++;
                i--;               
            }
        }
    }
    while (!isEmpty(store))
    {
        postfix[j] = pop(store);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char * infixform = "x+y/z-k*d";
    printf("postfix form of %s is %s", infixform, infotopo(infixform));
    return 0;
}

// xyz/+kd*-