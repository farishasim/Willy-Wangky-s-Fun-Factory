/* File : state.h */
/* file ini berisi header adt state, yang merepresentasikan state dari permainan */

#ifndef state_H
#define state_H

#include "mesinkata.h"
#include "map.h"
#include "jam.h"
#include "stackt.h"
#include "PrioQueueChar.h"
#include "wahana.h"
#include "graph2.h"


typedef struct {
  Kata username;         /* nama yg di-input oleh player */
  int money;         /* uang yang dimiliki pemain */
  int day;           /* hari ke-berapa */
  int NWahana;       /* banyaknya wahana yang dimiliki pemain*/
  int tempActs;
  int neededTime;
  int neededMoney;
  JAM current_time;  /* current time dari permainan */
  JAM openTime;       /* Waktu taman bermain dibuka */
  JAM closeTime;      /* Waktu taman bermain ditutup */
  Graph area;          /* lahan yang sedang diinjak pemain */
  POINT office;     /* merepresentasikan kordinat posisi office berada*/
  POINT position;    /* merepresentasikan kordinat posisi pemain berdiri */
  POINT locAntrian;     /* merepresentasikan kordinat posisi antrian berada*/ 
  boolean prep_phase; /* bernilai true jika permainan sedang dalam preparation phase */
  Stack act_list;    /* stack untuk menyimpan aksi-aksi pada prep phase */
  ListCustomer data_customer;
  PrioQueueChar antrian;
  Wahana data_wahana[10];  /* data semua wahana yang tersedia pada permainan */
  address_w listWahana[5];  /* list semua wahana yang dimiliki pemain */  // [&DataWahana[1],nil,nil,nil,nil]
  Map peta[4];              /* merepresentasikan lahan wahana yang dimiliki oleh pemain */
  Map_wahana peta_address[4];  // map yang setiap elemennya merupakan address dari suatu wahana
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
#define Prep(S) (S).prep_phase
#define Antrian(S) (S).antrian
#define Act(S) (S).act_list
#define ListWahana(S) (S).listWahana
#define DataCustomers(S) (S).data_customer
#define DataWahana(S)  (S).data_wahana
#define NWahana(S) (S).NWahana

// SELEKTOR Peta yang sedang aktif
// aktif artinya dimana pemain sedang berada
#define Area(S) (S).area  //  area yang sedang aktif
#define Peta(S) (S).peta[(S).area.First->info]
#define PetaAddress(S) (S).peta_address[(S).area.First->info]

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
