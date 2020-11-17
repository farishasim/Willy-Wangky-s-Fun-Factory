#ifndef wahana_H
#define wahana_H

#include "mesinkata.h"
#include "jam.h"
#include "material.h"
#include "point.h"

typedef struct twahana * address_w;  // address w adalah tipe pointer to node wahana

typedef struct twahana {
    Kata nama;
    Kata deskripsi;
    POINT position;
    POINT size;
    int harga;
    int kapasitas;
    int durasi;
    int bahan[5];
    int uang;
    int harga_repair;
    int durasi_repair;  // waktu yang diperlukan untuk repair
    int time_reparation;  // waktu yang tersisa untuk selesainya repair
    int count_used;
    int income;
    int count_used1;
    int income1;
    boolean broke;
} Wahana;

typedef address_w map_wahana[20][20]; 

void LoadWahana(Wahana * W, Material list[5]);
    // I.S. list[5] adalah list of material yang sudah di-load.
    // F.S. W adalah node wahana yang sudah di-load


void setAddressMap(map_wahana * map_of_address, address_w address_wahana, POINT loc, POINT size);
    // I.S. loc adalah kordinat yang valid dan size valid
    // F.S. pada map of address, akan dimasukkan address dari wahana 
    //      yang terletak pada titik : loc, dengan ukuran wahana : size

Wahana getWahanaAt(map_wahana map_of_address, POINT P);
    // prekondisi : P  point yang valid
    // return value : sebuah wahana yang terletak pada P.

void printDetail(Wahana W);
    // menampilkan detail wahana ke layar.

void printReport(Wahana W);
    //menampilkan report wahana ke layar.

#endif
