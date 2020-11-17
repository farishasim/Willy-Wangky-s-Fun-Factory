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

