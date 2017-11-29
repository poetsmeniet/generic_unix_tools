#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "generic_unix_tools.h"

void myFunc()
{
    printf("Signal processed\n");
}

int main(void)
{
    
    //Demonstrate catch CTR-C event
    catchSIGINT(&myFunc);

    printf("Waiting for signal..\n");
    sleep(10);

    return 0;
}
