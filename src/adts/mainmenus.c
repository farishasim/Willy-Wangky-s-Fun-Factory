#include "phases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char command[20];
State S;
optiontype options;
boolean isName, isLoad, isMove, isInput, isPlaying = false;

void newGame(State* S)
{
    printf("\n***** Memulai permainan baru *****\n\n");
    printf("Masukkan nama (maksimal 20 karakter): ");   
    inputPName(S);
}

void saveGame(State S)
{
    printf("\nMasukkan nama file untuk menyimpan datanya: ");
    Kata filename;
    fgets(filename.TabKata, NMax, stdin);
    filename.TabKata[strlen(filename.TabKata)-1] = '\0';
    saving(S, filename.TabKata);
    printf("\nData game berhasil disimpan.\n");
}

void loadGame(State *S)
{
    printf("\nMasukkan nama file yang menyimpan data game-nya: ");
    Kata filename;
    fgets(filename.TabKata, NMax, stdin);
    filename.TabKata[strlen(filename.TabKata)-1] = '\0';
    loading(S, filename.TabKata, isInput, isLoad);
    printf("\nData game berhasil dimuat.\n");
}

void Continue(State *S, boolean isLoad, boolean prep, optiontype menu)
{
    if (!isLoad)
    {
        printf("\nGame belum dimuat. Silakan pilih New Game atau Load Game terlebih dahulu.\n");
    }

    else if (isLoad && prep)
    {
        prepPhase(S);
    }

    else if (isLoad && !prep)
    {
        mainPhase(S);
    }
    
}

void Exit(State S)
{
    if (!isName)
    {
        printf("\nThanks for playing!\n");
    }

    else
    {
        printf("\nThanks for playing, %s!\n", Name(S).TabKata);
    }
}

void inputPName(State* S)
{  
    fgets(Name(*S).TabKata, NMax, stdin);
    Name(*S).Length = strlen(Name(*S).TabKata)-1;

    printf("aaaa");

    while (Name(*S).Length > 20)
    {
        printf("Jumlah karakter pada nama melebihi 20 karakter.\n");
        printf("Masukkan nama (maksimal 20 karakter): ");  
        fgets(Name(*S).TabKata, NMax, stdin);
        Name(*S).Length = strlen(Name(*S).TabKata)-1;
    }

    while (Name(*S).Length == 0)
    {
        printf("Nama pemain tidak boleh kosong.\n");
        printf("Masukkan nama (maksimal 20 karakter): ");  
        fgets(Name(*S).TabKata, NMax, stdin);
        Name(*S).Length = strlen(Name(*S).TabKata)-1;
    }

    isName = true;
    Name(*S).TabKata[Name(*S).Length] = '\0'; //ganti '\n' jadi '\0' 
}

void validateOptions(optiontype* menu, char l, char g, boolean isMove)
{
    *menu = getc(stdin);
    while (getc(stdin) != '\n');

    if (isMove) //terdapat command W, A, S, atau D
    {
        while ((*menu < (int)l || *menu > (int)g) && *menu != 48 && *menu != 57 && *menu != 119 && *menu != 87 && *menu != 97 && *menu != 65 && *menu != 115 && *menu != 83 && *menu != 100 && *menu != 68)
        {
            printf("Pilihan perintah tidak tersedia. Masukkan huruf atau angka yang sesuai.\n");
            printf("Pilih perintah (huruf atau angka pertama yang akan disimpan): ");
            *menu = getc(stdin);
            while (getc(stdin) != '\n');
        }
    }

    else
    {
        while ((*menu < (int)l || *menu > (int)g) && *menu != 48)
        {
            printf("Pilihan menu tidak tersedia. Masukkan angka antara %c -- %c atau 0.\n", l, g);
            printf("Pilih menu (angka pertama yang akan disimpan): ");
            *menu = getc(stdin);
            while (getc(stdin) != '\n');
        }
    }
}

boolean cekCommand(char * command_name) {
    return strcmp(command, command_name) == 0;
}