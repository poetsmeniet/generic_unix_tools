#include <stdio.h>
#include <stdlib.h>
#include "generic_unix_tools.h"

int main(void){

    typedef struct agenericLinkedList{
        int a;
        char b;
        struct agenericLinkedList *next;
    }aL;

    aL *myList = malloc(sizeof(aL));
    myList->a = 10;
    myList->b = 'c';
    myList->next = NULL;

    freeLinkedListGen(&myList);
    return 0;
}
