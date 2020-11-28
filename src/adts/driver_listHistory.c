#include <stdio.h>
#include "listrek.h"

int main() {
    int i;
    List L,L2,L3;
    L = Nil;
    L2 = Nil;
    L3 = Nil;

    printf("Test\n");
    for(i=0; i < 5; i++) {
        L = Konso(i, L);
    }

    printf("test2\n");
    PrintList(L);

    for(i=-1; i > -5; i--) {
        L3 = KonsB(L3, i);
    }

    printf("test3\n");
    PrintList(L);

    L2 = Copy(L);

    printf("test4\n");
    PrintList(L); 
    PrintList(L2); 

    MConcat(L,L2,&L3);
    PrintList(L3);

    return 0;
}