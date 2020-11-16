/* File : state.h */
/* file ini berisi header adt state, yang merepresentasikan state dari permainan */

#ifndef state_H
#define state_H

#include "mesinkata.h"
#include "map.h"
#include "point.h"
#include "jam.h"
//#include "stackt.h"
//#include "queue.h"

typedef int infotype;
typedef int address;   /* indeks tabel */

typedef struct { 
  Kata username;         /* nama yg di-input oleh player */
  int money;         /* uang yang dimiliki pemain */
  int day;           /* hari ke-berapa */
  int NWahana;       /* banyaknya wahana yang dimiliki pemain*/
  int tempActs;
  int neededTime;
  int neededMoney;
  JAM current_time;  /* current time dari permainan */
  JAM openTime;     /* Waktu taman bermain dibuka */
  JAM closeTime;      /* Waktu taman bermain ditutup */
  Map peta;          /* merepresentasikan lahan wahana yang dimiliki oleh pemain */
  POINT office;     /* merepresentasikan kordinat posisi office berada*/
  POINT position;    /* merepresentasikan kordinat posisi pemain berdiri */
  POINT locAntrian;     /* merepresentasikan kordinat posisi office berada*/ 
  boolean prep_phase; /* bernilai true jika permainan sedang dalam preparation phase */
  //Stack act_list;    /* stack untuk menyimpan aksi-aksi pada prep phase */
  //prior_qu antrian;
  //Wahana listWahana[5];  /* list semua wahana yang dimiliki pemain */
  //map_wahana map_address;  // map yang setiap elemennya merupakan address dari suatu wahana
} State;

/* WARNING!! : Adt state ini masih mentah, */
/* akan banyak mengalami perubahan dan penyesuaian */
/* tergantung dari banyak aspek, misalnya adt yang digunakan*/
/* atau kebutuhan fungsi2 pada game mechanicnya atau yg lainnya*/

#define Name(S) (S).username
#define Money(S) (S).money
#define Time(S) (S).current_time
#define TempActs(S) (S).tempActs
#define MoneyNeeded(S) (S).neededMoney
#define TimeNeeded(S) (S).neededTime
#define OpenTime(S) (S).openTime
#define CloseTime(S) (S).closeTime
#define Day(S) (S).day
#define Position(S) (S).position
#define Office(S) (S).office
#define LocAntrian(S) (S).locAntrian
#define Peta(S) (S).peta
#define Prep(S) (S).prep_phase
//#define Antrian(S) (S).antrian
//#define Act(S) (S).act_list

void loading(State* S, char* filename, boolean isInput, boolean isLoad);

void saving(State S, char* filename);

void svPlayerName(FILE** fp, State S);

void ldPlayerName(State *S, boolean isLoad);

void svMDP(char* mdp, FILE** fp, State S);

void ldMDP(char* mdp, State *S);

void svPos(FILE** fp, State S);

void ldPos(State* S, boolean isInput);

void svTime(FILE** fp, State S);

void ldTime(State *S, boolean isInput);

void svInfoActs(FILE** fp, State S);

void ldInfoActs(State *S);

#endif