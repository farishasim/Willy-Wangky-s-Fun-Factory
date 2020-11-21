
#include "graph.h"

void CreateEmptyGraph (Graph *G){
    First(*G) = Nil;
}

address AlokasiMap (Map M){
    address result;
    result = (address) malloc (sizeof(Node));
    if (result != Nil){
        Info(result) = M;
    }
    return result;
}
/*Alokasi map*/

Graph MakeGraph(Map M1,Map M2, Map M3, Map M4){
    Graph G ;
    CreateEmptyGraph(&G);
    address r1=AlokasiMap (M1);
    address r2=AlokasiMap (M2);
    address r3=AlokasiMap (M3);
    address r4=AlokasiMap (M4);
    if (r1!=Nil && r2!=Nil && r3!=Nil && r4!=Nil){
        First(G)=r1;
        Right(r1)=r2;
        Left(r2)=r1;
        Down(r2)=r3;
        Up(r3)=r2;
        Left(r3)=r4;
        Right(r4)=r3;
        Up(r4)=r1;
        Down(r1)=r4;
    }
    return G;
}
/*mengembalikan graph jika alokasi map berhasil
M1 = map 1 pojok kiri atas
M2 = map 2 pojok kanan atas
M3 = map 3 pojok kanan bawah
M4 = map 4 pojok kiri bawah*/


/*Move map*/
void MoveMapLeft (Graph G){
    First(G)=Left(First(G));
}

void MoveMapRight (Graph G){
    First(G)=Right(First(G));
}

void MoveMapUp (Graph G){
    First(G)=Up(First(G));
}
void MoveMapDown (Graph G){
    First(G)=Down(First(G));
}