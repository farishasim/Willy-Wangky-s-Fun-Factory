/* File: LISTHISTORY.h */
/* ADT List History yang mencatat history upgrade wahana*/
/* menggunakan ADT list linier dengan representasi pointer */
/* Implementasi list linier secara rekursif */

#ifndef _LISTHISTORY_H_
#define _LISTHISTORY_H_

#include "boolean.h"
#include "listcustomer.h"

/* Definisi Type */
typedef struct twahana * infohistory; // infotype berupa address dari wahana
typedef struct tElmtlistHistory * address_h;
typedef struct tElmtlistHistory { 
	infohistory info;
	address_h next;
} ElmtListHistory;

/* Definisi listHistory : */
/* ListHistory kosong : L = Nil */
typedef address_h ListHistory;

/* Deklarasi  nama untuk variabel kerja */ 
/*  	L : ListHistory */
/*  	P : address_h 	*/
/* Maka penulisan First(L) menjadi L */
/*                P.info menjadi Info(P); P.next menjadi Next(P) */

/* Selektor */
// #define Info(L) (L)->info
// #define Next(P) (P)->next

/* *** Manajemen Memori *** */
address_h AlokasiH (infohistory X);
/* Mengirimkan address_h hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_h tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokasiH (address_h P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_h P */

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListHistory */
int IsEmptyHistory(ListHistory L);
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
int IsOneHistory(ListHistory L);
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */

/* *** Selektor *** */
infohistory FirstHistory(ListHistory L);
/* Mengirimkan elemen pertama sebuah listHistory L yang tidak kosong */
ListHistory TailHistory(ListHistory L);
/* Mengirimkan listHistory L tanpa elemen pertamanya, mungkin menjadi listHistory kosong */

/* *** Konstruktor *** */
ListHistory Konso(infohistory e, ListHistory L);
/* Mengirimkan listHistory L dengan tambahan e sebagai elemen pertamanya. 
e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L. */
ListHistory KonsB(ListHistory L, infohistory e);
/* Mengirimkan listHistory L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan L */ 

/* *** Operasi Lain *** */
ListHistory Copy (ListHistory L);
/* Mengirimkan salinan listHistory L (menjadi listHistory baru) */
/* Jika ada alokasi gagal, mengirimkan L */ 
void MCopy (ListHistory Lin, ListHistory *Lout);
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
ListHistory Concat (ListHistory L1, ListHistory L2);
/* Mengirimkan salinan hasil konkatenasi listHistory L1 dan L2 (menjadi listHistory baru) */
/* Jika ada alokasi gagal, menghasilkan Nil */
void MConcat (ListHistory L1, ListHistory L2, ListHistory *LHsl);
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi listHistory L1 dan L2 */
void PrintListHistory (ListHistory L);
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen listHistory dicetak. */
int NbElmtListHistory (ListHistory L);
/* Mengirimkan banyaknya elemen listHistory L, Nol jika L kosong */
boolean Search (ListHistory L, infohistory X);
/* Mengirim true jika X adalah anggota listHistory, false jika tidak */


#endif