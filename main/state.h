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


typedef struct {
  Kata username;         /* nama yg di-input oleh player */
  int money;         /* uang yang dimiliki pemain */
  int day;           /* hari ke-berapa */
  int NWahana;       /* banyaknya wahana yang dimiliki pemain*/
  int infoPrep[3]; /*temp_acts, needTime, neededMoney*/
  JAM time[3];  /*cur_time, open_time, close_time*/
  Map peta;          /* merepresentasikan lahan wahana yang dimiliki oleh pemain */
  POINT objectsLoc[3]; /*positionPlayer, office, locAntrian*/
  boolean prep_phase; /* bernilai true jika permainan sedang dalam preparation phase */
  Stack act_list;    /* stack untuk menyimpan aksi-aksi pada prep phase */
  Material material[5];
  ListCustomer data_customer;
  PrioQueueChar antrian;
  Wahana data_wahana[10];  /* data semua wahana yang tersedia pada permainan */
  address_w listWahana[5];  /* list semua wahana yang dimiliki pemain */  // [&DataWahana[1],nil,nil,nil,nil]
  map_wahana map_address;  // map yang setiap elemennya merupakan address dari suatu wahana
} State;


/* WARNING!! : Adt state ini masih mentah, */
/* akan banyak mengalami perubahan dan penyesuaian */
/* tergantung dari banyak aspek, misalnya adt yang digunakan*/
/* atau kebutuhan fungsi2 pada game mechanicnya atau yg lainnya*/

#define Name(S) (S).username
#define Money(S) (S).money
#define Time(S) (S).time[0]
#define OpenTime(S) (S).time[1]
#define CloseTime(S) (S).time[2]
#define TempActs(S) (S).infoPrep[0]
#define MoneyNeeded(S) (S).infoPrep[1]
#define TimeNeeded(S) (S).infoPrep[2]
#define Day(S) (S).day
#define Position(S) (S).objectsLoc[0]
#define Office(S) (S).objectsLoc[1]
#define LocAntrian(S) (S).objectsLoc[2]
#define Peta(S) (S).peta
#define Prep(S) (S).prep_phase
#define Materials(S) (S).material
#define Antrian(S) (S).antrian
#define Act(S) (S).act_list
#define ListWahana(S) (S).listWahana
#define DataCustomers(S) (S).data_customer
#define DataWahana(S)  (S).data_wahana
#define NWahana(S) (S).NWahana

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

#endif
