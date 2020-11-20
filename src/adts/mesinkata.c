
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(char separator){
    while (CC==separator)
    {
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char * namafile, char separator){
    START(namafile);
    IgnoreBlank(separator);
    if (CC==MARK){
        EndKata=true;
    }
    else {
        EndKata=false;
        ADVKATA(separator);
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


void convert2StrKata(char** str, int integer)
{
    *str = malloc (snprintf(NULL, 0, "%d", integer) + 1);
    if (!*str)
    {
        printf("Maaf, terjadi kesalahan saat mengonversi data.\n");
    }
    snprintf(*str, snprintf(NULL, 0, "%d", integer) + 1, "%d", integer);
}


char* appended2Strings(char* str1, char* str2)
{   
    char* new;
    if ((new = malloc((strlen(str1) + strlen(str2)))) != NULL)
    {
        new[0] = '\0';
        strncat(new, str1, strlen(str1));
        strncat(new, str2, strlen(str2));
    }

    else
    {
        printf("Maaf, terjadi kesalahan saat mengkonkatenasi data.\n");
    }

    return new;
}


void PrintKata(Kata K){
    int i;
    for(i = 0; i < K.Length; i++) {
        printf("%c", K.TabKata[i]);
    }
}


boolean isKataSama(Kata K1, char* K2)
{
    if (K1.Length != strlen(K2)) return 0;

    else
    {
        int i;
        for(i = 0; i < K1.Length; ++i)
        {
            if (K1.TabKata[i] != K2[i]) return 0;
        }

        return 1;
    }
}