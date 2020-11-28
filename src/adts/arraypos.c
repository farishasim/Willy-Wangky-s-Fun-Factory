/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */
#include <stdio.h>
#include "arraypos.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T){
   int i ;
   for (i = IdxMin; i <=IdxMax ; i++) {
      (*T).TI[i]=ValUndef ;
   }
}
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtTab (TabInt T){
   int i;
   int j=0;
   for (i = IdxMin; i <=IdxMax ; i++) {
      if (T.TI[i] != ValUndef){
         j++;
      }
   }
   return j;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */

int MaxNbEl (TabInt T){
   int i = IdxMax-IdxMin;
   return i+1;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
   int i=IdxMin;
   while (T.TI[i]==ValUndef){i++;}
   return i;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T){
   int i=IdxMax;
   while (T.TI[i]==ValUndef){i--;}
   return i;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i){
   if (i>=IdxMin && i<=IdxMax) {
      return true;
   }
   else {
      return false;
   }
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff (TabInt T, IdxType i){
   if (i>=GetFirstIdx(T) && i<=GetLastIdx(T)) {
      return true;
   }
   else {
      return false;
   }
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T){
   if (NbElmtTab(T)==0) {
      return true;
   }
   else {
      return false;
   }
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull (TabInt T){
   if (NbElmtTab(T)==MaxNbEl(T)) {
      return true;
   }
   else {
      return false;
   }
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T){
   MakeEmpty(T);
   int N=-1;
   while (N<0 || N> MaxNbEl(*T)){
      scanf("%d\n",&N);
   }

   if (N!=0){
      int i;
      for (i=0;i<=N;i++){
         scanf("%d\n", &(*T).TI[i]);
      }
   }
   
}
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T); Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab (TabInt T){
   printf("[");
   if (IsEmpty(T)==false){
      int i;
      for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
         printf("%d",T.TI[i]);
         if (i>=GetFirstIdx(T) && i<GetLastIdx(T)){
            printf(",");
         }
      }
   }
   printf("]");
}
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku; 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus){
   TabInt hasil;
   int i;
   MakeEmpty(&hasil);
   for (i=GetFirstIdx(T2);i<=GetLastIdx(T2);i++){
      if (plus==true && ElmtTab(T1,i)!=ValUndef && ElmtTab(T2,i)!=ValUndef){
         ElmtTab(hasil,i) = ElmtTab(T1,i)+ElmtTab(T2,i);
      }
      else if (plus==false && ElmtTab(T1,i)!=ValUndef && ElmtTab(T2,i)!=ValUndef){
         ElmtTab(hasil,i) = ElmtTab(T1,i)-ElmtTab(T2,i);
      }
      else {
         ElmtTab(hasil,i) = 0;
      }   
   }
   return hasil;
}
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2){
   if (NbElmtTab(T1)==NbElmtTab(T2)){
      int i;
      while (ElmtTab(T1,i)==ElmtTab(T2,i) && i<MaxNbEl(T2)) {
         i++;
         return true;
      }
   }
   else {
      return false;
   }
}

/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElTab X){
   if (IsEmpty(T)){
      return IdxUndef;
   }
   else {
      int i=0;
      int pos;
      while (ElmtTab(T, i)!=X && i<GetLastIdx(T)){
         if (ElmtTab(T, i)==X){
            pos=i;
            i++;
         }
         else {
            pos = IdxUndef;
            i++;
         }
      }
      return pos;
   }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB (TabInt T, ElTab X){
   if (IsEmpty(T)){
      return false;
   }
   else {
      int i=0;
      boolean pos;
      while (ElmtTab(T, i)!=X && i<GetLastIdx(T)){
         if (ElmtTab(T, i)==X){
            pos=true;
            i++;
         }
         else {
            pos = false;
            i++;
         }
      }
      return pos;
   }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElTab * Max, ElTab * Min){
   int nmaks,nmin,i;
   nmaks = ElmtTab(T,GetFirstIdx(T));
   nmin = ElmtTab(T,GetFirstIdx(T));
   for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      if (ElmtTab(T,i)>nmaks){
         nmaks = ElmtTab(T,i);
      }
      if (ElmtTab(T,i)<nmin){
         nmin = ElmtTab(T,i);
      }
   }
   *Max = nmaks;
   *Min = nmin;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
ElTab SumTab (TabInt T){
   if (IsEmpty(T)){
      return 0;
   }
   int i;
   int sum=0;
   for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      if (ElmtTab(T,i)!= ValUndef){
         sum = sum+ ElmtTab(T,i);
      }
   }
   return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX (TabInt T, ElTab X){
   if (IsEmpty(T)){
      return 0;
   }
   int i;
   int count=0;
   for (i=GetFirstIdx(T);i<=GetLastIdx(T);i++){
      if (ElmtTab(T,i)== X){
         count = count + 1;
      }
   }
   return count;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap (TabInt T){
   int i=0;
   boolean genap=true;
   while (i<=GetLastIdx(T) && genap==true){
      if (ElmtTab(T,i)%2!=0){
         genap = false;
      }
   }
   return genap;
}

/* Menghailkan true jika semua elemen T genap */


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElTab X){
   (*T).TI[GetLastIdx(*T)+1] = X;
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElTab * X){
   *X=(*T).TI[GetLastIdx(*T)];
   (*T).TI[GetLastIdx(*T)] =ValUndef;
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */