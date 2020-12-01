#ifndef wahana_H
#define wahana_H

#include "mesinkata.h"
#include "jam.h"
#include "material.h"
#include "map.h"
#include "listhistory.h"
#include "treewahana.h"

typedef struct twahana * address_w;  // address w adalah tipe pointer to node wahana

typedef struct State_ State;

typedef struct twahana Wahana;
struct twahana {
    Kata nama;
    Kata deskripsi;
    POINT position;
    POINT size;
    ListHistory history;  //  list yang mencatat upgrade history wahana
    BinTree upgrade_tree;
    int ID;
    int harga;
    int kapasitas;
    int banyak_orang;
    int durasi;
    int bahan[5];
    int uang;
    int time_needed;
    int harga_repair;
    int durasi_repair;  // waktu yang diperlukan untuk repair
    int time_reparation;  // waktu yang tersisa untuk selesainya repair
    int count_used;
    int income;
    int count_used1;
    int income1;
    int lahan;  //  lahan dimana wahana ini berada
    boolean starter;  // rencananya starter ini buat menunjukkan kalo suatu wahana itu wahana starter atau hasil upgrade
    boolean broke;
};

typedef struct {
    address_w Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Map_wahana;

/*
Map_wahana adalah sebuah matriks yang setiap elemennya merupakan address memori dari wahana
Selektor Map_Wahana sama seperti matriks, yaitu

*//****** Selektor ******//*
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
*/

void LoadWahana(Wahana * W);
    // I.S. W sembarang
    // F.S. W adalah node wahana yang sudah di-load

void InitialAddressMap(Map_wahana * M, int NB, int NK);
    // I.S. M sembarang, NB dan NK int > 0
    // F.S. akan dibuat M sebagai Map_wahana yang baru

void TulisMATRIKSW (Map_wahana M);

void setAddressMap(Map_wahana * M, Wahana * W, POINT loc);
    // I.S. loc adalah kordinat yang valid dan size valid, 
    //      W adalah wahana yang akan disimpan addressnya pada M
    // F.S. pada M, akan dimasukkan address dari wahana W
    //      yang terletak pada titik : loc,

Wahana getWahanaAt(Map_wahana * M, POINT P);
    // prekondisi : P  point yang valid
    // return value : sebuah wahana yang terletak pada P.

void printDetail(Wahana * W);
    // menampilkan detail wahana ke layar.

void printReport(Wahana * W);
    // menampilkan report wahana ke layar.

void printHistory(Wahana * W);
    // menampilkan history upgrade wahana ke layar.

void printHistory1(ListHistory L);
    // proses rekursif untuk printHistory

void printNextGrade(Wahana * W);
    // menampilkan Upgrade = []

void printNextGrade1(BinTree P, int ID);
    // proses rekurens untuk printNextGrade
    // mencari dan menampilkan semua pilihan upgrade

boolean IsWahanaFull(Wahana * W);
    // true jika suatu wahana full
    // definisi full yaitu banyak orang == kapasitas

boolean IsPosisiEmpty(Map_wahana * M, POINT P, POINT size);
    // true jika wahana bisa dibangun di titik P

void SetPohonWahana(State * S, Wahana * W);

void SetForbiddenAddress(Map_wahana * M, POINT loc);

void SetPermanentAddress(Map_wahana * M);
    // proses : mengubah semua -1 menjadi -2;

void RemoveAddress(Map_wahana * M, address_w W);

void SetTemporer(Map_wahana *M, int i, int j);

int idxWahanaEQbyID(int ID, Wahana W[10]);

#endif
