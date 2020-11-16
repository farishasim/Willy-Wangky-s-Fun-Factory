#include "material.h"

void LoadMaterial(Material * mat) {
    int i,val;
    char separator = ',';

    ADVKATA(separator);
    CopyKata(CKata, &(*mat).nama);
    
    ADVKATA(separator);
    (*mat).harga = ConvertKata(CKata);
    (*mat).quantity = 0;
}

void WriteMaterial(Material mat){

}

void PrintMaterial(Material mat){
    PrintKata(mat.nama);
    printf(":%d,", mat.harga);
    printf("%d", mat.quantity);
}