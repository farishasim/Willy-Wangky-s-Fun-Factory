#include "listcustomer.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST listcustomer KOSONG ******************/
boolean IsEmpty (ListCustomer L) {
/* Mengirim true jika listcustomer kosong */
    return (First(L) == Nil);
}

/****************** PEMBUATAN listcustomer KOSONG ******************/
void CreateEmpty (ListCustomer *L) {
/* I.S. sembarang             */
/* F.S. Terbentuk listcustomer kosong */
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address_c Alokasi () {
/* Mengirimkan address_c hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_c tidak nil, dan misalnya */
/* menghasilkan P, maka Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
    address_c P;
    P = Nil;
    P = (address_c) malloc(sizeof(Customer));
    if (P) {
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi (address_c *P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_c P */
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LISTCustomer ******************/
boolean FSearch (ListCustomer L, address_c P) {
/* Mencari apakah ada elemen listcustomer yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
    address_c srcP;

    srcP = First(L);
    while ((srcP != Nil) && (srcP != P)) {
        srcP = Next(srcP);
    }
    return (srcP == P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListCustomer *L, address_c P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_c P sebagai elemen pertama */
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter (ListCustomer *L, address_c P, address_c Prec) {
/* I.S. Prec pastilah elemen listcustomer dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast (ListCustomer *L, address_c P) {
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    address_c Prec;

    if (IsEmpty(*L)) {
        InsertFirst(L,P);
    } else {
    Prec = First(*L);
    while (Next(Prec) != Nil) {
        Prec = Next(Prec);
    }
    // prec adalah elemen terakhir
    InsertAfter(L,P,Prec);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListCustomer *L, address_c *P) {
/* I.S. ListCustomer tidak kosong */
/* F.S. P adalah alamat elemen pertama listcustomer sebelum penghapusan */
/*      Elemen listcustomer berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelLast (ListCustomer *L, address_c *P) {
/* I.S. ListCustomer tidak kosong */
/* F.S. P adalah alamat elemen terakhir listcustomer sebelum penghapusan  */
/*      Elemen listcustomer berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
    address_c Prec;

    Prec = First(*L);
    if (Next(Prec) == Nil) { // listcustomer 1 elemen
        DelFirst(L,P);
    } else {
        while (Next(Next(Prec)) != Nil) {
            Prec = Next(Prec);
        }
        // Next(Next(Prec)) == Nil
        DelAfter(L,P,Prec);
    }
}

void DelAfter (ListCustomer *L, address_c *Pdel, address_c Prec) {
/* I.S. ListCustomer tidak kosong. Prec adalah anggota listcustomer  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen listcustomer yang dihapus  */
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN listcustomer ******************/
void PrintInfo (ListCustomer L) {
/* I.S. ListCustomer mungkin kosong */
/* F.S. Jika listcustomer tidak kosong, iai listcustomer dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika listcustomer kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    address_c P;

    printf("[");
    P = First(L);
    if (P != Nil) {
        printf("%d", Kesabaran(P));
        P = Next(P);
    }
    while (P != Nil) {
        printf(",%d", Kesabaran(P));
        P = Next(P);        
    }
    printf("]");
}

int NbElmtList (ListCustomer L) {
/* Mengirimkan banyaknya elemen listcustomer; mengirimkan 0 jika listcustomer kosong */
    int count;
    address_c P;

    count = 0;
    P = First(L);
    while (P != Nil) {
        count++;
        P = Next(P);
    }

    return count;
}

//***************** PROSES-PROSES LAIN UNTUK CUSTOMER ********************//
int PlayCount(address_c P) {
/* Mengirimkan banyaknya wahana yang ingin dinaiki cutomer*/
    int count,i;

    // skema menghitung banyaknya wahana yang ingin dinaiki customer
    count = 0;
    for (i=0; i<5; i++) {
        if (Play(P,i) != -1) {
            count++;
        }
    }

    return count;
}