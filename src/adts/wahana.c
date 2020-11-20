#include "wahana.h"
#include <stdio.h>

void LoadWahana(Wahana * W){
    int i;
    int x,y;
    char separator = ',';

    ADVKATA(separator);
    CopyKata(CKata, &(*W).nama);
    
    (*W).position = MakePOINT(-1,-1);

    ADVKATA(separator);
    x = ConvertKata(CKata);
    ADVKATA(separator);
    y = ConvertKata(CKata);
    
    (*W).size = MakePOINT(x,y);

    ADVKATA(separator);
    (*W).harga = ConvertKata(CKata);
    
    ADVKATA(separator);
    (*W).kapasitas = ConvertKata(CKata);
    
    ADVKATA(separator);
    (*W).durasi = ConvertKata(CKata);
    
    for(i = 0; i < 5; i++) {
        ADVKATA(separator);
        ((*W).bahan)[i] = ConvertKata(CKata);      
    }

    ADVKATA(separator);
    (*W).uang = ConvertKata(CKata);

    ADVKATA(separator);
    CopyKata(CKata, &(*W).deskripsi);
}


void setAddressMap(map_wahana * map_of_address, address_w address_wahana, POINT loc, POINT size) {
    // I.S. loc adalah kordinat yang valid dan size valid
    // F.S. pada map of address, akan dimasukkan address dari wahana 
    //      yang terletak pada titik : loc, dengan ukuran wahana : size
    int firstBrs,firstKol,lastBrs,lastKol,i,j;
    firstBrs = Absis(loc);
    firstKol = Ordinat(loc);
    lastBrs = firstBrs + Absis(size) - 1;
    lastKol = firstKol + Ordinat(size) - 1;

    for(i = firstBrs; i <= lastBrs; i++) {
        for(j = firstKol; j <= lastKol; j++) {
            (*map_of_address)[i][j] = address_wahana;
        }
    }
}

Wahana getWahanaAt(map_wahana map_of_address, POINT P) {
    // prekondisi : P  point yang valid
    // return value : sebuah wahana yang terletak pada P.

    return *(map_of_address[Absis(P)][Ordinat(P)]);
}

void printDetail(Wahana W) {
    // menampilkan detail wahana ke layar.
    printf("// Melihat detail wahana //");

    printf("\nNama : ");
    PrintKata(W.nama);
    
    printf("\nLokasi : ");
    TulisPOINT(W.position);
    
    printf("\nUpgrade(s) : []");  // untuk sementara kosong dulu

    printf("\nHistory : ");   // untuk sementara kosong dulu
    
    printf("\nStatus : ");
    if (W.broke) {
        printf("Tidak Berfungsi\n");
    } else {
        printf("berfungsi\n");
    }
}


void printReport(Wahana W){
    //menampilkan report wahana ke layar.
    printf("Total Pemakaian : %d\n", W.count_used);
    printf("Pemakaian hari ini : %d\n", W.count_used1);

    printf("Total Pemasukkan : %d\n", W.income);
    printf("Pemasukkan hari ini: %d\n", W.income1);
}


/* &W = 8
MAP                     MATRIK ADDress
* * * * * *             0 0 0 0 0 0
* * * W W *             0 0 0 8 8 0
* * * W W *             0 0 0 8 8 0
* * * * * *             0 0 0 0 0 0
*/

// *Matriks_Address[4][2]