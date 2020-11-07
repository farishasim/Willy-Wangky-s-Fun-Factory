#ifndef material_H
#define material_H

#include "mesinkata.h"

typedef struct {
    Kata nama;
    int harga;
    int quantity;
} Material;

void LoadMaterial(Material mat);

void WriteMaterial(Material mat);

#endif