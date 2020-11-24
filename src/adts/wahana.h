#ifndef wahana_H
#define wahana_H

#include "mesinkata.h"
#include "jam.h"
#include "material.h"
#include "map.h"

typedef struct twahana * address_w;  // address w adalah tipe pointer to node wahana

typedef struct twahana {
    Kata nama;
    Kata deskripsi;
    POINT position;
    POINT size;
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
    // boolean starter;  // rencananya starter ini buat menunjukkan kalo suatu wahana itu wahana starter atau hasil upgrade
    boolean broke;
} Wahana;

typedef struct {
    address_w Mem[BrsMax+1][KolMax+1];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} Map_wahana;

/*
Map_wahana adalah sebuah matriks yang setiap elemennya merupakan address memori dari wahana
Selektor Map_Wahana sama seperti matriks, yaitu
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]
*/

void LoadWahana(Wahana * W);
    // I.S. list[5] adalah list of material yang sudah di-load.
    // F.S. W adalah node wahana yang sudah di-load

void setAddressMap(Map_wahana * M, Wahana * W, POINT loc, POINT size);
    // I.S. loc adalah kordinat yang valid dan size valid, 
    //      W adalah wahana yang akan disimpan addressnya pada PetaAddress(S)
    // F.S. pada PetaAddress(S), akan dimasukkan address dari wahana W
    //      yang terletak pada titik : loc, dengan ukuran wahana : size

Wahana getWahanaAt(Map_wahana * M, POINT P);
    // prekondisi : P  point yang valid
    // return value : sebuah wahana yang terletak pada P.

void printDetail(Wahana * W);
    // menampilkan detail wahana ke layar.

void printReport(Wahana * W);
    //menampilkan report wahana ke layar.

boolean IsWahanaFull(Wahana * W);
    // true jika suatu wahana full
    // definisi full yaitu banyak orang == kapasitas

#endif
