#include "test.h"
#include <string.h>

int main() 
{ 
    char y[5], i = 0;
    while (i < 4 && getc(stdin) != '\n')
    {
        scanf("%c", &y[i++]);
    }
    
    printf("%s\n", y);
    
    return 0;
} 
