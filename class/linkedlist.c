#include <stdio.h>

typedef struct Person
{
    char name[100];
    int age;
} Person;

typedef struct Node
{
    Person data;
    struct Node *next;
} Node;

typedef Node *LinkedList;

int sizeofLinkedList(LinkedList l)
{
    int count = 0;
    while (l != NULL)
    {
        count++;
        l = l->next;
    }
}
LinkedList concatlinkedlist(LinkedList l1, LinkedList l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    LinkedList l = (LinkedList)malloc(sizeof(Node));
    l->data = l1->data;
    l->next = concatlinkedlist(l1->next, l2);
    if (l->next == NULL)
    {
        l->next = (LinkedList)malloc(sizeof(Node));
        l->next->data = l2->data;
        l->next->next = NULL;
    }
    return l;
}
LinkedList insertAtPosLinkedList(LinkedList l, int pos, Person p)
{
    if (pos < 0 || pos > sizeofLinkedList(l))
        return l;
    LinkedList newnode = (LinkedList)malloc(sizeof(Node));
    newnode->data = p;
    newnode->next = NULL;
    if (pos == 0)
    {
        newnode->next = l;
        return newnode;
    }
    if (pos == 1)
    {
        newnode->next = l->next;
        l->next = newnode;
        return l;
    }
    l->next = insertAtPosLinkedList(l->next, pos - 1, p);
    return l;
}

LinkedList reverselinkedlist(LinkedList l)
{
    LinkedList prev = NULL, cur = l, next = NULL;
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

free_linked_list(LinkedList l)
{
    if (l == NULL)
    {
        return;
    }
    free_linked_list(l->next);
    free(l);
}

LinkedList rever_in_place( LinkedList l ){
    if (l == NULL || l->next == NULL)
    {
        return l;
    }
    LinkedList rest = rever_in_place(l->next);
    l->next->next = l;
    l->next = NULL;
    return rest;
}

int main()
{

    Node P1 = {{"A", 10}, NULL};
    Node P2 = {{"B", 20}, &P1};
    Node P3 = {{"C", 30}, &P2};
    scanf("%d" , &P2.data.age) ; 

    LinkedList People = &P1;
    while (People != NULL)
    {
        
    printf("%d\n", People->data.age);
    }
    

    return 0;
}