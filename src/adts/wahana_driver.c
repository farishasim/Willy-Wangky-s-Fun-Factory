#include <stdio.h>
#include "wahana.h"
#include "point.h"

int main() {
    Wahana W;
    Material list_bahan[5];
    Map_wahana addressmap;
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
    LoadWahana(&W);

    printf("%d",&W);

    // tampilkan hasil wahana yang di-input untuk testing
    PrintKata(W.nama); printf("\n");
    TulisPOINT(W.size); printf("\n");
    for(i = 0; i < 5; i++){
        printf("%d",W.bahan[i]); printf("\n");
    }
    PrintKata(W.deskripsi);

    printf("%c", CC);

    // testing map of address
    Elmt(addressmap,0,0) = &W;
    printf("%d", Elmt(addressmap,0,0));

    // tampilkan hasil wahana yang di-input untuk testing
    // dengan mencoba menggunakan address wahana
    PrintKata((*Elmt(addressmap,0,0)).nama); printf("\n");
    TulisPOINT((*Elmt(addressmap,0,0)).size); printf("\n");
    for(i = 0; i < 5; i++){
        printf("%d",(*Elmt(addressmap,0,0)).bahan[i]); printf("\n");
    }
    PrintKata((*Elmt(addressmap,0,0)).deskripsi);

    return 0;
}