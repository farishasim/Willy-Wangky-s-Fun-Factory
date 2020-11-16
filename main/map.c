#include "map.h"
#include "state.h"

void InitialMap(Map * M) {
/* I.S. M sebuah map berisi karakter sembarang */
/* F.S. M sebuah map taman wahana kosong hanya berisi office dan Antrian*/
/* kosong artinya belum ada satu pun wahana */
    indeks i,j;

    // isi baris paling atas dengan '*'
    i = 0;
    for(j = 0; j < (*M).NKolEff; j++) {
        Elmt(*M,i,j) = '*';
    }
    // isi dari baris ke i=1, hingga ke i=brsmax-1
    for(i = 1; i < (*M).NBrsEff-1; i++) {
        j = 0;
        Elmt(*M,i,j) = '*';
        for (j = 1; j < (*M).NKolEff-1; j++) {
            Elmt(*M,i,j) = '-';
        }
        j = (*M).NKolEff-1;
        Elmt(*M,i,j) = '*';
    }
    // isi baris paling bawah dengan '*'
    i = (*M).NBrsEff-1;
    for(j = 0; j < (*M).NKolEff; j++) {
        Elmt(*M,i,j) = '*';
    }

    //Elmt(*M,1,1) = 'A'; // set nilai matriks di (1,1) dengan antrian, pemilihan ini bebas, boleh saja dirubah
    //Elmt(*M,1,3) = 'O'; // set nilai matriks di (1,3) dengan Office, pemilihan ini bebas, boleh saja dirubah
}

void SetWahana(Map * M, POINT P) {
/* I.S. M sebuah map yang berisi n buah wahana, n mungkin nol, dan P adalah sebuah Point yang valid*/
/* F.S. M sebuah map yang berisi n+1 buah wahana, dengan wahana baru terletak pada koordinat P*/
    Elmt(*M,Absis(P)-1,Ordinat(P)-1) = 'W';
}

void SetOffice(Map * M, POINT P)
{
    Elmt(*M,Absis(P)-1,Ordinat(P)-1) = 'O';
}

void SetAntrian(Map * M, POINT P)
{
    Elmt(*M,Absis(P)-1,Ordinat(P)-1) = 'A';
}