#include <stdio.h>

typedef struct node
{
    struct node *next;
    int n;
} node;

typedef node *linkedlist;

node *cycling(linkedlist l)
{

    linkedlist t = l, r = l;
    int c = 74;
    while (c > 0 && r != NULL && r->next != NULL)
    {
        t = t->next;
        c--;
        r = r->next->next;
        printf("%d %d \n", r->n, t->n);
        if (t == r)
            break;
    }
    if (r == NULL || r->next == NULL)
    {
        return NULL;
    }
    else if (t == r)
    {
        return r;
    }
    return NULL;
}

int main()
{

    node nodes[10];
    for (int i = 0; i < 9; i++)
    {
        nodes[i].n = i;
        nodes[i].next = &nodes[i + 1];
    }
    nodes[9].n = 10;

    for (int i = 0; i < 9 ; i++)
    {
        nodes[9].next = &nodes[i];

        node *k = cycling(&nodes[0]);

        if (k == NULL)
            printf(" %d not found \n");
        else
            printf(" %d found at %d\n", i , k->n);
    }
    return 0;
}
