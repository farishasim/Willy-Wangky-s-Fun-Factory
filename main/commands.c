#include "mainmenus.h"
#include "commands.h"
#include "wahana.h"
#include <stdio.h>

void listMenu(optiontype menu)
{
    printf("\nMenu:\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("3. Save Game\n");
    printf("4. Continue\n");
    printf("5. Exit\n");
    printf("0. Info Options\n");
    printf("Masukkan angka untuk memilih menu (contoh, '1' untuk New Game)");
    printf("\nPilih menu (angka pertama yang akan disimpan): ");
}

void listMenuPrepPhase(optiontype menu)
{
    printf("Perintah: \n");
    printf("W\n");
    printf("A\n");
    printf("S\n");
    printf("D\n");
    printf("1. Build\n");
    printf("2. Upgrade\n");
    printf("3. Buy\n");
    printf("4. Undo\n");
    printf("5. Execute\n");
    printf("6. Main\n");
    printf("9. Main Menu\n");
    printf("0. Info Options\n");
    printf("\nPilih perintah (huruf atau angka pertama yang akan disimpan): ");
}

void listMenuMainPhase(optiontype menu)
{
    printf("Perintah: \n");
    printf("W\n");
    printf("A\n");
    printf("S\n");
    printf("D\n");
    printf("1. Serve\n");
    printf("2. Repair\n");
    printf("3. Detail\n");
    printf("4. Office\n");
    printf("5. Prepare\n");
    printf("9. Main Menu\n");
    printf("0. Info Options\n");
    printf("\nPilih perintah (huruf atau angka pertama yang akan disimpan): ");
}

void chooseState(optiontype options)
{
    printf("\nApakah Anda ingin menentukan beberapa komponen secara manual?\n");
    printf("1. Ya, tentukan secara manual\n");
    printf("2. Tidak, gunakan default dari game\n");
}

void inputManual(State *S/*, Wahana *W*/)
{
    printf("\nTentukan luas taman bermain (default-nya adalah 11 (11 x 11)): ");
    scanf("%d", &Peta(*S).NBrsEff);
    while (Peta(*S).NBrsEff < 5 || Peta(*S).NBrsEff > 15)
    {
        printf("Masukkan antara 5 (untuk 5 x 5) -- 15 (untuk 15 x 15): ");
        scanf("%d", &Peta(*S).NBrsEff);
    }
    Peta(*S).NKolEff = Peta(*S).NBrsEff;

    /*
    //Masalah ukuran, blm jelas
    InitialMap(&Peta(*S), Peta(*S).NBrsEff, Peta(*S).NKolEff);
    TulisMATRIKS(Peta(*S));
    printf("Tentukan lokasi wahana: ");
    scanf("%d", LocWahana(*W));
    while (LocWahana(*W).X )
    */

    InitialMap(&Peta(*S));
    printf("\nLokasi objek-objek saat ini:\n");
    TulisMATRIKS(Peta(*S));
    printf("\nTentukan lokasi antrian (Contoh, 1 1 berada di pojok kiri atas peta): ");
    scanf("%d", &LocAntrian(*S).X);
    scanf("%d", &LocAntrian(*S).Y);
    while (LocAntrian(*S).X == 1 || LocAntrian(*S).X == Peta(*S).NBrsEff || LocAntrian(*S).Y == 0 || LocAntrian(*S).Y == Peta(*S).NKolEff /*|| (LocAntrian(*S).X == Position(*S).X && LocAntrian(*S).Y == Position(*S).Y)*/)
    {
        if (LocAntrian(*S).X < 1 || LocAntrian(*S).X > Peta(*S).NBrsEff || LocAntrian(*S).Y < 0 || LocAntrian(*S).Y > Peta(*S).NKolEff)
        {
            printf("Input tidak valid.\n");
        }

        else
        {
            printf("Terdapat bangunan atau benda lain di sana.\n"); //minus wahana dan pemain
        }
        
        printf("Tentukan lokasi antrian (Contoh, 1 1 berada di pojok kiri atas peta): ");
        scanf("%d", &LocAntrian(*S).X);
        scanf("%d", &LocAntrian(*S).Y);
    }
    SetAntrian(&Peta(*S), LocAntrian(*S));
    printf("\nLokasi objek-objek saat ini:\n");
    TulisMATRIKS(Peta(*S));

    printf("\nTentukan lokasi office (Contoh, 1 1 berada di pojok kiri atas peta): ");
    scanf("%d", &Office(*S).X);
    scanf("%d", &Office(*S).Y);
    while (Office(*S).X <= 1 || Office(*S).X >= Peta(*S).NBrsEff || Office(*S).Y <= 0 || Office(*S).Y >= Peta(*S).NKolEff || ((LocAntrian(*S).X == Office(*S).X) && (LocAntrian(*S).Y == Office(*S).Y))/*|| (LocAntrian(*S).X == Position(*S).X && LocAntrian(*S).Y == Position(*S).Y)*/)
    {
        if (Office(*S).X < 1 || Office(*S).X > Peta(*S).NBrsEff || Office(*S).Y < 0 || Office(*S).Y > Peta(*S).NKolEff)
        {
            printf("Lokasi tidak valid.\n");
        }

        else
        {
            printf("Terdapat bangunan atau benda lain di sana.\n"); //minus wahana dan pemain
        }

        printf("Tentukan lokasi office (Contoh, 1 1 berada di pojok kiri atas peta): ");
        scanf("%d", &Office(*S).X);
        scanf("%d", &Office(*S).Y);
    }

    SetOffice(&Peta(*S), Office(*S));
    printf("\nLokasi objek-objek saat ini:\n");
    TulisMATRIKS(Peta(*S));

    printf("\nTentukan waktu taman dibuka (default-nya adalah 09 00 (sembilan pagi)): ");
    scanf("%d", &OpenTime(*S).HH);
    scanf("%d", &OpenTime(*S).MM);
    while (!IsJAMValid(OpenTime(*S).HH, OpenTime(*S).MM) || OpenTime(*S).HH < 7 || OpenTime(*S).HH > 12 || ((OpenTime(*S).HH == 12) && (OpenTime(*S).MM > 0)))
    {
        if (!IsJAMValid(OpenTime(*S).HH, OpenTime(*S).MM))
        {
            printf("Jam tidak valid.\n");
        }
        else
        {
            printf("Taman bermain mulai dapat dibuka antara 07 00 -- 12 00.\n");
            
        }
        
        printf("Tentukan waktu taman dibuka (default-nya adalah 09 00 (sembilan pagi)): ");
        scanf("%d", &OpenTime(*S).HH);
        scanf("%d", &OpenTime(*S).MM);
    }
    
    printf("\nTentukan waktu taman ditutup (default-nya adalah 21 00 (sembilan malam)): ");
    scanf("%d", &CloseTime(*S).HH);
    scanf("%d", &CloseTime(*S).MM);
    while (!IsJAMValid(CloseTime(*S).HH, CloseTime(*S).MM) || CloseTime(*S).HH < 19 || ((CloseTime(*S).HH == 0) && (CloseTime(*S).MM > 0)))
    {
        if (!IsJAMValid(CloseTime(*S).HH, CloseTime(*S).MM))
        {
            printf("Jam tidak valid.\n");
        }

        else
        {
            printf("Taman bermain dapat dan harus sudah ditutup antara 19 00 -- 23 59.\n");
        }
        
        printf("Tentukan waktu taman ditutup (default-nya adalah 21 00 (sembilan malam)): ");
        scanf("%d", &CloseTime(*S).HH);
        scanf("%d", &CloseTime(*S).MM);
    }

    Time(*S) = CloseTime(*S);
    while (getc(stdin) != '\n');
}