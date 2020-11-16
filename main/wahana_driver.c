#include <stdio.h>
#include "wahana.h"
#include "point.h"

int main() {
    Wahana W;
    Material list_bahan[5];
    int i;

    // LOad material ke list material
    START("../file/material.txt");
    for(i = 0; i < 5; i++){
        LoadMaterial(&list_bahan[i]);
        PrintMaterial(list_bahan[i]);
    }
    printf("%c", CC);

    // Load wahana ke wahana W
    START("../file/wahana.txt");
    LoadWahana(&W, list_bahan);

    // tampilkan hasil wahana yang di-input untuk testing
    PrintKata(W.nama); printf("\n");
    TulisPOINT(W.size); printf("\n");
    for(i = 0; i < 5; i++){
        PrintMaterial(W.bahan[i]); printf("\n");
    }
    PrintKata(W.deskripsi);

    printf("%c", CC);

    return 0;
}