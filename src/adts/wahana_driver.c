#include <stdio.h>
#include "wahana.h"
#include "point.h"
#include "state.h"

int main() {
    State S;
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
    // START("../../file/wahana.txt");
    // LoadWahana(&(S).data_wahana[1]);

    // printf("%d",&(S).data_wahana[1]);

    // // tampilkan hasil wahana yang di-input untuk testing
    // PrintKata((S).data_wahana[1].nama); printf("\n");
    // TulisPOINT((S).data_wahana[1].size); printf("\n");
    // for(i = 0; i < 5; i++){
    //     printf("%d",(S).data_wahana[1].bahan[i]); printf("\n");
    // }
    // PrintKata((S).data_wahana[1].deskripsi);

    // printf("%c", CC);

    // // testing map of address
    // Elmt(addressmap,0,0) = &(S).data_wahana[1];
    // printf("%d", Elmt(addressmap,0,0));

    // // tampilkan hasil wahana yang di-input untuk testing
    // // dengan mencoba menggunakan address wahana
    // PrintKata((*Elmt(addressmap,0,0)).nama); printf("\n");
    // TulisPOINT((*Elmt(addressmap,0,0)).size); printf("\n");
    // for(i = 0; i < 5; i++){
    //     printf("%d",(*Elmt(addressmap,0,0)).bahan[i]); printf("\n");
    // }
    // PrintKata((*Elmt(addressmap,0,0)).deskripsi);

    START("../../file/wahana.txt");
    for(i = 0; i < 7; i++){ 
        LoadWahana(&(S).data_wahana[i]);
        SetPohonWahana(&S, &(S).data_wahana[i]);
        ADV();
    }

    for(i = 0; i < 7; i++){ 
        PrintKata((S).data_wahana[i].nama);
        printf("\n");
        PrintTree((S).data_wahana[i].upgrade_tree,2);
    }
    printf("%c",CC);
    return 0;
}

/*
gcc -o wahana_driver wahana_driver.c wahana.o mesinkar.o mesinkata.o point.o treewahana.o listhistory.o material.o
*/