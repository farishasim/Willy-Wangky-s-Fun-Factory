
#include <stdio.h>
#include "boolean.h"
#include "matriks.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    M->NBrsEff=NB;
    M->NKolEff=NK;
    int i,j;
    for (i=0;i<=NB-1;i++){
        for (j=0;j<=NB-1;j++){
            M->Mem[i][j]='0';
        }
    }
}

boolean IsIdxValid (int i, int j){
    if (i<=BrsMax && i>=0 && j<=KolMax && j>=0) {
        return true;
    }
    else {
        return false;
    }
}
indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
    return M.NBrsEff-1;
}

indeks GetLastIdxKol (MATRIKS M){
    return M.NKolEff-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    if (i<=M.NBrsEff-1 && i>=0 && j<=M.NKolEff-1 && j>=0) {
        return true;
    }
    else {
        return false;
    }
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
    return Elmt(M,i,i);
}
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
    MakeMATRIKS(MIn.NBrsEff,MIn.NKolEff,MHsl);
    int i,j;
    for (i=0;i<=GetLastIdxBrs(MIn);i++){
        for (j=0;j<=GetLastIdxBrs(MIn);j++){
            MHsl->Mem[i][j]=MIn.Mem[i][j];
        }
    }
}

void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    MakeMATRIKS(NB,NK,M);
    int i,j;
    for (i=0;i<=GetLastIdxBrs(*M);i++){
        for (j=0;j<=GetLastIdxBrs(*M);j++){
            scanf("%d", &(M->Mem[i][j]));
        }
    }
}

void TulisMATRIKS (MATRIKS M){
    
}
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS MHasil;
    MakeMATRIKS (M1.NBrsEff,M1.NKolEff,&MHasil);
    int i,j;
    for (i=0;i<=GetLastIdxBrs(MHasil);i++){
        for (j=0;j<=GetLastIdxBrs(MHasil);j++){
           MHasil.Mem[i][j]=M1.Mem[i][j]+M2.Mem[i][j];
        }
    }
    return MHasil;
}

MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
    MATRIKS MHasil;
    MakeMATRIKS (M1.NBrsEff,M1.NKolEff,&MHasil);
    int i,j;
    for (i=0;i<=GetLastIdxBrs(MHasil);i++){
        for (j=0;j<=GetLastIdxBrs(MHasil);j++){
           MHasil.Mem[i][j]=M1.Mem[i][j]-M2.Mem[i][j];
        }
    }
    return MHasil;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
    return M1;
}
MATRIKS KaliKons (MATRIKS M, ElType X){
    MATRIKS MHasil;
    MakeMATRIKS (M.NBrsEff,M.NKolEff,&MHasil);
    int i,j;
    for (i=0;i<=GetLastIdxBrs(MHasil);i++){
        for (j=0;j<=GetLastIdxBrs(MHasil);j++){
           MHasil.Mem[i][j]=X*M.Mem[i][j];
        }
    }
    return MHasil;
}
void PKaliKons (MATRIKS * M, ElType K){
    MATRIKS MHasil = KaliKons(*M,K);
    *M = MHasil;
}
boolean EQ (MATRIKS M1, MATRIKS M2){
    boolean sama=true;
    int i=0,j=0;
    while (i<=GetLastIdxBrs(M1) && sama) {
        while (j<=GetLastIdxKol(M1) && sama)
        {
            if (M1.Mem[i][j]!=M2.Mem[i][j]){
                sama=false;
            }
            j++;
        }
        i++;
    }
    return sama;
}

boolean NEQ (MATRIKS M1, MATRIKS M2){
    return !EQ(M1,M2);
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
    if (M1.NBrsEff==M2.NBrsEff && M1.NKolEff==M2.NKolEff){
        return true;
    }
    else {
        return false;
    }
}
int NBElmtMatriks (MATRIKS M){
    return (M.NBrsEff*M.NKolEff);
}

