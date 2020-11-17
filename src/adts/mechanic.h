#ifndef _game_mechanic_H_
#define _game_mechanic_H_

#include "state.h"

//********* Fungsi-Fungsi untuk command *************//
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
        
void Office(State * S);
/* I.S. user memberi command untuk mengakses office */
/* F.S. jika user berada pada posisi office, akan ditampilkan antarmuka office
        selama di dalam office, user dapat memberi command Details, Report, Exit
        user akan terus berada di office hingga memberi command Exit*/


//********** Fungsi-fungsi untuk Support ************//
void printListWahana(State * S);
/* I.S. Sembarang */
/* F.S. Menampilkan semua nama wahana yang dimiliki pemain*/

void incrementTime(State * S);
/* I.S. Sembarang */
/* F.S. Time(S) akan bertambah satu menit, dan semua proses lain akan dijalankan paralel */

void timeFlow(State * S, int N);
// I.S. Sembarang
// F.S. Time(S) akan bertambah sebanyak N menit dan semua proses lain akan dijalankan paralel

#endif