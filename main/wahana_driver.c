#include <stdio.h>
#include "wahana.h"
#include "point.h"

int main() {
    Wahana W;
    Material list_bahan[5];
    int i;

    // LOad material ke list material
    STARTKATA("../files/material.txt", ',');
    while (!EndKata){
        i = 0;
        LoadMaterial(&list_bahan[i]);
        PrintMaterial(list_bahan[i]);
    }
    printf("\n");

    // Load wahana ke wahana W
    STARTKATA("../files/wahana.txt", ',');
    while (!EndKata)
    {
        LoadWahana(&W);
        PrintKata(W.nama); printf("\n");
        TulisPOINT(W.size); printf("\n");
        for(i = 0; i < 5; i++){
            printf("%d", W.bahan[i]); printf("\n");
        }
        PrintKata(W.deskripsi);
        printf("\n");
    }
    
    // tampilkan hasil wahana yang di-input untuk testing
    
    
    return 0;
}