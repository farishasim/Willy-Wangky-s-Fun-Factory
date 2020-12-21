#ifndef graph2_H
#define graph2_H

#include "../map/map.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct tNodeGraph *address_g;
typedef struct tNodeGraph {
int info;
address_g up;
address_g down;
address_g right;
address_g left;
} NodeGraph;
/* Definisi Graph: */
/* Graph kosong: First(G) = Nil */
typedef struct {
address_g First;
} Graph;
/* Selektor */

/*
info(first(graph)) = 1
[0] -- [1]
 |      |
 |      |
[2] -- [3]

peta[4]
[peta[0],peta[1],peta[2],peta[3]]
petaadrress[4]

petaaddress[4]
[petaaddress[0],...]

/* &W = 8
MAP                     MATRIK ADDress -2 
# * * * * * *             0 0 0 0 0 0
# * O * W W *             0 -2 0 8 8 0
# * * * W W *             0 0 0 8 8 0
# * * * * * *             0 0 0 0 0 0
######V######             -2 -2 -3 -2 -2
*/

// kalo address gerbang atas kiri kanan bawah bakal beda kan?
// cth gerbang bawah -3 kanan -4 ?
// itu bebas sih kalo mau sama atau beda

//kalo misal petaaddress[0] ntar nge return Map 0 (kiri atas)? atau address dari Map 0?

// sebenernya intinya kalo matriks address ini fungsinya buat ngebantu biar tau 
// ada wahana apa di titik tertentu
// tapi kalo ternyata bisa dipake buat ngebantu buat yg lain juga, 
// kyk gerbang dll boleh2 aja

// #define First(P) ((P).First) // ada pada boolean.h
// #define Info(P) (P)->info  // ada pada boolean.h
#define Right(P) (P)->right
#define Left(P) (P)->left
#define Up(P) (P)->up
#define Down(P) (P)->down

//typedef address_g graph_peta[4]; 

void CreateEmptyGraph (Graph *G);
/*Create graph kosong First(G)=Nil*/



void MakeGraph(Graph *G);
/*mengembalikan graph jika alokasi map berhasil
M1 = map 1 pojok kiri atas
M2 = map 2 pojok kanan atas
M3 = map 3 pojok kanan bawah
M4 = map 4 pojok kiri bawah*/

/*Move map*/
void MoveMapLeft (Graph * G);

void MoveMapRight (Graph * G);

void MoveMapUp (Graph * G);

void MoveMapDown (Graph * G);
#endif