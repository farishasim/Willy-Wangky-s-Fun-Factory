#include <stdio.h>
#include "state.h"

void LoadWahana(Wahana * W){
    int i;
    int x,y;
    char separator = ',';
    
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

    ADVKATA(separator);
    (*W).durasi_repair = ConvertKata(CKata);
}

void SetPohonWahana(State * S, Wahana * W) {
    // I.S. setelah LoadWahana(W), CC = ID wahana
    char separator = ',';
    int ID_next_kiri;
    int ID_next_kanan;
    int ID_prev;
    BinTree parent;

    ADVKATA(separator);
    (*W).ID = ConvertKata(CKata);

    ADVKATA(separator);
    (*W).starter = ConvertKata(CKata);

    ADVKATA(separator);
    ID_next_kiri = ConvertKata(CKata);

    ADVKATA(separator);
    ID_next_kanan = ConvertKata(CKata);

    ADVKATA(separator);
    ID_prev = ConvertKata(CKata);

    if ((*W).starter) {
        (*W).upgrade_tree = AlokasiTree((*W).ID);
        if (ID_next_kiri != -1) {
            Left((*W).upgrade_tree) = AlokasiTree(ID_next_kiri);
            if (ID_next_kanan != -1) {    
                Right((*W).upgrade_tree) = AlokasiTree(ID_next_kanan);
            }   
        }
    } else {
        parent = GetWahana(*S,ID_prev).upgrade_tree;
        if (Info(Left(parent)) == (*W).ID) {  //  jika wahana merupakan anak kiri
            (*W).upgrade_tree = Left(parent);
        } else {             //    jika wahana merupakan anak kanan
            (*W).upgrade_tree = Right(parent);
        }
        if (ID_next_kiri != -1) {
            Left((*W).upgrade_tree) = AlokasiTree(ID_next_kiri);
            if (ID_next_kanan != -1) {    
                Right((*W).upgrade_tree) = AlokasiTree(ID_next_kanan);
            }   
        }
    }
}

void InitialAddressMap(Map_wahana * M, int NB, int NK) {
    // I.S. M sembarang, NB dan NK int > 0
    // F.S. akan dibuat M sebagai Map_wahana yang baru
    int i,j;
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;

    i=0;
    for(j=0; j<NK; j++) {
        Elmt(*M,i,j) = (address_w) -2;
    } i++;
    for(j=0; j<NK; j++) {
        Elmt(*M,i,j) = (address_w) -2;
    }
    for(i=2; i<NBrsEff(*M)-2; i++) {
        j=0; Elmt(*M,i,j) = (address_w) -2;
        j++; Elmt(*M,i,j) = (address_w) -2;
        for(j=2; j<NKolEff(*M)-2; j++) {
            Elmt(*M,i,j) = Nil;
        }
        Elmt(*M,i,j) = (address_w) -2;
        j++; Elmt(*M,i,j) = (address_w) -2;
    }
    for(j=0; j<NK; j++) {
        Elmt(*M,i,j) = (address_w) -2;
    } i++;
    for(j=0; j<NK; j++) {
        Elmt(*M,i,j) = (address_w) -2;
    }
}

void SetForbiddenAddress(Map_wahana * M, POINT loc) {
    int firstBrs,firstKol,lastBrs,lastKol,i,j;

    firstBrs = Absis(loc)-1;
    firstKol = Ordinat(loc)-1;
    lastBrs = firstBrs + 3;
    lastKol = firstKol + 3;

    for(i = firstBrs; i < lastBrs; i++) {
        for(j = firstKol; j < lastKol; j++) {
            Elmt(*M,i,j) = (address_w) -2;
        }
    }
}

void setAddressMap(Map_wahana * M, Wahana * W, POINT loc) {
    // I.S. loc adalah kordinat yang valid dan size valid
    // F.S. pada map of address, akan dimasukkan address dari wahana 
    //      yang terletak pada titik : loc, dengan ukuran wahana : size
    int firstBrs,firstKol,lastBrs,lastKol,i,j;
    POINT size = (*W).size;
    address_w address_wahana;
    address_wahana = W;

    firstBrs = Absis(loc);
    firstKol = Ordinat(loc);
    lastBrs = firstBrs + Absis(size) - 1;
    lastKol = firstKol + Ordinat(size) - 1;

    i = firstBrs-1;
    for(j = firstKol-1; j <= lastKol+1; j++) {
        Elmt(*M,i,j) = (address_w)-1;  //  sekeliling atas menjadi forbidden
    }
    for(i = firstBrs; i <= lastBrs; i++) {
        Elmt(*M,i,firstKol-1) = (address_w)-1;  //  sekeliling kiri menjadi forbidden
        for(j = firstKol; j <= lastKol; j++) {
            Elmt(*M,i,j) = address_wahana;
        }
        Elmt(*M,i,lastKol+1) = (address_w)-1;  //  sekeliling kanan menjadi forbidden
    }
    i = lastKol-1;
    for(j = firstKol-1; j <= lastKol+1; j++) {
        Elmt(*M,i,j) = (address_w)-1;  //  sekeliling bawah menjadi forbidden
    }
}

