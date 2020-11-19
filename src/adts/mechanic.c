#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//********* Fungsi-Fungsi untuk command *************//
void Repair(State * S) {
// I.S. user memberi command untuk repair
/* F.S. jika di sebelah kanan user terdapat wahana, 
        dan jika wahana tersebut rusak, dan jika uang user mencukupi, 
        wahana tersebut akan mulai reparation*/
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
/* I.S. user memberi command untuk melihat detail wahana*/
/* F.S. jika di sebelah kanan user terdapat wahana, 
        akan ditampilkan detail dari wahana tersebut
        dan waktu akan bertambah sebanyak 2 menit (opsional)*/
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


void OFFice(State * S) {
/* I.S. user memberi command untuk mengakses office */
/* F.S. jika user berada pada posisi office, akan ditampilkan antarmuka office
        selama di dalam office, user dapat memberi command Details, Report, Exit
        user akan terus berada di office hingga memberi command Exit*/
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
                printDetail(*ListWahana(*S)[choice_w]);
                timeFlow(S,2); // melihat detail membutuhkan waktu 2 menit.
            } else {
                printf("invalid");
            }

        } else if (choice == "Report") {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (choice_w >= 0 && choice_w < (*S).NWahana) {
                printReport(*ListWahana(*S)[choice_w]);
                timeFlow(S,2); // melihat report membutuhkan waktu 2 menit.
            } else {
                printf("invalid");
            }

        } else if (choice == "Exit") {
            exit = true;

        } else {
            printf("Invalid Command!");
        
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
        PrintKata(((*ListWahana(*S)[i])).nama);
        printf("\n");
    }
}



void incrementTime(State * S) {
/* I.S. Sembarang */
/* F.S. Time(S) akan bertambah satu menit, dan semua proses lain akan dijalankan paralel */
    int rand_num,count_play,i;
    address_c P,Prec;
    boolean quit,masuk_antrian;
    Time(*S) = NextMenit(Time(*S));

    // CEK SETIAP CUSTOMER
    P = First(DataCustomers(*S));
    while (P != Nil) {
        quit = false;
        Playtime(P) -= 1;
        if (Playtime(P) == 0) {
            if (Loc(P) != -1) {  //  customer berada pada suatu wahana
                Loc(P) = -1;
                // skema menghitung banyaknya wahana yang ingin dinaiki user
                count_play = 0;
                for (i=0; i<5; i++) {
                    if (Play(P,i) != -1) {
                        count_play++;
                    }
                }
                //  jika customer sudah tidak lagi memiliki daftar wahana 
                //  yang ingin dinaiki, atau jika antrian penuh,
                //  ia akan keluar
                if (count_play == 0 || IsFullQueue(Antrian(*S))) {  
                    quit = true;
                } else {
                    Playtime(P) = 10;
                    masuk_antrian = true;
                }
            } else {   //  customer berada pada antrian
                Kesabaran(P) -= 1;
                Prio(P) -= 1;
                if (Kesabaran(P) == 0) {  //  jika kesabaran customer habis, ia akan keluar.
                    quit = true;
                } else {
                    Playtime(P) = 10;
                }
            }
        }
        if (quit) {
            if (P == First(DataCustomers(*S))) {
                DelFirst(&DataCustomers(*S), &P);
                Dealokasi(&P);
                P = First(DataCustomers(*S));
            } else {
                DelAfter(&DataCustomers(*S), &P, Prec);
                Dealokasi(&P);
                P = Next(Prec);
            }
        } else if (masuk_antrian) {
            Enqueue(&Antrian(*S),P);
        }
        Prec = P;
        P = Next(P);  //  ke customer selanjutnya
    }

    //  PADA KONDISI INI, Prec menunjukkan customer terakhir
    rand_num = Randomize(0,6);
    if (rand_num < 1) {  //  16.7 % chance for generate customer
        P = generateCustomer(S);
        if (P) {  //  if generate customer succes
            InsertAfter(&DataCustomers(*S), P, Prec);  // masukkan customer ke data
            Enqueue(&Antrian(*S), P);   //  masukkan customer ke antrian
        }
    }

    //  CEK SETIAP WAHANA
    for(i=0; i<(*S).NWahana; i++) {
        if ((*ListWahana(*S)[i]).time_reparation != 0) {  // wahana sedang dalam perbaikan 
            (*ListWahana(*S)[i]).time_reparation -= 1;
            if ((*ListWahana(*S)[i]).time_reparation == 0) {  // jika wahana selesai diperbaiki
                (*ListWahana(*S)[i]).broke = false;
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


address_c generateCustomer(State * S) {
/* I.S. Sembarang */
/* F.S. didatangkan seorang customer baru. 
    jika antrian sudah penuh, maka customer tersebut pulang lagi
    jika tidak penuh, maka customer akan tercatat di data_customer
    dan customer akan masuk antrian*/
    address_c P;
    int i;

    P = Alokasi();
    if (!P) {  //  jika alokasi gagal, langsung keluar tidak melakukan apa-apa
        return P;
    }

    if (IsFullQueue(Antrian(*S))) {  //  Jika Antrian penuh, langsung keluar tidak melakukan apa-apa
        Dealokasi(&P);
        P = Nil;
        return P;
    }

    Prio(P) = 15;  //  priority default = 15 (opsional)
    Kesabaran(P) = 5;  //  kesabaran default = 5 (opsional)
    Loc(P) = -1;  //  langsung masuk antrian
    Playtime(P) = 10;  //  inisiasi waktu = 10(opsional)
    for(i = 0; i < 5; i++) {
        Play(P,i) = -1;
    }

    //  penentuan wahana yang ingin dinaiki customer, 
    //  lagi-lagi dengan RNG.
    RandomPlay(P);  

    return P;
}


int Randomize(int lower_bound, int upper_bound) {
// menghasilkan bilangan random antara lower_bound dan upper_bound
    srand(time(NULL));
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}


void RandomPlay(address_c P) {
// I.S. Sembarang
/* F.S. RNG for Play(P)*/
    int rand_num,i,nplay,j;
    boolean found;
    rand_num = Randomize(0,100);

    // 50 % chance 1 wahana, 20 % chance 2 wahana
    // 15 % chance 3 wahana, 10 % chance 4 wahana
    // 5 % chance 5 wahana (opsional)
    if (rand_num < 50) {
        nplay = 1;
    } else if (rand_num < 70) {
        nplay = 2;
    } else if (rand_num < 85) {
        nplay = 3;
    } else if (rand_num < 95) {
        nplay = 4;
    } else {
        nplay = 5;
    }

    i = 0;
    while (i < nplay) {
        rand_num = Randomize(0,5);
        found = false;
        j = 0;
        while (Play(P,j) != -1 && !found) {
            if (Play(P,j) = rand_num) {
                found = true;
            }
            j++;
        }
        if (!found){
            Play(P,j) = rand_num;
            i++;
        }
    }
}