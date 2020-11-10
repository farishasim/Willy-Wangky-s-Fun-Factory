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

    (*address_wahana_kanan).broke = false;
    Money(*S) -= (*address_wahana_kanan).harga_repair;
    Time(*S) = NextNMenit(Time(*S), (*address_wahana_kanan).durasi_repair);
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
    Time(*S) = NextNMenit(Time(*S), 2); // melihat detail membutuhkan waktu 2 menit.
}


void Office(State * S) {
    // posisi office adalah di (5,5)
    POINT office;
    char choice[8];
    int choice_w;
    boolean exit;

    office = MakePOINT(5,5);

    if (NEQPOINT((*S).position, office)) {
        printf("Anda tidak sedang berada di Office!");
    }

    printf("Anda sedang membuka Office.");

    do {
        fgets(&choice, 8, stdin);
        if (choice == "Details") {
            printListWahana(*S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            printDetail((*S).listWahana[choice_w]);
            Time(*S) = NextNMenit(Time(*S), 2); // melihat detail membutuhkan waktu 2 menit.
        
        } else if (choice == "Report") {
            printListWahana(*S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            printReport((*S).listWahana[choice_w]);
            Time(*S) = NextNMenit(Time(*S), 2); // melihat report membutuhkan waktu 2 menit.

        } else if (choice == "Exit") {
            exit = true;

        } else {
            printf("Command tidak tersedia");
        
        }
    } while (!exit);

    printf("Anda keluar dari Office.");
}   