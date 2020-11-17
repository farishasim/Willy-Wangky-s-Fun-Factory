#include "state.h"
#include <stdio.h>

void Repair(State * S) {
    POINT posisi_wahana;
    address_w address_wahana_kanan;

    posisi_wahana = NextX(Position(*S));
    
    if (!IsWahana(Peta(*S),posisi_wahana)) {
        printf("Tidak ada wahana apapun di samping kanan");
        return;
    }

    address_wahana_kanan = (*S).map_address[Absis(posisi_wahana)][Ordinat(posisi_wahana)];

    if (!(*address_wahana_kanan).broke) {
        printf("wahana di samping kanan tidak rusak!");
        return;
    } 

    if (Money(*S) < (*address_wahana_kanan).harga_repair) {
        printf("Uang tidak cukup!");
        return;
    }

    (*address_wahana_kanan).time_reparation = (*address_wahana_kanan).durasi_repair;
    Money(*S) -= (*address_wahana_kanan).harga_repair;
    timeFlow(S,5);  //  waktu yang diperlukan untuk memulai perbaikan wahana adalah 5 menit (opsional)
    printf("// Memperbaiki ");
    PrintKata((*address_wahana_kanan).nama);

}


void Detail(State * S) {
    POINT posisi_wahana;
    Wahana wahana_kanan;

    posisi_wahana = NextX(Position(*S));
    
    if (!IsWahana(Peta(*S),posisi_wahana)) {
        printf("Tidak ada wahana apapun di samping kanan");
        return;
    }

    wahana_kanan = getWahanaAt((*S).map_address, posisi_wahana);

    printDetail(wahana_kanan);
    timeFlow(S,2); // melihat detail membutuhkan waktu 2 menit. (opsional)
}


void Office(State * S) {
    POINT office;
    char choice[8];
    int choice_w;
    boolean exit;

    office = MakePOINT(Absis((*S).office),Ordinat((*S).office));

    if (NEQPOINT((*S).position, office)) {
        printf("// Anda tidak sedang berada di Office! //");
        return;
    }

    printf("// Memasuki office mode //");

    exit = false;

    do {
        printf("Masukkan perintah (Details / Report / Exit):");
        fgets(&choice, 8, stdin);
        if (choice == "Details") {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (choice_w >= 0 && choice_w < (*S).NWahana) {
                printDetail((*S).listWahana[choice_w]);
                timeFlow(S,2); // melihat detail membutuhkan waktu 2 menit.
            } else {
                printf("invalid");
            }

        } else if (choice == "Report") {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (choice_w >= 0 && choice_w < (*S).NWahana) {
                printReport((*S).listWahana[choice_w]);
                timeFlow(S,2); // melihat report membutuhkan waktu 2 menit.
            } else {
                printf("invalid");
            }

        } else if (choice == "Exit") {
            exit = true;

        } else {
            printf("Command tidak tersedia");
        
        }
    } while (!exit);

    printf("Anda keluar dari Office.");
}   


//********** Fungsi-fungsi untuk Support ************//
void printListWahana(State * S) {
/* I.S. Sembarang */
/* F.S. Menampilkan semua nama wahana yang dimiliki pemain*/
    int i;
    
    printf("Daftar Wahana yang dimiliki : \n");
    
    for(i = 0; i < ((*S).NWahana); i++) {
        printf("%d. ", i+1);
        PrintKata((*S).listWahana[i].nama);
        printf("\n");
    }
}



void incrementTime(State * S) {
/* I.S. Sembarang */
/* F.S. Time(S) akan bertambah satu menit, dan semua proses lain akan dijalankan paralel */
    int i,count_play,j;
    Customer temp;
    boolean quit;
    Time(*S) = NextMenit(Time(*S));

    // cek setiap customer
    for(i=0 ; i<NBElmtQueue(Antrian(*S)); i++) {
        Dequeue(&Antrian(*S),&temp);
        quit = false;
        temp.time -= 1;
        if (temp.time == 0) {
            if (temp.loc != -1) {  //  customer berada pada suatu wahana
                temp.loc = -1;
                // skema menghitung banyaknya wahana yang ingin dinaiki user
                count_play = 0;
                for (j=0; j<5; j++) {
                    if (temp.play[j] != -1) {
                        count_play++;
                    }
                }
                if (count_play == 0) {  //  jika customer sudah tidak lagi memiliki daftar wahana yang ingin dinaiki, ia akan keluar
                    quit = true;
                } else {
                    temp.time = 10;
                }
            } else {   //  customer berada pada antrian
                temp.kesabaran -= 1;
                temp.prio -= 1;
                if (temp.kesabaran == 0) {  //  jika kesabaran customer habis, ia akan keluar.
                    quit = true;
                }
            }
        }
        if (!quit) {
            Enqueue(&Antrian(*S),temp);
        }
    }

    //  cek setiap wahana
    for(i=0; i<(*S).NWahana; i++) {
        if ((*S).listWahana[i].time_reparation != 0) {  // wahana sedang dalam perbaikan 
            (*S).listWahana[i].time_reparation -= 1;
            if ((*S).listWahana[i].time_reparation == 0) {  // jika wahana selesai diperbaiki
                (*S).listWahana[i].broke = false;
            }
        }
    }
}


void timeFlow(State * S, int N) {
    // I.S. Sembarang
    // F.S. Time(S) akan bertambah sebanyak N menit
    int i;
    for(i=0; i<N; i++) {
        incrementTime(S);
    }
}