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