
#include "graph2.h"

void CreateEmptyGraph (Graph *G){
    First(*G) = Nil;
}


void MakeGraph(Graph *G, graph_peta*array_of_mapaddress){
    address result1;
    result1 = (address) malloc (sizeof(Node));
    if (result1 != Nil){
        Info(result1) = 0;
        (*array_of_mapaddress)[0]=result1;
    }    
    address result2;
    result2 = (address) malloc (sizeof(Node));
    if (result2 != Nil){
        Info(result2) = 1;
        (*array_of_mapaddress)[1]=result2;
    }    
    address result3;
    result3 = (address) malloc (sizeof(Node));
    if (result3 != Nil){
        Info(result3) = 2;
        (*array_of_mapaddress)[2]=result3;
    }    
    address result4;
    result4 = (address) malloc (sizeof(Node));
    if (result4 != Nil){
        Info(result4) = 3;
        (*array_of_mapaddress)[3]=result4;
    }
    if (result1!=Nil && result2!=Nil && result3!=Nil && result4!=Nil){

        First(*G)=result1;
        Right(result1)=result2;
        Left(result2)=result1;
        Down(result2)=result3;
        Up(result3)=result2;
        Left(result3)=result4;
        Right(result4)=result3;
        Up(result4)=result1;
        Down(result1)=result4;
    }

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