#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char *arr;  //@  * because its gona be a string %s instead of a %c
};


char stackTop(struct Stack * ptr){
    char x = ptr->arr[ptr->top];
    return x;
}

int isEmpty(struct Stack *ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *ptr){
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    return 0;   
}

void push(struct Stack *ptr ,char value){
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]= value;
    }
}

char pop(struct Stack *ptr){
    if (ptr->top == -1)
    {
        printf("Stack underflow ");
    }
    else{
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    } 
}

//Function to check Operators(+-*/)
int isOperator(char n){
    if (n=='+' || n== '-' || n=='*' || n=='/')
    {
        return 1;
    }
    return 0;
}

//Function to give precedence to Operators i.e. Precedence of * = / > + = -
int precedence(char ch){
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else{
        return 0;
    }
}




char* infixTOpostfix(char * infix){
    
    // struct Stack * store;  //ye kaam nahi karraha tha kyuki hamne stack ka instance banaya hi nahi even hamne array ko malloc mein space di, we also have to give space to stack in space using malloc, else function wont run!!!!!!!
    
    //This stack "store" is to store the operators while computing Postfix
    struct Stack * store = (struct Stack *)malloc(sizeof(struct Stack));        
    store->size =100;
    store->top = -1;
    store->arr = (char*)malloc(sizeof(char));       //it's imporant to allocate space for the array characters too

    char *postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));    //This character string will store the Postfix form of Infix!

    int i=0;            //for traversing Infix          i.e. for reading the infix
    int j=0;            //for tracking Postfix addition

    //Using while loop - taught by sir: 
    // while (infix[i] != '\0')
    // {
    //     if (!isOperator(infix[i]))      //is not operator that is not +-*/
    //     {
    //         postfix[j]= infix[i];
    //         i++;    
    //         j++;
    //     }
    //     else{
    //         if (   precedence(infix[i]) > precedence(stackTop(store))   )           
    //         {
    //             push(store, infix[i]);
    //             i++;        //sirf yaha par i++ karo not in the else part!!!! varna ek operator skip kar diya jayega
    //         }
    //         else{
    //             postfix[j]= pop(store);
    //             j++;
    //         }
    //     }
    // }

    //using FOR LOOP - done by me completely!!! AND AMAZING ANSWER FASTER! :
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
                i--;            // THIS IS THE PART WHICH IS MAKING ENTIRE DIFFERENCE IN FOR AND WHILE LOOP!!!           
            }
        }
    }

    while(!isEmpty(store)){
        postfix[j] =pop(store);
        j++;
    }
    postfix[j]= '\0';       //it's important to end the string hence \0
    return postfix;
}











int main(){
    char * infixform = "x+y/z-k*d";
    printf("Postfix form of %s is %s\n", infixform, infixTOpostfix(infixform));
    return 0;
}


//THIS WAS AMAZING!!! LOVED TO CODE IT!  ALSO REFER NOTES FOR CLEAR PICTURE!