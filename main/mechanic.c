#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mechanic.h"


//********* Fungsi-Fungsi untuk command *************//
void Serve(State * S) {
/* I.S. user memberi command untuk serve */
/* F.S. serve customer terdepan pada Antrian(S),.*/
    infoqueue P;
    int i,idwahana,choice,num;
    int daftarID[5];

    if (NEQPOINT(NextY(Position(*S)),LocAntrian(*S)) &&
        NEQPOINT(NextX(Position(*S)),LocAntrian(*S)) &&
        NEQPOINT(NextX(LocAntrian(*S)),Position(*S)) &&
        NEQPOINT(NextY(LocAntrian(*S)),Position(*S))) {
        printf("Anda tidak sedang berada di samping antrian!\n");
        return;
    }

    // Ambil informasi customer terdepan
    P = InfoHead(Antrian(*S));

    printf("// Daftar wahana yang dapat di-serve //\n\n");

    num = 0;
    for(i = 0; i < 5; i++) {
        idwahana = Play(P,i);
        if (idwahana != -1) {
            daftarID[num] = idwahana;
            num++;
            printf("%d. ", num);
            PrintKata(DataWahana(*S)[idwahana].nama);
            printf("\n");
        }
    }
    
    printf("Masukkan pilihan: ");
    scanf("%d", &choice);

    while (!isBetween(choice,1,num)) {
        printf("Masukkan tidak valid. ");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);
    }

    choice--;
    idwahana = daftarID[choice];
    
    // jika berhasil wahana yang dipilih user adalah DataWahana(*S)[idwahana]
    // jika wahana rusak
    if (DataWahana(*S)[idwahana].broke) {
        printf("// Gagal melayani pengunjung, wahana sedang rusak //\n");
        return;
    }

    // jika wahana full
    if (IsWahanaFull(&(DataWahana(*S)[idwahana]))) {
        printf("// Gagal melayani pengunjung, wahana sudah penuh //\n");
        return;
    }

    // jika wahana tidak penuh dan tidak rusak, maka berhasil melayani customer
    Money(*S) += DataWahana(*S)[idwahana].harga;

    // jumlah orang pada wahana tersebut akan bertambah    
    DataWahana(*S)[idwahana].banyak_orang++;

    // pendapatan yang tercatat akan bertambah
    DataWahana(*S)[idwahana].income += DataWahana(*S)[idwahana].harga;
    DataWahana(*S)[idwahana].income1 += DataWahana(*S)[idwahana].harga;
    
    // banyak pemakaian yang tercatat akan bertambah
    DataWahana(*S)[idwahana].count_used++;
    DataWahana(*S)[idwahana].count_used1++;

    // Pengunjung tersebut akan di-dequeue, lokasinya akan berpindah ke wahana
    Dequeue(&Antrian(*S),&P);
    Loc(P) = idwahana;
    Playtime(P) = DataWahana(*S)[idwahana].durasi; // waktu bermain customer akan di-set dengan durasi wahana
    Prio(P)--;  // prioritas pemain akan meningkat

    // wahana tersebut akan dihapus dari daftar wahana customer
    for(i = 0; i < 5; i++) {
        if (Play(P,i) == idwahana){
            Play(P,i) = -1;
        }
    }

    triggerBroke(&DataWahana(*S)[idwahana],S);  
    //  ada 10% chance wahana tersebut berubah menjadi rusak
}

