#include <stdio.h>


typedef struct node {
    node * next ; 
    int n ; 
} node ; 

typedef node * linkedlist ; 

node * cycling( linkedlist l ) {

    linkedlist t = l , r = l ;
    while( t!= NULL && t->next != NULL  ) {
	t = t->next ; 
	r = r->next->next ;
    }
    if( t == NULL || t->next == NULL ) {
	printf("reached end \n" ) ; 
    } else if ( t == r ) {
	printf("%d\n found\n"  , r->n ) ; 
    }
    return r ; 

}

int main() {

    node nodes[10] ; 
    for( int i = 0 ; i < 9 ; i++ ) {
	node[i].n = i ; 
	node[i].next = &node[i+1] ;
    }
    node[9].n = 10 ; 
    node[9].next = &nodes[5] ; 
    return 0 ; 
}
