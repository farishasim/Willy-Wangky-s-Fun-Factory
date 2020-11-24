#ifndef graph2_H
#define graph2_H

#include "map.h"
#include <stdlib.h>
#include <stdio.h>

#define Nil NULL
typedef struct tNode *address;
typedef struct tNode {
int info;
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

typedef address graph_peta[4]; 

void CreateEmptyGraph (Graph *G);
/*Create graph kosong First(G)=Nil*/



void MakeGraph(Graph *G, graph_peta*array_of_mapaddress);
/*mengembalikan graph jika alokasi map berhasil
M1 = map 1 pojok kiri atas
M2 = map 2 pojok kanan atas
M3 = map 3 pojok kanan bawah
M4 = map 4 pojok kiri bawah*/

/*Move map*/
void MoveMapLeft (Graph G);

void MoveMapRight (Graph G);

void MoveMapUp (Graph G);

void MoveMapDown (Graph G);
#endif