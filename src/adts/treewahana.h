#ifndef treewahana_H
#define treewahana_H

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

typedef int IdWahana;
typedef struct tNodeTree *address;
typedef struct tNodeTree {
IdWahana info;
address left;
address right;
} NodeTree;

/* Definisi PohonBiner */
/* Pohon Biner kosong P = Nil */
typedef address BinTree;

/* Selektor */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

address AlokasiTree (IdWahana X);
/* Mengirimkan address hasil alokasi sebuah elemen X }
{ Jika alokasi berhasil, maka address tidak nil, dan misalnya
menghasilkan P, maka Info(P)=X, Left(P)=Nil, Right(P)=Nil 
{ Jika alokasi gagal, mengirimkan Nil }*/

void DealokasiTree (address P);
/*{ I.S. P terdefinisi }
{ F.S. P dikembalikan ke sistem }
{ Melakukan dealokasi/pengembalian address P }
*/

//Konstruktor
BinTree Tree (IdWahana X , BinTree L ,BinTree R );
/*{ Menghasilkan sebuah pohon biner dari X, L, dan R, jika alokasi
berhasil }
{ Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (IdWahana X, BinTree L , BinTree R ,BinTree *P );
/*{ I.S. Sembarang }
{ F.S. Menghasilkan sebuah pohon P }
{ Menghasilkan sebuah pohon biner P dari X, L, dan R, jika alokasi berhasil }
{ Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal }*/


IdWahana GetAkar (address P);
// Mengirimkan nilai Akar pohon biner P 

BinTree GetLeft (address P);
// Mengirimkan Anak Kiri pohon biner P 

BinTree GetRight (address P);
//Mengirimkan Anak Kanan pohon biner P 

boolean IsTreeEmpty (BinTree T);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil }
 Menghasilkan pohon kosong (Nil) jika alokasi gagal */


boolean IsOneElmt (BinTree T);
/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen }
*/

boolean IsUnerLeft (BinTree T);
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft:
hanya mempunyai subpohon kiri }*/

boolean IsUnerRight (BinTree T);
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright:
hanya mempunyai subpohon kanan }*/

boolean IsBiner (BinTree T);
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner:
mempunyai subpohon kiri dan subpohon kanan }*/

boolean SearchTree (BinTree T, IdWahana X);
/*{ Mengirimkan true jika ada nodeTree dari P yang bernilai X }
*/

void AddDaun (BinTree P ,IdWahana X, IdWahana Y,boolean Kiri);
/*{ I.S. P tidak kosong, X adalah daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika
Kiri), atau sebagai anak Kanan X (jika not Kiri). Jika ada lebih
dari satu daun bernilai X, Y ditambahkan pada daun paling kiri. }*/

void DelDaun (BinTree P ,IdWahana X );
/*{ I.S. P tidak kosong, minimum 1 daun bernilai X }
{ F.S. Semua daun yang bernilai X dihapus dari P }*/

//********   Fungsi-fungsi lain terkait Tree   *******//
IdWahana SearchSubPohon(BinTree T, IdWahana X, boolean Kiri);
    /* Mengembalikan akar subpohon dari pohon yang memiliki Akar = X */
    /* jika Kiri=true, Mengembalikan akar subpohon kiri */
    /* jika Kiri=false*, Mengembalikan akar subpohon kanan */
    /* prekondisi : jika Kiri true maka pohon harus memiliki sub-pohon kiri
                    jika Kiri false maka pohon harus memiliki subpohon kanan
                    setiap akar pada pohon bernilai unik. dan X ada pada pohon*/

#endif