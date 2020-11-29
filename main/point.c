#include <stdio.h>
#include "point.h"
#include <math.h>
/**** Konstruktor POINT ****/
POINT MakePOINT (int x, int y)
/* Membentuk sebuah POINT dari x dan y dengan x sebagai absis dan y sebagai ordinat */
{ /* KAMUS */
    POINT P;
/* ALGORITMA */
    Absis(P) = x;
    Ordinat(P) = y;
    return P;
}

/**** Predikat ****/
boolean IsOrigin (POINT P)
/* Mengirimkan nilai benar jika P adalah titik origin yaitu titik <0,0> */
{ /* ALGORITMA */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

/**** Prosedur - Interaksi dengan I/O device, BACA/TULIS ****/
void BacaPOINT (POINT * P)
/* Membentuk P dari x dan y yang dibaca dari keyboard */
{ /* KAMUS */
    int x, y;
/* ALGORITMA */
    scanf("%d", &x);
    scanf("%d", &y);
    *P = MakePOINT(x,y);
}

    void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dg format "(X,Y)" */
{ /* ALGORITMA */
    printf("(%.2d,%.2d)", Absis(P), Ordinat(P));
}
/**** Fungsi/Operasi lain terhadap POINT ****/
    void Geser (POINT *P, int deltaX, int deltaY)
/* Menghasilkan POINT yang merupakan hasil penggeseran P */
/* sebesar dx arah sumbu x dan dy arah sumbu y */
{ /* ALGORITMA */
    MakePOINT(Absis(*P) +deltaX, Ordinat(*P) +deltaY);
}

boolean EQPOINT (POINT P1, POINT P2){return ((P1.X == P2.X) && (P1.Y == P2.Y));}
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
boolean NEQPOINT (POINT P1, POINT P2){return (!EQPOINT(P1,P2));}
/* Mengirimkan true jika P1 tidak sama dengan P2 */
boolean IsOnSbX (POINT P){return (P.Y == 0);}
/* Menghasilkan true jika P terletak Pada sumbu X */
boolean IsOnSbY (POINT P){return (P.X == 0);}
/* Menghasilkan true jika P terletak pada sumbu Y */

POINT NextX (POINT P){
    POINT next=P;
    next.X=P.X+1;
    return next;}
/* Mengirim salinan P dengan absis ditambah satu */
POINT NextY (POINT P){
    POINT next=P;
    next.Y=P.Y+1;
    return next;}
/* Mengirim salinan P dengan ordinat ditambah satu */
POINT PlusDelta (POINT P, int deltaX, int deltaY){
    POINT next=P;
    next.X=P.X+deltaX;
    next.Y=P.Y+deltaY;
    return next;}
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */