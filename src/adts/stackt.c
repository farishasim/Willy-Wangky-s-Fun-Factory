
#include "boolean.h"
#include "stackt.h"
#include <stdlib.h>
#include <stdio.h>

void CreateEmptyStackt (Stack *S){
  Top(*S) = Nil;
}
boolean IsEmptyStackt (Stack S){
  return (Top(S)==Nil);
}
boolean IsFullStackt (Stack S){
  return(Top(S)==MaxEl-1);
}
void Push (Stack * S, infotype X)
  Top(*S)++;
  InfoTop(*S) = X;
}

void Pop (Stack * S, infotype* X){
  *X = InfoTop(*S);
  Top(*S)--;
}
