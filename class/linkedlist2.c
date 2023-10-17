#include <stdio.h>
#include <stdlib.h>

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

int sizeofLinkedList( LinkedList l ){
    int count = 0 ; 
    while ( l != NULL ){
        count++ ; 
        l = l->next ; 
    }
}
LinkedList concatlinkedlist(LinkedList l1, LinkedList l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    LinkedList l = (LinkedList)malloc(sizeof(Node));
    l->data = l1->data;
    l->next = concatlinkedlist(l1->next, l2);
    if (l->next == NULL) {
        l->next = (LinkedList)malloc(sizeof(Node));
        l->next->data = l2->data;
        l->next->next = NULL;
    }
    return l;
}
LinkedList insertAtPosLinkedList(LinkedList l, int pos, Person p) {
    if (pos < 0 || pos > sizeofLinkedList(l)) return l;
    LinkedList newnode = (LinkedList)malloc(sizeof(Node));
    newnode->data = p;
    newnode->next = NULL;
    if (pos == 0) {
        newnode->next = l;
        return newnode;
    }
    if (pos == 1) {
        newnode->next = l->next;
        l->next = newnode;
        return l;
    }
    l->next = insertAtPosLinkedList(l->next, pos - 1, p);
    return l;
}




LinkedList reverselinkedlist( LinkedList l ){
    LinkedList prev = NULL , cur = l , next = NULL ; 
    while ( cur != NULL ){
        next = cur->next ; 
        cur->next = prev ; 
        prev = cur ; 
        cur = next ; 
    }
    return prev ; 
}

int main()
{

    
    Node P3 = {{"C", 10}, NULL};
    Node P2 = {{"B", 20}, &P3};
    Node P1 = {{"A", 30}, &P2};

    LinkedList People = &P1;
    LinkedList People2  = &P2 ; 
    LinkedList People3 = reverselinkedlist(People);

    scanf("%d" , &(P1.data.age));

    while( People3 != NULL ){
        printf("%s %d\n", People3->data.name, People3->data.age);
        People3 = People3->next;
    }

    return 0;
}
