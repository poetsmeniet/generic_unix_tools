#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic_unix_tools.h"

typedef struct chanList{
    char chanName[100];
    struct chanList *next;
}chanList;

void addChannel(chanList *chans, char *chanName, int len);

int main(void){
    //Inititalize and populate linked list
    chanList *chans = malloc(sizeof(chanList));
    addChannel(chans, "test", 4);
    addChannel(chans, "kest", 4);
    addChannel(chans, "rest", 4);

    freeLinkedListGen((void *)chans); //Explicitly casting not really needed

    return 0;
}

//Adds node to linked list
void addChannel(chanList *chans, char *chanName, int len){
    chanList *head = chans;
    while(head->next != NULL){
        head = head->next;
    }
    
    head->next = malloc(sizeof(chanList));
    memcpy(head->next->chanName, chanName, len); 
    head->next->chanName[len] = '\0';
    head->next->next = NULL;
}
