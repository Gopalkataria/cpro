#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
    int l, r;
    struct line *next;

} line;

typedef line *Stack;

void stackadd(Stack *S, int l, int r)
{
    Stack temp = (Stack)malloc(sizeof(line));
    temp->l = l;
    temp->r = r;
    temp->next = NULL;
    Stack P  = *S ; 
    if (*S == NULL)
    {
        *S = temp;
        return;
    }
    else
    {
        while (P->next != NULL)
        {
            P = P->next;
        }

        P->next = temp;
        return;
    }
}

void stackremove( Stack * S , int l , int r  ){
    Stack temp = *S;
    if( temp == NULL ){
        return;
    }
    else if( temp->l == l && temp->r == r ){
        *S = temp->next;
        free(temp);
        return;
    }
    else{
        while( temp->next != NULL ){
            if( temp->next->l == l && temp->next->r == r ){
                Stack temp2 = temp->next;
                temp->next = temp->next->next;
                free(temp2);
                return;
            }
            temp = temp->next;
        }
    }
}

void printStack( Stack S){
    Stack temp = S;
    while( temp != NULL ){
        printf("%d %d\n", temp->l , temp->r );
        temp = temp->next;
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    char op; 
    line k = {
        1 , 2 , NULL
    };
    Stack S = &k;
        printf("Stack is:\n");
    int l , r ; 
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %d %d", &op , &l , &r );
        if (op=='+')
        {
            stackadd(&S, l, r);
            // printf("+ %d %d\n", l, r) ; 
        } else if (op=='-')
        {
            stackremove(&S, l, r);
            // printf("- %d %d\n", l, r);
        }
        printStack(S);
        
    }
    

    return 0;
}