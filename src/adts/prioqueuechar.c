
#include "boolean.h"
#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmptyQueue (PrioQueueChar Q){
    if (Q.HEAD==Nilqueue && Q.TAIL==Nilqueue){
        return true;
    }
    else {
        return false;
    }
}

boolean IsFullQueue (PrioQueueChar Q){
    if (Q.HEAD==(Q.TAIL+1)%MaxEl(Q)){
        return true;
    }
    else {
        return false;
    }
}

int NBElmtQueue (PrioQueueChar Q){
    if (IsEmptyQueue(Q)){
        return 0;
    }
    if (IsFullQueue(Q)){
        return MaxEl(Q);
    }
    if (!IsEmptyQueue(Q) && !IsFullQueue(Q)){
        return (Q.TAIL-Q.HEAD + Q.MaxEl)%Q.MaxEl+1;
    }
}

void MakeEmptyQueue (PrioQueueChar * Q, int Max){
    (*Q).T= (address_c * ) malloc (Max * sizeof(address_c));
    if ((*Q).T!=NULL){
        (*Q).MaxEl=Max;
        (*Q).HEAD=Nilqueue;
        (*Q).TAIL=Nilqueue;
    }
    else{
        (*Q).MaxEl=0;
    }

}

void DeAlokasi(PrioQueueChar * Q){
    (*Q).MaxEl=0;
    free((*Q).T);
}

void Enqueue (PrioQueueChar * Q, address_c X){
    if(IsEmptyQueue(*Q)){
        (*Q).HEAD=0;
    }
    (*Q).TAIL=((*Q).TAIL+1)%(*Q).MaxEl;
    InfoTail(*Q)=X;
    int i = (*Q).TAIL;
    int j = (i-1+(*Q).MaxEl)%(*Q).MaxEl;
    address_c temp;
    while ( i!=(*Q).HEAD && Prio((*Q).T[i])<Prio((*Q).T[j])){
        temp=(*Q).T[i];
        (*Q).T[i]=(*Q).T[j];
        (*Q).T[j]=temp;
        i=j;
        j=(i-1+(*Q).MaxEl)%(*Q).MaxEl;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
        
void Dequeue (PrioQueueChar * Q, address_c * X){
    *X=InfoHead(*Q);
    if ((*Q).HEAD==((*Q).TAIL)){
        (*Q).HEAD=Nilqueue;
        (*Q).TAIL=Nilqueue;
    }
    else {
        (*Q).HEAD= ((*Q).HEAD+1)%(*Q).MaxEl;
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilqueueNilqueueai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    if (IsEmptyQueue(Q)){
    }
    else{
        printf("%d %c\n",Prio(InfoHead(Q)),Info(InfoHead(Q)));
        while (Q.HEAD!=Q.TAIL)
        {
            (Q).HEAD= ((Q).HEAD+1)%(Q).MaxEl;
            printf("%d %c\n",Prio(InfoHead(Q)),Info(InfoHead(Q)));
        }
    }
    printf("#\n");
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

