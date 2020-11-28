#include "map.h"

void InitialMap(Map * M) {
/* I.S. M sebuah map berisi karakter sembarang */
/* F.S. M sebuah map taman wahana kosong hanya berisi office dan Antrian*/
/* kosong artinya belum ada satu pun wahana */
    indeks i,j;
    // isi baris paling atas dengan '*'
    i = GetFirstIdxBrs(*M);
    for(j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
        Elmt(*M,i,j) = '*';
    }
    // isi dari baris ke i=1, hingga ke i=brsmax-1
    for(i = i + 1; i <=GetLastIdxBrs(*M)-1; i++) {
        j = GetFirstIdxKol(*M);
        Elmt(*M,i,j) = '*';
        for (j = j+1; j <= GetLastIdxKol(*M)-1; j++) {
            Elmt(*M,i,j) = '-';
        }
        Elmt(*M,i,j) = '*';
    }
    // isi baris paling bawah dengan '*'
    for(j = 0; j <= GetLastIdxKol(*M); j++) {
        Elmt(*M,i,j) = '*';
    }

    // Elmt(*M,1,1) = 'A'; // set nilai matriks di (1,1) dengan antrian, pemilihan ini bebas, boleh saja dirubah
    // Elmt(*M,1,3) = 'O'; // set nilai matriks di (1,3) dengan Office, pemilihan ini bebas, boleh saja dirubah
}

void SetWahana(Map * M, POINT P, POINT Size) {
/* I.S. M sebuah map yang berisi n buah wahana, n mungkin nol, dan P adalah sebuah Point yang valid*/
/* F.S. M sebuah map yang berisi n+1 buah wahana, dengan wahana baru terletak pada koordinat P*/
    int i,j;
    
    for(i = Absis(P); i < Absis(Size); i++) {
        for(j = Ordinat(P); j < Ordinat(Size); j++) {
            Elmt(*M,i,j) = 'W';
        }
    }
}

boolean IsWahana(Map M, POINT P) {
    return Elmt(M,Absis(P),Ordinat(P)) == 'W';
}

void SetOffice(Map * M, POINT P)
{
    Elmt(*M,Absis(P),Ordinat(P)) = 'O';
}

void SetAntrian(Map * M, POINT P)
{
    Elmt(*M,Absis(P),Ordinat(P)) = 'A';
}

void SetPlayer(Map * M, POINT P)
{
    Elmt(*M,Absis(P),Ordinat(P)) = 'P';
}