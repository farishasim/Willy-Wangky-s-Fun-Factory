#include "queue.h"
#include "boolean.h"
#include <stdlib.h>

boolean IsEmptyQueue (Queue Q){
	return (Head(Q)==Nil && Tail(Q)==Nil);
}

boolean IsFullQueue (Queue Q){
	return ((Tail(Q)+1)%MaxEl(Q) == Head(Q));
}

int NBElmtQueue (Queue Q){
	if(IsEmptyQueue(Q)){
			return 0;
	}
	else if(Tail(Q)>Head(Q)){
		return Tail(Q)-Head(Q)+1;
	}
	else if(Tail(Q)<Head(Q)){
		return Tail(Q)+MaxEl(Q)-Head(Q)+1;
	}
	else{
		return 1;
	}
}

void MakeEmptyQueue (Queue * Q, int Max){
	if (Max>0) {
		(*Q).T=(infotype*) malloc ((Max)*sizeof (infotype));
		MaxEl(*Q)=Max-1;
	} 
	else {
		MaxEl(*Q)=0;
	}
	Head(*Q)=0;
	Tail(*Q)=0;
}

void DeAlokasiQueue(Queue * Q){
	if(MaxEl(*Q)!=0){
	    MaxEl(*Q) = 0;
    	Head(*Q) = Nil;
    	Tail(*Q) = Nil;
		free((*Q).T);
	}
}

void Enqueue (Queue * Q, infotype X){
	if (!IsFullQueue(*Q)){
		if (IsEmptyQueue(*Q)) {
			Head(*Q)=0;
			Tail(*Q)=0;
			InfoTail(*Q)=X;
		} 
		else { 
			Tail(*Q)++;
			if (Tail(*Q)>MaxEl(*Q)-1) {
				Tail(*Q)=Tail(*Q)%MaxEl(*Q);
				InfoTail(*Q)=X;
			} 
			else {
				InfoTail(*Q)=X;
			}
		}	
	}
}


void Dequeue (Queue * Q, infotype * X){
	if(!IsEmptyQueue(*Q)){
		(*X)=InfoHead(*Q);
		if (NBElmtQueue(*Q)==1) {
			Head(*Q)=Nil;
			Tail(*Q)=Nil;
		} 
		else {
			Head(*Q)++;
			if (Head(*Q)>MaxEl(*Q)) {
				Head(*Q)=Head(*Q)%MaxEl(*Q);
			}
			else if (Head(*Q)==MaxEl(*Q)-1){
				Head(*Q)=0;
			}
		}
	}
}