
#include <stdlib.h>
#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"


void IgnoreBlank(char separator){
    while (CC==separator)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char * namafile){
    START(namafile);
    IgnoreBlank(BLANK);
    if (CC==MARK){
        EndKata=true;
    }
    else {
        EndKata=false;
        ADVKATA(BLANK);
    }
}
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(char separator){
    if (CC==MARK){
        EndKata=true;
    }
    else {
        SalinKata(separator);
        IgnoreBlank(separator);
    }

}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata(char separator){
    // Kamus Lokal
    int i;
    // Algoritma
    i = 0;
    while ((CC != MARK) && (CC != separator)) {
        if (i < NMax) {
            CKata.TabKata[i] = CC;
            i++;
        }
        ADV();
    }
    CKata.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyKata(Kata Kin, Kata * Kout) {
    int i;

    for(i = 0; i < Kin.Length; i++) {
        (*Kout).TabKata[i] = Kin.TabKata[i];
    }

    (*Kout).Length = Kin.Length;
}

int ConvertKata(Kata Kin) {
    int i;
    int val;

    val =0;
    for(i = 0; i < Kin.Length; i++) {
        val *= 10;
        val += (Kin.TabKata[i] - '0');
    } 

    return val;
}

void PrintKata(Kata K){
    int i;
    for(i = 0; i < K.Length; i++) {
        printf("%c", K.TabKata[i]);
    }
}