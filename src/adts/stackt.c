
#include "boolean.h"
#include "stackt.h"
#include <stdlib.h>
#include <stdio.h>

void CreateEmptyStackt (Stack *S){
  Top(*S) = NilStackt;
}
boolean IsEmptyStackt (Stack S){
  return (Top(S)==NilStackt);
}
boolean IsFullStackt (Stack S){
  return(Top(S)==MaxElStack-1);
}
void Push (Stack * S, infostack X){
  Top(*S)++;
  InfoTop(*S) = X;
}

void Pop (Stack * S, infostack* X){
  *X = InfoTop(*S);
  Top(*S)--;
}
