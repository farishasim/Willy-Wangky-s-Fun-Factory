
#ifndef peta_H
#define peta_H

#include "../matriks/matriks.h"
#include "../point/point.h"

typedef MATRIKS Map;

/*
Misal NBrsEff = 15, NKolEff = 15

* * * * * * * * * * * * 
* (1,1)               *
*                     *
*                     *
*                     *
*                     *
*                     *
*                     *
*             (14,14) *
* * * * * * * * * * * * 

*/

void InitialMap(Map * M);
/* I.S. M sebuah map berisi karakter sembarang */
/* F.S. M sebuah map taman wahana kosong hanya berisi office */
/* kosong artinya belum ada satu pun wahana */

void SetWahana(Map * M, POINT P, POINT Size);
/* I.S. M sebuah map yang berisi n buah wahana, n mungkin nol, dan P adalah sebuah Point yang valid*/
/* F.S. M sebuah map yang berisi n+1 buah wahana, dengan wahana baru terletak pada koordinat P*/

void RemoveWahana(Map * M, POINT P, POINT Size);

boolean IsWahana(Map M, POINT P);
// menhasilkan true jika map pada posisi P adalah 'W'

void SetOffice(Map * M, POINT P);

void SetAntrian(Map * M, POINT P);

void SetPlayer(Map * M, POINT P);
#endif
