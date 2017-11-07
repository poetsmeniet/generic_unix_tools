#include <stdio.h>
#include <stdlib.h>
#include "generic_unix_tools.h"

int main(void){

    typedef struct agenericLinkedList{
        int a;
        char b;
        struct agenericLinkedList *next;
    }aL;

    //Start list
    aL *myList = malloc(sizeof(aL));
    myList->a = 10;
    myList->b = 'c';

    //add another
    myList->next = malloc(sizeof(aL));
    myList->next->a = 11;
    myList->next->b = 'd';
    myList->next->next = NULL;
    

    freeLinkedListGen(myList);
    return 0;
}
