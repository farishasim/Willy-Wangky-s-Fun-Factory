#include "listhistory.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Manajemen Memori *** */
address_h AlokasiH (infohistory X) {
/* Mengirimkan address_h hasil alokasiH sebuah elemen */
/* Jika alokasiH berhasil, maka address_h tidak Nil, dan misalnya menghasilkan P, 
  maka Info(P) = X, Next(P) = Nil */
/* Jika alokasiH gagal, mengirimkan Nil */
    address_h P;

    P = (address_h) malloc (sizeof(ElmtListHistory));
    if (P) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DealokasiH (address_h P) {
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasiH/pengembalian address_h P */
    free(P);
}

/* *** Primitif-primitif yang harus direalisasikan *** */

/* Pemeriksaan Kondisi ListHistory */
int IsEmptyHistory(ListHistory L) {
/* Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong */
    return L == Nil;
}

int IsOneHistory(ListHistory L) {
/* Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong */
    if (IsEmptyHistory(L)) {
        return 0;
    } else if (Next(L) == Nil) {
        return 1;
    } else {
        return 0;
    }
}

/* *** Selektor *** */
infohistory FirstHistory (ListHistory L) {
/* Mengirimkan elemen pertama sebuah listHistory L yang tidak kosong */
    return Info(L);
}

ListHistory TailHistory(ListHistory L) {
/* Mengirimkan listHistory L tanpa elemen pertamanya, mungkin menjadi listHistory kosong */
    return Next(L);
}

/* *** Konstruktor *** */
ListHistory Konso(infohistory e, ListHistory L) {
/* Mengirimkan listHistory L dengan tambahan e sebagai elemen pertamanya. 
e dialokasiH terlebih dahulu. Jika alokasiH gagal, mengirimkan L. */
    address_h P;

    P = AlokasiH(e);
    if (P) {
        Next(P) = L;
        L = P;
    }
    return L;
}

ListHistory KonsB(ListHistory L, infohistory e) {
/* Mengirimkan listHistory L dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasiH terlebih dahulu */
/* Jika alokasiH e gagal, mengirimkan L */ 
    if (IsEmptyHistory(L)) {
        address_h P;
        P = AlokasiH(e);
        L = P;
        return L;
    } else {
        Next(L) = KonsB(Next(L),e);
        return L;
    }
}

/* *** Operasi Lain *** */
ListHistory Copy (ListHistory L) {
/* Mengirimkan salinan listHistory L (menjadi listHistory baru) */
/* Jika ada alokasiH gagal, mengirimkan L */ 
    if (IsEmptyHistory(L)) {
        return Nil;
    } else {
        return Konso(Info(L),Copy(Next(L)));
    } 
}

void MCopy (ListHistory Lin, ListHistory *Lout) {
/* I.S. Lin terdefinisi */
/* F.S. Lout berisi salinan dari Lin */
/* Proses : menyalin Lin ke Lout */
    *Lout = Copy(Lin);
}

ListHistory Concat (ListHistory L1, ListHistory L2) {
/* Mengirimkan salinan hasil konkatenasi listHistory L1 dan L2 (menjadi listHistory baru) */
/* Jika ada alokasiH gagal, menghasilkan Nil */
    address_h newP,P,Prec;
    ListHistory newL;
    boolean gagal;

    newL = Nil;
    gagal = false;

    P = L1; 
    while ((P != Nil) && (!gagal)) {
        newP = AlokasiH(Info(P));
        if (newP) {
            if (IsEmptyHistory(newL)) {
                newL = newP;
            } else {
                Next(Prec) = newP;
            } 
        } else {
            gagal = true;
        }
        Prec = newP;
        P = Next(P);
    }

    P = L2;
    while ((P != Nil) && (!gagal)) {
        newP = AlokasiH(Info(P));
        if (newP) {
            if (IsEmptyHistory(newL)) {
                newL = newP;
            } else {
                Next(Prec) = newP;
            } 
        } else {
            gagal = true;
        }
        Prec = newP;
        P = Next(P);
    }

    if (gagal) {
        newL = Nil;
    }

    return newL;
}

void MConcat (ListHistory L1, ListHistory L2, ListHistory *LHsl) {
/* I.S. L1, L2 terdefinisi */
/* F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin" */
/* Proses : Menghasilkan salinan hasil konkatenasi listHistory L1 dan L2 */
    *LHsl = Concat(L1,L2);
}

void PrintListHistory (ListHistory L) {
/* I.S. L terdefinisi. */
/* F.S. Setiap elemen listHistory dicetak. */
    if (!IsEmptyHistory(L)) {
        //printf("%d\n", Info(L)); // didn't work on linux
        printf("%p\n", Info(L));
        PrintListHistory(Next(L));
    }
}

int NbElmtListHistory (ListHistory L) {
/* Mengirimkan banyaknya elemen listHistory L, Nol jika L kosong */
    if (IsEmptyHistory(L)) {
        return 0;
    } else {
        return 1 + NbElmtListHistory(Next(L));
    }
}

boolean Search (ListHistory L, infohistory X) {
/* Mengirim true jika X adalah anggota listHistory, false jika tidak */
    if (IsOneHistory(L)) {
        return Info(L) == X;
    } else if (Info(L) == X) {
        return true;
    } else {
        return Search(Next(L),X);
    }
}
