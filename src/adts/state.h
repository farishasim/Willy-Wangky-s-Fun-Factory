/* File : state.h */
/* file ini berisi header adt state, yang merepresentasikan state dari permainan */

#ifndef state_H
#define state_H

#include "mesinkata.h"
#include "map.h"
#include "jam.h"
#include "stackt.h"
#include "queue.h"

typedef int infotype;
typedef int address;   /* indeks tabel */

typedef struct { 
  Kata nama;         /* nama yg di-input oleh player */
  int money;         /* uang yang dimiliki pemain */
  Jam current_time;  /* current time dari permainan */
  int day;           /* hari ke-berapa */
  Map peta;          /* merepresentasikan lahan wahana yang dimiliki oleh pemain */
  Point position;    /* merepresentasikan kordinat posisi pemain berdiri */
  boolean prep_phase; /* bernilai true jika permainan sedang dalam preparation phase */
  Stack act_list;    /* stack untuk menyimpan aksi-aksi pada prep phase */
  Queue antrian;
} State;

/* WARNING!! : Adt state ini masih mentah, */
/* akan banyak mengalami perubahan dan penyesuaian */
/* tergantung dari banyak aspek, misalnya adt yang digunakan*/
/* atau kebutuhan fungsi2 pada game mechanicnya atau yg lainnya*/

#define Name(S) (S).nama
#define Money(S) (S).money
#define Time(S) (S).current_timet
#define Day(S) (S).day
#define Position(S) (S).position
#define Peta(S) (S).peta
#define Prep(S) (S).prep_phase
#define Antrian(S) (S).antrian
#define Act(S) (S).act_list

void StartState(State * S);
/* I.S. sembarang */
/* F.S. State S merupakan state di awal permainan*/

void SaveState(State * S);
/* I.S. State S adalah state permainan yang sedang berlangsung */
/* F.S. State S disimpan ke dalam file eksternal */

void LoadState(State * S);
/* I.S. sembarang */
/* F.S. State S adalah state permainan yang sudah di-save sebelumnya pada suatu file eksternal */


#endif