void TulisMATRIKSW (Map_wahana M){
    int i,j;
    for(i=0; i < NBrsEff(M); i++){
        for(j=0; j< NKolEff(M); j++) {
            printf("%d",Elmt(M,i,j));
        } 
        printf("\n");
    }
}

Wahana getWahanaAt(Map_wahana * M, POINT P) {
    // prekondisi : P  point yang valid
    // return value : sebuah wahana yang terletak pada P.

    return *Elmt(*M,Absis(P),Ordinat(P));
}

void printDetail(Wahana * W) {
    // menampilkan detail wahana ke layar.
    printf("// Melihat detail wahana //");

    printf("\nNama : ");
    PrintKata((*W).nama);
    
    printf("\nLokasi : ");
    TulisPOINT((*W).position);
    
    printf("\nUpgrade(s) : []");  // untuk sementara kosong dulu

    printf("\nHistory : ");   // untuk sementara kosong dulu
    
    printf("\nStatus : ");
    if ((*W).broke) {
        printf("Tidak Berfungsi\n");
    } else {
        printf("berfungsi\n");
    }
}


void printReport(Wahana (*W)){
    //menampilkan report wahana ke layar.
    printf("Total Pemakaian : %d\n", (*W).count_used);
    printf("Pemakaian hari ini : %d\n", (*W).count_used1);

    printf("Total Pemasukkan : %d\n", (*W).income);
    printf("Pemasukkan hari ini: %d\n", (*W).income1);
}

void printHistory1(ListHistory L){
    if (!IsEmptyHistory(L)) {
        PrintKata((*Info(L)).nama);
        if (Next(L)) {
            printf(" -> ");
            printHistory1(Next(L));
        }
    }
}

void printHistory(Wahana * W) {
    ListHistory L;
    address_h P;

    L = (*W).history;
    
    printHistory1(L);
}

void printNextGrade(Wahana * W) {
    // menampilkan Upgrade = []
    // Kamus
    BinTree PohonUpgrade;
    // Algoritma
    PohonUpgrade = (*W).upgrade_tree;
}

void printNextGrade1(BinTree P, int ID) {
    // proses rekurens untuk printNextGrade
    if (Akar(P) == ID) {

    }
}

boolean IsWahanaFull(Wahana * W){
    // true jika suatu wahana full
    // definisi full yaitu banyak orang == kapasitas
    return (*W).banyak_orang == (*W).kapasitas;
}

boolean IsPosisiEmpty(Map_wahana * M, POINT P) {
    // true jika wahana bisa dibangun di titik P
    boolean build;
    int i,j;

    build = true;
    i = 0;
    while(i < NBrsEff(*M) && build) {
        j = 0;
        while (j < NKolEff(*M) && build){
            if (Elmt(*M,i,j) != Nil) {
                build = false;
            }
            j++;
        }        
        i++;
    }

    return build;
}

int idxWahanaEQbyID(int ID, Wahana W[10])
{
    int idx = 0;
    while (ID != W[idx].ID && idx < 10)
    {
        ++idx;
    }
    return idx;
}

/* &W = 8
MAP                     MATRIK ADDress -2
# * * * * * *             0 0 0 0 0 0
# * O * W W *             0 -2 0 8 8 0
# * * * W W *             0 0 0 8 8 0
# * * * * * *             0 0 0 0 0 0
*/

// *Matriks_Address[4][2]


// wahana yang dibangun 0, 1, 4

/*
i traversal
if DataWahana[i].starter then
[0,1,4]

1. DataWahana[0].nama
2. DataWahana[1].nama
3. DataWahana[4].nama

2

&DataWahana[1]

uwucoaster -> engi descent

*/