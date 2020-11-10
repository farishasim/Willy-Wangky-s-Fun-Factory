#include "wahana.h"

void LoadWahana(Wahana * W, Material list_material[5]){
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
        ((*W).bahan)[i].quantity = ConvertKata(CKata);
        CopyKata(list_material[i].nama, &((*W).bahan)[i].nama);
        ((*W).bahan)[i].harga = list_material[i].harga;      
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
    
}