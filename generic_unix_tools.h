#ifndef generic_unix_tools_H_
#define generic_unix_tools_H_

/*A generic placeholder linked list, used by
 * freeLinkedListGen()*/
typedef struct agenericLinkedList{
    //int a;
    char chanName[100];
    struct agenericLinkedList *next;
}genL;

/* Count nr of lines in file */
extern int countLines(char *fileName);

/* Returns true or false if regex matches string
Usage: regexMatch("thomas$", "this is a test string mr thomas");*/
extern int regexMatch(char *regex, char *string);

/* Generic linked list free */
extern void freeLinkedListGen(void* targetList);

/* Inline malloc wrapper 
 * Using inline 'might' improve performance
 * but I could not verify that because of compiler optimization
 * This function will save a lot of typing in malloc heavy
 * code */
inline void *tryMalloc(size_t memSz);

#endif
