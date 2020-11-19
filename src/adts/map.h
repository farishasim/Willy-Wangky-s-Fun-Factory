
#ifndef peta_H
#define peta_H

#include "matriks.h"
#include "point.h"

typedef MATRIKS Map;

void InitialMap(Map * M);
/* I.S. M sebuah map berisi karakter sembarang */
/* F.S. M sebuah map taman wahana kosong hanya berisi office */
/* kosong artinya belum ada satu pun wahana */

void SetWahana(Map * M, POINT P);
/* I.S. M sebuah map yang berisi n buah wahana, n mungkin nol, dan P adalah sebuah Point yang valid*/
/* F.S. M sebuah map yang berisi n+1 buah wahana, dengan wahana baru terletak pada koordinat P*/

boolean IsWahana(Map M, POINT P);
// menhasilkan true jika map pada posisi P adalah 'W'

void SetOffice(Map *S, POINT P);

void SetAntrian(Map * M, POINT P);

#endif
