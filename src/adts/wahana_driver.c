#include <stdio.h>
#include "wahana.h"
#include "point.h"

int main() {
    Wahana W;
    Material list_bahan[5];
    map_wahana addressmap;
    int i;

    // LOad material ke list material
    START("../../file/tes_material.txt");
    for(i = 0; i < 5; i++){
        LoadMaterial(&list_bahan[i]);
        PrintMaterial(list_bahan[i]);
    }
    printf("%c", CC);

    // Load wahana ke wahana W
    START("../../file/teswahana.txt");
    LoadWahana(&W, list_bahan);

    printf("%d",&W);

    // tampilkan hasil wahana yang di-input untuk testing
    PrintKata(W.nama); printf("\n");
    TulisPOINT(W.size); printf("\n");
    for(i = 0; i < 5; i++){
        PrintMaterial(W.bahan[i]); printf("\n");
    }
    PrintKata(W.deskripsi);

    printf("%c", CC);

    // testing map of address
    addressmap[0][0] = &W;
    printf("%d", addressmap[0][0]);

    // tampilkan hasil wahana yang di-input untuk testing
    // dengan mencoba menggunakan address wahana
    PrintKata((*addressmap[0][0]).nama); printf("\n");
    TulisPOINT((*addressmap[0][0]).size); printf("\n");
    for(i = 0; i < 5; i++){
        PrintMaterial((*addressmap[0][0]).bahan[i]); printf("\n");
    }
    PrintKata((*addressmap[0][0]).deskripsi);

    return 0;
}