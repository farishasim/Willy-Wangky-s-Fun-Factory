/* File : state.h */
/* file ini berisi header adt state, yang merepresentasikan state dari permainan */

#ifndef state_H
#define state_H

#include "mesinkata.h"
#include "map.h"
#include "jam.h"
#include "stackt.h"
#include "prioqueuechar.h"
#include "wahana.h"
#include "graph2.h"

typedef struct State_ State;

struct State_ {
  Kata username;         /* nama yg di-input oleh player */
  POINT objectsLoc[3]; /*positionPlayer, office, locAntrian*/
  JAM time[3];    /*cur_time, open_time, close_time*/
  int money;         /* uang yang dimiliki pemain */
  int day;           /* hari ke-berapa */
  boolean prep_phase; /* bernilai true jika permainan sedang dalam preparation phase */
  int infoPrep[3]; /*temp_acts, neededTime, neededMoney*/
  Stack act_list;    /* stack untuk menyimpan aksi-aksi pada prep phase */
  PrioQueueChar antrian;
  int NWahana;       /* banyaknya wahana yang dimiliki pemain*/
  Graph area;          /* lahan yang sedang diinjak pemain */
  ListCustomer data_customer;
  Wahana data_wahana[10];  /* data semua wahana yang tersedia pada permainan */
  address_w listWahana[5];  /* list semua wahana yang dimiliki pemain */  // [&DataWahana[1],nil,nil,nil,nil]
  Map peta[4];              /* merepresentasikan lahan wahana yang dimiliki oleh pemain */
  Map_wahana peta_address[4];  // map yang setiap elemennya merupakan address dari suatu wahana
  Material Storage[5];
};


/* WARNING!! : Adt state ini masih mentah, */
/* akan banyak mengalami perubahan dan penyesuaian */
/* tergantung dari banyak aspek, misalnya adt yang digunakan*/
/* atau kebutuhan fungsi2 pada game mechanicnya atau yg lainnya*/

#define Name(S) (S).username
#define Money(S) (S).money
#define Day(S) (S).day
#define Time(S) (S).time[0]
#define OpenTime(S) (S).time[1]
#define CloseTime(S) (S).time[2]
#define TempActs(S) (S).infoPrep[0]
#define MoneyNeeded(S) (S).infoPrep[1]
#define TimeNeeded(S) (S).infoPrep[2]
#define Position(S) (S).objectsLoc[0]
#define Office(S) (S).objectsLoc[1]
#define LocAntrian(S) (S).objectsLoc[2]
#define Prep(S) (S).prep_phase
#define Storage(S) (S).Storage
#define Antrian(S) (S).antrian
#define Act(S) (S).act_list
#define ListWahana(S) (S).listWahana
#define DataCustomers(S) (S).data_customer
#define DataWahana(S)  (S).data_wahana
#define NWahana(S) (S).NWahana

// SELEKTOR Peta yang sedang aktif
// aktif artinya dimana pemain sedang berada
#define Area(S) (S).area //  area yang sedang aktif
#define Peta(S) (S).peta[(S).area.First->info]
#define PetaAddress(S) (S).peta_address[(S).area.First->info]
/*
[0] -- [1]
 |      |
 |      |
[2] -- [3]
*/// di Peta(S) diganti strip
// moveup



// Selektor Wahana dengan ID (ada pada state S)
#define GetWahana(S,ID) (S).data_wahana[ID]
// untuk mendapat address-nya dapat dengan 
/////// &GetWahana(S,ID)


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

void svCurMaterial(FILE** fp, State S);

void ldMaterial(State* S);

void svActList(FILE** fp, State S);

void ldActList(State* S);

void svQueue(FILE** fp, State S);

void ldQueue (State* S);

void ldDefWahana(State* S);

void svWahanaPlayer(FILE** fp, State S);

void ldWahanaPlayer(State* S);

#endif
