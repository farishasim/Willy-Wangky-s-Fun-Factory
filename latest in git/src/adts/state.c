#include "state.h"
#include <stdio.h>

//********** PRIMITIF Untuk STATE ***********//
void StartState(State * S){
/* I.S. sembarang */
/* F.S. State S merupakan state di awal permainan*/
    InitialMap(&Peta(*S));
}

void SaveState(State * S) {
/* I.S. State S adalah state permainan yang sedang berlangsung */
/* F.S. State S disimpan ke dalam file eksternal */

}

// keterangan : Load state belum beres
void LoadState(State * S){
/* I.S. sembarang */
/* F.S. State S adalah state permainan yang sudah di-save sebelumnya pada suatu file eksternal */
    STARTKATA("state.txt");
    // Load nama player
    CopyKata(CKata, &Name(*S));
}


//********** Fungsi-fungsi untuk Support ************//
void printListWahana(State * S) {
/* I.S. Sembarang */
/* F.S. Menampilkan semua nama wahana yang dimiliki pemain*/
    int i;
    
    printf("Daftar Wahana yang dimiliki : \n");
    
    for(i = 0; i < ((*S).NWahana); i++) {
        printf("%d. ", i+1);
        PrintKata((*S).listWahana[i].nama);
        printf("\n");
    }
}

