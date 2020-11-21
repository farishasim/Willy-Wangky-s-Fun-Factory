#ifndef graph_H
#define graph_H

#include "map.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL
typedef struct tNode *address;
typedef struct tNode {
Map info;
address up;
address down;
address right;
address left;
} Node;
/* Definisi Graph: */
/* Graph kosong: First(G) = Nil */
typedef struct {
address First;
} Graph;
/* Selektor */
#define Info(P) (P)->info
#define Right(P) (P)->right
#define Left(P) (P)->left
#define Up(P) (P)->up
#define Down(P) (P)->down
#define First(G) ((G).First)

void CreateEmptyGraph (Graph *G);
/*Create graph kosong First(G)=Nil*/

address AlokasiMap (Map M);
/*Alokasi map*/

Graph MakeGraph(Map M1,Map M2, Map M3, Map M4);
/*mengembalikan graph jika alokasi map berhasil
M1 = map 1 pojok kiri atas
M2 = map 2 pojok kanan atas
M3 = map 3 pojok kanan bawah
M4 = map 4 pojok kiri bawah*/

/*Move map*/
void MoveMapLeft (address *current_map);

void MoveMapRight (address *current_map);

void MoveMapUp (address *current_map);

void MoveMapDown (address *current_map);
#endif