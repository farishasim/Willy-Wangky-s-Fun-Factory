#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mesinkata.h"
#include "mesinkar.h"

boolean EndKata, counterNL, counterSC;
Kata CKata;

void IgnoreBlank(char separator){
    while (CC==separator || CC == '\n')
    {
        if (CC == '\n')
        {
            counterNL = true;
        }
        else if (CC != '\n')
        {
            counterNL = false;
        }
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
    while ((CC != MARK) && (CC != separator) && (CC != '\n')) {
        if (i < NMax) {
            if (CC == ';')
            {
                counterSC = true;
            }
            else if (CC != ';')
            {
                counterSC = false;
            }
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

<<<<<<< HEAD
int ConvertKata(Kata Kin) {
=======
void writeAString(char* str, FILE** fp)
{
       int i;
       for (i = 0; i < strlen(str); ++i)
       {
              CC = str[i];
              writeAChar(CC, fp);
       }
}

void CopyKata(Kata Kin, Kata * Kout) {
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
    int i;
    int val;
    
    val = 0;
    if (Kin.TabKata[0] == '-'){
        for(i = 1; i < Kin.Length; i++) {
            val *= 10;
            val += (Kin.TabKata[i] - '0');
        } 
        val *= -1;
    }

    else
    {
        for(i = 0; i < Kin.Length; i++) {
            val *= 10;
            val += (Kin.TabKata[i] - '0');
        }
    }
    return val;
}

void writeAString(char* str, FILE** fp)
{
       int i;
       for (i = 0; i < strlen(str); ++i)
       {
              CC = str[i];
              writeAChar(CC, fp);
       }
}

void CopyKata(Kata Kin, Kata * Kout) {
    int i;
<<<<<<< HEAD

    for(i = 0; i < Kin.Length; i++) {
        (*Kout).TabKata[i] = Kin.TabKata[i];
    }

    (*Kout).Length = Kin.Length;
=======
    int val;
    
    val = 0;
    if (Kin.TabKata[0] == '-'){
        for(i = 1; i < Kin.Length; i++) {
            val *= 10;
            val += (Kin.TabKata[i] - '0');
        } 
        val *= -1;
    }

    else
    {
        for(i = 0; i < Kin.Length; i++) {
            val *= 10;
            val += (Kin.TabKata[i] - '0');
        }
    }
    return val;
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
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

void PrintKata(Kata K){
    int i;
    for(i = 0; i < K.Length; i++) {
        printf("%c", K.TabKata[i]);
    }
}
<<<<<<< HEAD

=======
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
