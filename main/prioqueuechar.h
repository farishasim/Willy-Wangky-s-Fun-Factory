/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut tidak mengecil berdasarkan elemen prio */
/* Elemen queue adalah address memori dari customer*/

#ifndef prioqueuechar_H
#define prioqueuechar_H

#include "boolean.h"
#include "listcustomer.h"

#define Nilqueue -1
/* Konstanta untuk mendefinisikan idxqueue tak terdefinisi */

/* Definisi elemen dan idxqueue */

typedef address_c infoqueue;

typedef int idxqueue;   /* indeks tabel */
/* Contoh deklarasi variabel bertype PrioQueueChar : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */

typedef struct {
    infoqueue * T;   /* tabel penyimpan elemen */
    idxqueue HEAD;  /* alamat penghapusan */
    idxqueue TAIL;  /* alamat penambahan */
    int MaxEl;     /* Max elemen queue */
} PrioQueueChar;
/* Definisi PrioQueueChar kosong: HEAD=Nil; TAIL=Nil. */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah infoqueue dan Q adalah PrioQueueChar, maka akses elemen : */

#define Head(Q)     (Q).HEAD
#define Tail(Q)     (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q)    (Q).MaxEl
#define ElmtQueue(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmptyQueue (PrioQueueChar Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue (PrioQueueChar Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmtQueue (PrioQueueChar Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmptyQueue (PrioQueueChar * Q, int Max);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infoqueue X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueChar * Q, infoqueue * X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q); /// mungkin bisa buat printcustomer;
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

void ReSort(PrioQueueChar * Q, infoqueue P);
/* I.S. Q tidak mungkin kosong, P adalah elemen pada Q*/
/* F.S. Pada waktu tertentu, P mungkin berubah prioritasnya 
        sehingga perlu di sort khusus untuk P saja
        P akan ditempatkan pada urutan yang seharusnya*/

#endif