void Repair(State * S) {
// I.S. user memberi command untuk repair
/* F.S. jika di sebelah kanan user terdapat wahana, 
        dan jika wahana tersebut rusak, dan jika uang user mencukupi, 
        wahana tersebut akan mulai reparation*/
    POINT posisi_wahana;
    address_w address_wahana_kanan;

    posisi_wahana = NextX(Position(*S));
    
    if (!IsWahana(Peta(*S),posisi_wahana)) {
        printf("Tidak ada wahana apapun di samping kanan\n");
        return;
    }

    address_wahana_kanan = (*S).map_address[Absis(posisi_wahana)][Ordinat(posisi_wahana)];

    if (!(*address_wahana_kanan).broke) {
        printf("wahana di samping kanan tidak rusak!\n");
        return;
    } 

    if (Money(*S) < (*address_wahana_kanan).harga_repair) {
        printf("Uang tidak cukup!\n");
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

    printDetail(&wahana_kanan);
    timeFlow(S,2); // melihat detail membutuhkan waktu 2 menit. (opsional)
}


void OFFice(State * S) {
/* I.S. user memberi command untuk mengakses office */
/* F.S. jika user berada pada posisi office, akan ditampilkan antarmuka office
        selama di dalam office, user dapat memberi command Details, Report, Exit
        user akan terus berada di office hingga memberi command Exit*/
    char choice[8];
    int choice_w;
    boolean exit;

    if (NEQPOINT(Position(*S), Office(*S))) {
        printf("// Anda tidak sedang berada di Office! //");
        return;
    }
    
    printf("// Memasuki office mode //");

    exit = false;

    do {
        printf("Masukkan perintah (Details / Report / Exit):");
        fgets(choice, 8, stdin);
        if (choice == "Details") {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (choice_w >= 0 && choice_w < (*S).NWahana) {
                printDetail(ListWahana(*S)[choice_w]);
                timeFlow(S,2); // melihat detail membutuhkan waktu 2 menit.
            } else {
                printf("invalid");
            }

        } else if (choice == "Report") {
            printListWahana(S); // tampilkan semua pilihan wahana
            scanf("%d", &choice_w);
            if (choice_w >= 0 && choice_w < (*S).NWahana) {
                printReport(ListWahana(*S)[choice_w]);
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
boolean isBetween(int val, int lower, int upper) {
// true jika lower <= val <= upper
    return val >= lower && val <= upper;
}

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
    // waktu bertambah satu menit
    Time(*S) = NextMenit(Time(*S));

    // Proses SETIAP CUSTOMER
    ProcessAllCustomers(S);

    // Proses SETIAP WAHANA
    ProcessAllWahanas(S);
}


void timeFlow(State * S, int N) {
    // I.S. Sembarang
    // F.S. Time(S) akan bertambah sebanyak N menit
    int i;
    for(i=0; i<N; i++) {
        incrementTime(S);
    }
}


void ProcessAllCustomers(State * S) {
// I.S. Sembarang
/* F.S. Akan dilakukan proses terhadap semua customer dalam satu satuan waktu
        sehingga seolah-olah proses paralel 
        setelah proses semua cutomer, ada 16.7% chance generate customer*/
    // KAMUS
    int rand_num,count_play;
    address_c P,Prec;
    boolean quit,masuk_antrian;
    
    // CEK SETIAP CUSTOMER
    P = First(DataCustomers(*S));
    while (P != Nil) {
        quit = false;
        Playtime(P) -= 1;
        if (Playtime(P) == 0) {
            if (Loc(P) != -1) {  //  customer berada pada suatu wahana
                //  jika customer sudah tidak lagi memiliki daftar wahana 
                //  yang ingin dinaiki, atau jika antrian penuh,
                //  ia akan keluar
                count_play = PlayCount(P);  //  menghitung daftar wahana customer
                if (count_play == 0 || IsFullQueue(Antrian(*S))) {  
                    quit = true;
                } else {
                    Loc(P) = -1;
                    Playtime(P) = 10;
                    masuk_antrian = true;
                }
            } else {   //  customer berada pada antrian
                Kesabaran(P) -= 1;
                Prio(P) -= 1;
                ReSort(&Antrian(*S),P); // customer akan diposisikan ke urutan yang semestinya
                if (Kesabaran(P) == 0) {  //  jika kesabaran customer habis, ia akan keluar.
                    quit = true;
                } else {
                    Playtime(P) = 10;
                }
            }
        }

        if (masuk_antrian) {
            Enqueue(&Antrian(*S),P);
        } else if (quit) {
            // jika berada pada antrian, customer akan di-dequeue
            if (Loc(P) == -1) {
                Dequeue(&Antrian(*S),&P);
            }
            if (P == First(DataCustomers(*S))) {
                DelFirst(&DataCustomers(*S), &P);
                Dealokasi(&P);
                P = First(DataCustomers(*S)); //  ke customer selanjutnya
            } else {
                DelAfter(&DataCustomers(*S), &P, Prec);
                Dealokasi(&P);
                Prec = P;
                P = Next(Prec); //  ke customer selanjutnya
            }
        } else {
            Prec = P;
            P = Next(P);  //  ke customer selanjutnya
        }
    }

    //  PADA KONDISI INI, P = Nil, Prec menunjukkan customer terakhir
    rand_num = Randomize(0,6);
    if (rand_num < 1) {  //  16.7 % chance for generate customer
        P = generateCustomer(S);
        if (P) {  //  if generate customer succes
            InsertAfter(&DataCustomers(*S), P, Prec);  // masukkan customer setelah Prec ke data
            Enqueue(&Antrian(*S), P);   //  masukkan customer ke antrian
        }
    }
}


void ProcessAllWahanas(State * S) {
// I.S. Sembarang
/* F.S. Akan dilakukan proses terhadap semua wahana dalam satu satuan waktu
        sehingga seolah-olah proses paralel */
    //  CEK SETIAP WAHANA
    int i;
    
    for(i=0; i<(*S).NWahana; i++) {
        if ((*ListWahana(*S)[i]).time_reparation != 0) {  // wahana sedang dalam perbaikan 
            (*ListWahana(*S)[i]).time_reparation -= 1;
            if ((*ListWahana(*S)[i]).time_reparation == 0) {  // jika wahana selesai diperbaiki
                (*ListWahana(*S)[i]).broke = false;
            }
        }
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

    if (IsFullQueue(Antrian(*S))) {  //  Jika Antrian penuh, langsung keluar
        Dealokasi(&P);               //  P di-dealokasi
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
    RandomPlay(P,S);  

    return P;
}


void triggerBroke(address_w W, State * S) {
// I.S. seorang pengunjung baru saja berhasil dilayani
// F.S. ada kemungkinan wahana dengan address W menjadi rusak
    int rand_num;
    address_c P,Prec;

    rand_num = Randomize(0,10);

    if (rand_num < 1) { // 10% chance wahana broke
        (*W).broke = true;
    }

    if ((*W).broke) {
        //  Jika wahana rusak, maka akan dilakukan proses setiap customer
        //  Jika Antrian tidak penuh,
        //  untuk customer yg berada di wahana tersebut akan pindah ke Antrian
        //  Loc(P) berubah menjadi -1, dan di-enqueue
        //  Jika Antrian penuh, cutomer pulang.
        P = First(DataCustomers(*S));
        while (P != Nil) {
            if (Loc(P) == (*W).ID) {
                Loc(P) = -1;
                Prio(P)--;
                Playtime(P) = 10;
                if (!IsFullQueue(Antrian(*S))) {
                    Enqueue(&Antrian(*S),P);
                    Prec = P;
                    P = Next(P);
                } else {  //  jika antrian penuh, customer pulang.
                    if (P == First(DataCustomers(*S))) {
                        DelFirst(&DataCustomers(*S),&P);
                        P = First(DataCustomers(*S));
                    } else {
                        DelAfter(&DataCustomers(*S),&P,Prec);
                        Prec = P;
                        P = Next(P);
                    }
                }
            } else {
                Prec = P;
                P = Next(P);
            }
        }
    }
}

//********** Fungsi-fungsi RNG ***********//
int Randomize(int lower_bound, int upper_bound) {
// menghasilkan bilangan random antara lower_bound dan upper_bound
    srand(time(NULL));
    return ((rand() % (upper_bound - lower_bound)) + lower_bound);
}


void RandomPlay(address_c P, State * S) {
// I.S. Sembarang
/* F.S. RNG for Play(P)*/
    int rand_num,i,nplay,j;
    boolean found;
    rand_num = Randomize(0,100);

    // 50 % chance 1 wahana, 25 % chance 2 wahana
    // 13 % chance 3 wahana, 7 % chance 4 wahana
    // 5 % chance 5 wahana (opsional)
    if (rand_num < 50) {
        nplay = 1;
    } else if (rand_num < 75) {
        nplay = 2;
    } else if (rand_num < 88) {
        nplay = 3;
    } else if (rand_num < 95) {
        nplay = 4;
    } else {
        nplay = 5;
    }

    if (nplay > NWahana(*S)) { 
        nplay = NWahana(*S);
    }

    i = 0;
    while (i < nplay) {
        rand_num = Randomize(0,NWahana(*S));
        found = false;
        j = 0;
        while (Play(P,j) != -1 && !found) {
            if (Play(P,j) = (*ListWahana(*S)[rand_num]).ID) {
                found = true;
            }
            j++;
        }
        if (!found){
            Play(P,j) = (*ListWahana(*S)[rand_num]).ID;
            i++;
        }
    }
}