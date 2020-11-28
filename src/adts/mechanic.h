#ifndef _game_mechanic_H_
#define _game_mechanic_H_

#include "state.h"

//********* Fungsi-Fungsi untuk command *************//
void W(State *S);

void A(State *S);

void Su(State *S);

void D(State *S);

void Execute(State * S);
/* I.S. user memberi command untuk Execute */
/* F.S. semua aksi yang disimpan pada stack sudah dieksekusi.*/

void Serve(State * S);
/* I.S. user memberi command untuk serve */
/* F.S. serve customer terdepan pada Antrian(S),.*/

void Repair(State * S);
// I.S. user memberi command untuk repair
/* F.S. jika di sebelah kanan user terdapat wahana, 
        dan jika wahana tersebut rusak, dan jika uang user mencukupi, 
        wahana tersebut akan mulai reparation*/

void Detail(State * S);
/* I.S. user memberi command untuk melihat detail wahana*/
/* F.S. jika di sebelah kanan user terdapat wahana, 
        akan ditampilkan detail dari wahana tersebut
        dan waktu akan bertambah sebanyak 2 menit (opsional)*/
        
void OFFice(State * S);
/* I.S. user memberi command untuk mengakses office */
/* F.S. jika user berada pada posisi office, akan ditampilkan antarmuka office
        selama di dalam office, user dapat memberi command Details, Report, Exit
        user akan terus berada di office hingga memberi command Exit*/


//********* Sub-Fungsi untuk Fungsi-fungsi Command *********//
POINT GateSpawnX (State *S);

POINT GateSpawnY (State *S);

void ExecuteBuy(State * S, infostack quest);

void ExecuteBuild(State * S, infostack quest);
/* I.S. S Embarang, mod(quest,10) = 2*/
/* F.S. ListWahana(S) akan bertambah satu elemen di akhir. NWahana(S) di-increment
        PetaAddress(S) akan di set dengan address wahana hasil build*/

void ExecuteUpgrade(State * S, infostack quest);
/* I.S. S Sembarang, mod(quest,10) = 3*/
/* F.S. elemen pada ListWahana akan di ubah menjadi hasil upgradenya.
        PetaAddress(S) akan di set dengan address wahana hasil upgrade*/


//********** Fungsi-fungsi untuk Support ************//
boolean isBetween(int val, int lower, int upper);
// true jika lower <= val <= upper

void printListWahana(State * S);
/* I.S. Sembarang */
/* F.S. Menampilkan semua nama wahana yang dimiliki pemain*/

void incrementTime(State * S);
/* I.S. Sembarang */
/* F.S. Time(S) akan bertambah satu menit, dan 
        semua proses lain akan dijalankan paralel */

void timeFlow(State * S, int N);
// I.S. Sembarang
/* F.S. Time(S) akan bertambah sebanyak N menit dan 
        semua proses lain akan dijalankan paralel*/

void ProcessAllCustomers(State * S);
// I.S. Sembarang
/* F.S. Akan dilakukan proses terhadap semua customer dalam satu satuan waktu
        sehingga seolah-olah proses paralel 
        setelah proses semua cutomer, ada 16.7% chance generate customer*/

void ProcessAllWahanas(State * S);
// I.S. Sembarang
/* F.S. Akan dilakukan proses terhadap semua wahana dalam satu satuan waktu
        sehingga seolah-olah proses paralel */

address_c generateCustomer(State * S);
/* I.S. Sembarang */
/* F.S. didatangkan seorang customer baru. 
        jika antrian sudah penuh, maka customer tersebut pulang lagi
        jika tidak penuh, maka customer akan tercatat di data_customer
        dan customer akan masuk antrian*/

void triggerBroke(address_w W, State * S);
// I.S. seorang pengunjung baru saja berhasil dilayani
// F.S. ada kemungkinan wahana dengan address W menjadi rusak

//********** Fungsi-fungsi RNG ***********//
int Randomize(int lower_bound, int upper_bound);
// menghasilkan bilangan random antara lower_bound dan upper_bound-1

void RandomPlay(address_c P, State * State);
// I.S. Sembarang
/* F.S. RNG for Play(P)*/

#endif
