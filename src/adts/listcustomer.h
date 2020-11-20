/* File : ListCustomerlinier.h */
/* contoh ADT ListCustomer berkait dengan representasi fisik pointer  */
/* Representasi address_c dengan pointer */
/* ElmtType adalah customer */

#ifndef ListCustomerlinier_H
#define ListCustomerlinier_H

#include "boolean.h"

#define Nil NULL

typedef struct tCustomer * address_c;

typedef struct tCustomer { 
	int prio; /* [1..10], prioritas dengan nilai 1..10 (1 adalah prioritas tertinggi) */
    int play[5];  /* [1..10], prioritas dengan nilai 1..10 (1 adalah prioritas tertinggi) */
    int loc;  
    int time;
    int kesabaran;
	address_c next;
} Customer;

typedef struct {
	address_c First;
} ListCustomer;

/* Definisi ListCustomer : */
/* ListCustomer kosong : First(L) = Nil */
/* Setiap elemen dengan address_c P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListCustomer : jika address_cnya Last, maka Next(Last)=Nil */

#define Prio(P)   (P)->prio
#define Play(P,i) (*P).play[i]
#define Loc(P)    (P)->loc
#define Playtime(P) (P)->time
#define Kesabaran(P) (P)->kesabaran
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST ListCustomer KOSONG ******************/
boolean IsEmpty (ListCustomer L);
/* Mengirim true jika ListCustomer kosong */

/****************** PEMBUATAN ListCustomer KOSONG ******************/
void CreateEmpty (ListCustomer *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListCustomer kosong */

/****************** Manajemen Memori ******************/
address_c Alokasi ();
/* Mengirimkan address_c hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_c tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address_c *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_c P */

/****************** PENCARIAN SEBUAH ELEMEN ListCustomer ******************/
boolean FSearch (ListCustomer L, address_c P);
/* Mencari apakah ada elemen ListCustomer yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListCustomer *L, address_c P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_c P sebagai elemen pertama */
void InsertAfter (ListCustomer *L, address_c P, address_c Prec);
/* I.S. Prec pastilah elemen ListCustomer dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (ListCustomer *L, address_c P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListCustomer *L, address_c *P);
/* I.S. ListCustomer tidak kosong */
/* F.S. P adalah alamat elemen pertama ListCustomer sebelum penghapusan */
/*      Elemen ListCustomer berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */

void DelLast (ListCustomer *L, address_c *P);
/* I.S. ListCustomer tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListCustomer sebelum penghapusan  */
/*      Elemen ListCustomer berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListCustomer *L, address_c *Pdel, address_c Prec);
/* I.S. ListCustomer tidak kosong. Prec adalah anggota ListCustomer  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListCustomer yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListCustomer ******************/
void PrintInfo (ListCustomer L);
/* I.S. ListCustomer mungkin kosong */
/* F.S. Jika ListCustomer tidak kosong, iai ListCustomer dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListCustomer kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int NbElmt (ListCustomer L);
/* Mengirimkan banyaknya elemen ListCustomer; mengirimkan 0 jika ListCustomer kosong */


//***************** PROSES-PROSES LAIN UNTUK CUSTOMER ********************//
int PlayCount(address_c P);
/* Mengirimkan banyaknya wahana yang ingin dinaiki cutomer*/

#endif