#include "map.h"
#include "mesinkata.c"

static int mapSize;
static char general[2]; /* star, minus */ 
static char obj[4]; /* P, O, A, W */
static char gate[4]; /* <, ^, >, v */

void InitialMap(Map * M, char* filename, boolean isInput) {
/* I.S. M sebuah map berisi karakter sembarang */
/* F.S. M sebuah map taman wahana kosong hanya berisi office dan Antrian */
/* kosong artinya belum ada satu pun wahana */ 
    int m;

    if (!isInput)
    {
        mapSize = ConvertKata(CKata);
    }
    ADVKATA(',');
    for (m = 0; m < 2; ++m)
    {
        general[m] = CKata.TabKata[0];
        ADVKATA(',');
    }
    for (m = 0; m < 4; ++m)
    {
        obj[m] = CKata.TabKata[0];
        ADVKATA(',');
    }
    for (m = 0; m < 4; ++m)
    {
        gate[m] = CKata.TabKata[0];
        ADVKATA(',');
    }
    
    indeks i,j;
    // isi baris paling atas dengan '*'
    i = GetFirstIdxBrs(*M);
    for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
        Elmt(*M,i,j) = general[0];
    }
    // isi dari baris ke i=1, hingga ke i=brsmax-1
    for(i = i + 1; i <=GetLastIdxBrs(*M)-1; i++) {
        j = GetFirstIdxKol(*M);
        Elmt(*M,i,j) = general[0];
        for (j = j+1; j <= GetLastIdxKol(*M)-1; j++) {
            Elmt(*M,i,j) = general[1];
        }
        Elmt(*M,i,j) = general[0];
    }
    // isi baris paling bawah dengan '*'
    for(j = 0; j <= GetLastIdxKol(*M); j++) {
        Elmt(*M,i,j) = general[0];
    }
}


void SetWahana(Map * M, POINT P, POINT Size) {
/* I.S. M sebuah map yang berisi n buah wahana, n mungkin nol, dan P adalah sebuah Point yang valid*/
/* F.S. M sebuah map yang berisi n+1 buah wahana, dengan wahana baru terletak pada koordinat P*/
    int i,j;
    
    for(i = Absis(P); i < Absis(Size); i++) {
        for(j = Ordinat(P); j < Ordinat(Size); j++) {
            Elmt(*M,i,j) = obj[3];
        }
    }
}

boolean IsWahana(Map M, POINT P) {
    return Elmt(M,Absis(P),Ordinat(P)) == obj[3];
}

void SetOffice(Map * M, POINT P)
{
    Elmt(*M,Absis(P),Ordinat(P)) = obj[1];
}

void SetAntrian(Map * M, POINT P)
{
    Elmt(*M,Absis(P),Ordinat(P)) = obj[2];
}

void SetPlayer(Map * M, POINT P)
{
    Elmt(*M,Absis(P),Ordinat(P)) = obj[0];
}