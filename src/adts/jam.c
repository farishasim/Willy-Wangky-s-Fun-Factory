/* File : jam.c */
/* Body ADT Jam */
#include <stdio.h>
#include "jam.h"
/* -----------konstruktor Jam--------- */
JAM MakeJAM(int H, int M)
/* Membentuk Jam dari H, M, S yg valid */
{ /* Kamus Lokal */
    JAM J1;
/* Algoritma */
    Hour(J1) = H;
    Minute(J1) = M;
    return J1;
}

/*------------validator Jam------------*/
boolean IsJAMValid(int H, int M)
/* Mengirim true jika H,M,S dapat membentuk Jam yang valid */
{ /* Kamus Lokal */
/* Algoritma */
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) );
}

/*------------Baca & Tulis jam-----------*/
void BacaJAM(JAM *J)
/* I.S. : J tak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam valid */
/* Proses : mengulang baca komponen H, M, S sehingga membentuk J yang valid */
{ /* Kamus Lokal */
    int H, M;
/* Algoritma */
    do {
    printf("Masukkan jam : ");scanf("%d",&H);
    printf("Masukkan menit : ");scanf("%d",&M);
    } while(!IsJAMValid(H,M));
    *J = MakeJAM(H,M);
}

void TulisJAM(JAM J)
/* I.S. : J sembarang*/
/* F.S. : J ditulis ke layar dengan format HH:MM:SS */
/* Proses : Menulis ke layar */
{ 
    if (J.HH < 10)
    {
        if (J.MM < 10)
        {
            printf("0%d.0%d\n", J.HH, J.MM);
        }

        else
        {
            printf("0%d.%d\n", J.HH, J.MM);
        }
    } 

    else
    {
        if (J.MM < 10)
        {
            printf("%d.0%d\n", J.HH, J.MM);
        }

        else
        {
            printf("%d.%d\n", J.HH, J.MM);
        }
    }
}

int JAMToMenit(JAM J)
/* Konversi Jam menjadi Menit */
{ /* Kamus Lokal */
/* Algoritma */
    return(60 * Hour(J) + Minute(J));
}

JAM MenitToJAM(int N)
/* Konversi Menit ke Jam */
{ /* Kamus Lokal */
    int sisa;
    JAM JOut;
/* Algoritma */
    N = N % 1440; // harus ditambah ini agar valid
    Hour(JOut) = N / 60;
    Minute(JOut) = N % 60;
    return JOut;
}

boolean JEQ (JAM J1, JAM J2){
    return(JAMToMenit(J1) == JAMToMenit(J2));}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2){
    return (JAMToMenit(J1) != JAMToMenit(J2));}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2){
    return (JAMToMenit(J1) < JAMToMenit(J2));}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2){
    return (JAMToMenit(J1) > JAMToMenit(J2));}
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextMenit (JAM J){
    return NextNMenit(J, 1);}
/* Mengirim 1 Menit setelah J dalam bentuk JAM */
JAM NextNMenit (JAM J, int N){
    return MenitToJAM(JAMToMenit(J) + (1L*N));}
/* Mengirim N Menit setelah J dalam bentuk JAM */
JAM PrevMenit (JAM J){
    return PrevNMenit(J, 1);}
/* Mengirim 1 Menit sebelum J dalam bentuk JAM */
JAM PrevNMenit (JAM J, int N){
    return MenitToJAM(JAMToMenit(J) - (N) + 1440);}
/* Mengirim N Menit sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
int abs_val(int y){
if (y<0){
return (y*-1);}
else{return y;}
}
int Durasi (JAM JAw, JAM JAkh){
    return(abs_val(JAMToMenit(JAkh)-JAMToMenit(JAw)-1440)%1440);}
/* Mengirim JAkh-JAw dlm Menit, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */

void TulisDurasi(long N)
{
    if (MenitToJAM(N).MM == 0 && MenitToJAM(N).HH != 0)
    {
        printf("%d hour(s)\n", MenitToJAM(N).HH);
    }

    else if (MenitToJAM(N).MM != 0 && MenitToJAM(N).HH != 0)
    {
        printf("%d hour(s) %d minute(s)\n", MenitToJAM(N).HH, MenitToJAM(N).MM);
    }

    else
    {
        printf("%d minute(s)\n", MenitToJAM(N).MM);
    }
}
