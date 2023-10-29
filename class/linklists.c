#include <stdio.h>
#include <stdlib.h>

typedef struct customdata
{
    int num;
} customdata;

typedef struct Account
{
    customdata data;
    struct Account *next;
} Account;

typedef Account *Linkedlist;

void print_Linkedlist(Linkedlist l)
{
    printf("\n---\n");
    while (l != NULL)
    {
        printf("%d \n", l->data.num);
        l = l->next;
    }
    printf("---\n");
}

void append_Linkedlist(Linkedlist *l2, customdata newdata)
{
    Linkedlist l = *l2;
    Account *n;
    n = (Account *)malloc(sizeof(Account));
    n->data = newdata;
    n->next = NULL;

    if (l == NULL)
    {
        *l2 = n;
        return;
    }

    while (l->next != NULL)
    {
        l = l->next;
    }
    l->next = n;
}

Linkedlist preppend_Linkedlist(Linkedlist l, customdata newdata)
{
    Linkedlist n;
    n = (Account *)malloc(sizeof(Account));
    n->data = newdata;
    n->next = l;
    return n;
}

void removeduplicates_Linkedlist(Linkedlist l)
{
    Linkedlist i, j, t;
    for (i = l; i != NULL; i = i->next)
    {
        j = i ; 
        while( j->next != NULL)
        {
            if (i->data.num == j->next->data.num)
            {
                t = j->next;
                j->next = j->next->next;
                free(t);
            }
            else
            {
                j = j->next;
            }
        }
    }
}

void removeduplicatesrecursive_Linkedlist(Linkedlist l)
{
    if (l == NULL || l->next == NULL)
        return;

    if (l->data.num == l->next->data.num)
    {
        Linkedlist t = l->next;
        l->next = l->next->next;
        free(t);
        removeduplicatesrecursive_Linkedlist(l);
    }
    else
    {
        removeduplicatesrecursive_Linkedlist(l->next);
    }
}

int cmp_links(const void *a, const void *b)
{
    Account **na = (Account **)a;
    Account **nb = (Account **)b;
    return (*na)->data.num - (*nb)->data.num;
}
    

Linkedlist  qsort_Linkedlist( Linkedlist l ){
    if (l == NULL)
    {
        return NULL ; 
    }
    
    int s = sizeof_Linkedlist( l ) ; 
    Account * elems[s]  ; 
    for (int i = 0; i < s; i++)
    {
        elems[i] = l;
        l= l->next;
    }
    qsort(elems, s, sizeof(Account *), cmp_links); 
    Linkedlist head = elems[0] ; 
    for (int i = 0; i < s-1; i++)
    {
        elems[i]->next = elems[i+1] ; 
    }
    
    elems[s-1]->next = NULL ; 
    return head ; 
    
}

Linkedlist concat_Linkedlist(Linkedlist l1, Linkedlist l2)
{ /* code */

    if (l1 == NULL)
    {
        return l2;
    }
    Linkedlist head = l1;
    head->next = concat_Linkedlist(l1->next, l2);
    return head;
}

void reverse_Linkedlistinplace(Linkedlist *l)
{
    Linkedlist nex, curr = *l, prev = NULL;
    if (l == NULL)
        return NULL;
    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    *l = prev;
}

int sizeof_Linkedlist(Linkedlist l)
{
    if (l == NULL)
        return 0;
    return 1 + sizeof_Linkedlist(l->next);
}

Linkedlist recursive_reverse_linkedlistinplace(Linkedlist l)
{
    Linkedlist head = l;
    if (l->next == NULL || l == NULL)
    {
        return l;
    }

    while (l->next->next != NULL) // find second last elem
    {
        l = l->next;
    }
    Linkedlist new = l->next;                              // preserve last elem
    l->next = NULL;                                        // set second last element as end
    new->next = recursive_reverse_linkedlistinplace(head); // recurse
    return new;
}

Linkedlist new_concat_Linkedlist(Linkedlist l1, Linkedlist l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    Linkedlist newtail = NULL, head;

    newtail = (Account *)malloc(sizeof(Account));
    newtail->data = l1->data;
    l1 = l1->next;
    head = newtail;
    while (l1 != NULL)
    {
        append_Linkedlist(newtail, l1->data);

        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        append_Linkedlist(newtail, l2->data);

        l2 = l2->next;
    }

    return head;
}

int main()
{
    Account all[10];
    for (int i = 0; i < 9; i++)
    {
        all[i].data.num = i + 1;
        all[i].next = &all[i + 1];
    }
    all[9].data.num = 9;
    all[9].next = NULL;

    Account k = {{10}, NULL};

    Linkedlist L = &all[0];

    Account all2[10];
    for (int i = 0; i < 9; i++)
    {
        all2[i].data.num = 10 * (i + 1);
        all2[i].next = &all2[i + 1];
    }

    all2[9].data.num = 90;
    all2[9].next = NULL;
    Linkedlist m = all2;

    // print_Linkedlist(L);
    Linkedlist l = L;

    // print_Linkedlist(L);
    reverse_Linkedlistinplace(&L);
    Account koo = {{96}, NULL};
    customdata mi = {10};
    // Linkedlist moo = &koo;
    Linkedlist moo = NULL;
    for (int i = 0; i < 30; i++)
    {
        mi.num = (i/2) % 10;
        append_Linkedlist(&moo, mi);
    }



    moo = recursive_reverse_linkedlistinplace(moo);
    printf("\n%d linklist size \n", sizeof_Linkedlist(moo));
    // printf("\n%d linklist size \n", sizeof_Linkedlist(moo));
    print_Linkedlist(moo);
    removeduplicatesrecursive_Linkedlist(moo);
    printf("\n%d linklist size \n", sizeof_Linkedlist(moo));
    print_Linkedlist(moo);
    removeduplicates_Linkedlist(moo) ;
    printf("\n%d linklist size \n", sizeof_Linkedlist(moo));
    print_Linkedlist(moo);
    moo = qsort_Linkedlist(moo) ; 
    print_Linkedlist(moo);

    return 0;
}