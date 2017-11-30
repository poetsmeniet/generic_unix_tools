#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include "generic_unix_tools.h"

/* This function makes is a bit easier to catch CTR-C keyb event 
 * handler is the address to function that will handle the event */
void catchSIGINT(void *handler)
{
    //Define sigaction struct and pass to sigaction
    struct sigaction act;
    act.sa_handler = handler;
    sigaction(SIGINT,  &act, NULL);
}

/*Free a linked list
 * Will work if the "genL" struct type matches your struct in size 
 * Customize if needed or adjust genL struct */
extern void freeLinkedListGen(void* targetList){
    genL *tL = (genL *)targetList; //Explicit

    if(tL->next == NULL){ //Only one node, the first
        free(tL);
    }else{
        genL *head = tL;
        genL *curr;
        while ((curr = head) != NULL) { 
            head = head->next;          
            free (curr);                
        }
    }
}

//Count nr of lines in file
extern int countLines(char *fileName){
    FILE *fp;
    int lineCnt = 0;
    fp = fopen(fileName, "r");

    if(fp != NULL){
        char line[256];
        while (fgets(line, sizeof(line), fp)) {
            lineCnt++;
        }
        fclose(fp);
    }
    return lineCnt;
}

/* Returns true or false if regex matches string
Usage: regexMatch("thomas$", "this is a test string mr thomas");*/
extern int regexMatch(char *regex, char *string){
    //Check lengths
    if(strlen(regex) == 0 || strlen(string) == 0){
        printf("Regex or string empty\n");
        return -1;
    }
    regex_t preg;

    //Compile regex, case insensitive
    int rc = regcomp(&preg, regex, REG_ICASE);
    if(rc != 0){
        printf("Regex compilation failed, rc = %d\n", rc);
        return 1;
    }

    rc = regexec(&preg, string, 0, 0, 0);

    if(rc == 0){
        regfree(&preg);
        return 0;
    }else{
        regfree(&preg);
        return 1;
    }
}
