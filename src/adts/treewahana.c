
#include "treewahana.h"


address AlokasiTree (IdWahana X){
    address result;
    result = (address) malloc (sizeof(NodeTree));
    if (result != Nil){
        Akar(result) = X;
        Left(result) = Nil;
        Right(result) = Nil;
    }
    return result;
}

void DealokasiTree (address P){
    free(P);
}

//Konstruktor
BinTree Tree (IdWahana X , BinTree L ,BinTree R ){
    address P;
    P= AlokasiTree(X);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}
/*{ Menghasilkan sebuah pohon biner dari X, L, dan R, jika alokasi
berhasil }
{ Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (IdWahana X, BinTree L , BinTree R ,BinTree *P ){
    *P = AlokasiTree(X);
    if (*P != Nil) {
        Left(*P) = L;
        Right(*P) = R;
    }
}
/*{ I.S. Sembarang }
{ F.S. Menghasilkan sebuah pohon P }
{ Menghasilkan sebuah pohon biner P dari X, L, dan R, jika alokasi berhasil }
{ Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal }*/


IdWahana GetAkar (BinTree T){
    return Akar(T);
}
// Mengirimkan nilai Akar pohon biner P 

BinTree GetLeft (BinTree T){
    return Left(T);
}
// Mengirimkan Anak Kiri pohon biner P 

BinTree GetRight (BinTree T){
    return Right(T);
}
//Mengirimkan Anak Kanan pohon biner P 

boolean IsTreeEmpty (BinTree T){
    return  (T == Nil);
}
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil }
 Menghasilkan pohon kosong (Nil) jika alokasi gagal */


boolean IsOneElmt (BinTree T){
    if (!IsTreeEmpty(T)){
        return ((Left(T) == Nil) && (Right(T) == Nil));
    }
    else{
        return false;
    }
}
/*{ Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1 elemen }
*/

boolean IsUnerLeft (BinTree T){
    return (Right(T) == Nil) && (Left(T) != Nil);
}
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerleft:
hanya mempunyai subpohon kiri }*/

boolean IsUnerRight (BinTree T){    
    return (Left(T) == Nil) && (Right(T) != Nil) ;
}
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon unerright:
hanya mempunyai subpohon kanan }*/

boolean IsBiner (BinTree T){
    return (Left(T) != Nil) && (Right(T) != Nil);
}
/*{ Mengirimkan true jika pohon biner tidak kosong, P adalah pohon biner:
mempunyai subpohon kiri dan subpohon kanan }*/


boolean SearchTree (BinTree T, IdWahana X){
    if (IsOneElmt(T)){
        if (Akar(T)==X){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (IsUnerLeft(T)){
            return SearchTree(Left(T),X);
        }
        else if (IsUnerRight(T)){
            return SearchTree(Right(T),X);
        }
        else if (IsBiner(T)){
            return (SearchTree(Left(T),X) || SearchTree(Right(T),X));
        }
    }
}
/*{ Mengirimkan true jika ada nodeTreeNodeTree dari P yang bernilai X }
*/

void PrintTree(BinTree P, int h) {
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
    PrintTree1(P,h,h);
}

void PrintTree1(BinTree P, int h, int acch) {
// printtree dengan akumulator
    int i;
    if (!IsTreeEmpty(P)) {
        printf("%d\n",Akar(P));
        if (Left(P) != Nil) {
            for(i = 0; i < acch; i++) {
                printf(" ");
            }
            PrintTree1(Left(P),h,acch+h);
        }
        if (Right(P) != Nil) {
            for(i = 0; i < acch; i++) {
                printf(" ");
            }
            PrintTree1(Right(P),h,acch+h);
        }
    }
}

void AddDaun (BinTree T ,IdWahana X, IdWahana Y,boolean Kiri){
    if (IsOneElmt(T) && Akar(T)==X){
        if (Kiri){
            address P = AlokasiTree(Y);
            Left(T)=P;
        }
        else {
            address P = AlokasiTree(Y);
            Right(T)=P;
        }
    }
    else {
        if (IsUnerLeft(T)){
            return AddDaun(Left(T),X,Y,Kiri);
        }
        else if (IsUnerRight(T)){
            return AddDaun(Right(T),X,Y,Kiri);
        }
        else if (IsBiner(T)){
            if (SearchTree(Left(T),X)){
                AddDaun(Left(T),X,Y,Kiri);
            }
            else if (SearchTree(Right(T),X)) {
                AddDaun(Right(T),X,Y,Kiri);
            }
        }
    }

}
/*{ I.S. P tidak kosong, X adalah daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika
Kiri), atau sebagai anak Kanan X (jika not Kiri). Jika ada lebih
dari satu daun bernilai X, Y ditambahkan pada daun paling kiri. }*/

void DelDaun (BinTree P ,IdWahana X ){
    BinTree temp,del;
    if (IsOneElmt(P) && Akar(P)==X){
        P=Nil;
    }
    else {
        if (IsOneElmt(Left(P))){
            if (Akar(Left(P))==X){
                del=(Left(P));
                DealokasiTree(del);
                Left(P)=Nil;
            }
        }
        else {
            temp = Left(P);
            DelDaun(temp,X);
            Left(P)=temp;
        }
        if (IsOneElmt(Right(P))){
            if (Akar(Right(P))==X){
                del=(Right(P));
                DealokasiTree(del);
                Right(P)=Nil;
            }
        }
        else {
            temp = Right(P);
            DelDaun(temp,X);
            Right(P)=temp;
        }
    }
}
/*{ I.S. P tidak kosong, minimum 1 daun bernilai X }
{ F.S. Semua daun yang bernilai X dihapus dari P }*/


//********   Fungsi-fungsi lain terkait Tree   *******//
IdWahana SearchSubPohon(BinTree T, IdWahana X, boolean Kiri) {
    /* Mengembalikan akar subpohon dari pohon yang memiliki Akar = X */
    /* jika Kiri=true, Mengembalikan akar subpohon kiri */
    /* jika Kiri=false*, Mengembalikan akar subpohon kanan */
    /* prekondisi : jika Kiri true maka pohon harus memiliki sub-pohon kiri
                    jika Kiri false maka pohon harus memiliki subpohon kanan
                    setiap akar pada pohon bernilai unik. dan X ada pada pohon*/
    if (Akar(T)==X){
        if (Kiri){
            return Akar(Left(T));
        }
        else {
            return Akar(Right(T));
        }
    } else {
        if (SearchTree(Left(T),X)) {
            return SearchSubPohon(Left(T),X,Kiri);
        } else {
            return SearchSubPohon(Right(T),X,Kiri);
        }
    }
}
