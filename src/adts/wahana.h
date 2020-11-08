#ifndef wahana_H
#define wahana_H

#include "mesinkata.h"
#include "jam.h"
#include "material.h"
#include "point.h"

typedef struct {
    Kata nama;
    Kata deskripsi;
    POINT position;
    POINT size;
    int harga;
    int kapasitas;
    int durasi;
    Material bahan[5];
    int uang;
    int count_used;
    int income;
    int count_used1;
    int income1;
} Wahana;

void LoadWahana(Wahana * W, Material list[5]);

#endif
