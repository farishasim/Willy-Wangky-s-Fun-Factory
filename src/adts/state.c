#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

void loading(State* S, char* filename, boolean isInput, boolean isLoad)
{
    ldDefMaterial(S);
    ldDefWahana(S);
    STARTKATA(filename, ',');
    ldPlayerName(S, isLoad);
    ldPos(S, isInput);    
    ldTime(S, isInput);
    ldMDP("money", S);
    ldMDP("day", S);
    ldMDP("prep", S);
    ldQuantityMaterial(S);
    ldInfoActs(S);
    ldActList(S);
    ldQueue(S);
    ldMap(S, isInput);
    ldWahanaPlayer(S);
    while (!EndKata)
    {
        ADVKATA(',');
    }
}

void saving(State S, char* filename)
{
    FILE* fp = fopen(filename, "w");
    svPlayerName(&fp, S);
    svPos(&fp, S);
    svTime(&fp, S);
    svMDP("money", &fp, S);
    svMDP("day", &fp, S);
    svMDP("prep", &fp, S);
    svQuantityMaterial(&fp, S);
    svInfoActs(&fp, S);
    svActList(&fp, S);
    svQueue(&fp, S);
    svWahanaPlayer(&fp,S);
    writeAChar(CC = MARK, &fp);
    fclose(fp);
}

void svPlayerName(FILE** fp, State S)
{
    int i;
    for (int i = 0; i < Name(S).Length; ++i)
    {
        fputc(CC = Name(S).TabKata[i], *fp);
    }
    fputc(CC = '\n', *fp);   
}

void ldPlayerName(State *S, boolean isLoad)
{
    int i;
    if (isLoad)
    {
        for (i = 0; i < CKata.Length; ++i)
        {
            Name(*S).TabKata[i] = CKata.TabKata[i];
        }
        Name(*S).Length = CKata.Length; 
    }
    ADVKATA(',');
}

void svMDP(char* mdp, FILE** fp, State S)
{
    int i;
    char* string;
    if (mdp == "money")
    {
        convert2StrKata(&string, Money(S));
    }
     if (mdp == "day")
    {
        convert2StrKata(&string, Day(S));
    }
    else if (mdp == "prep")
    {
        convert2StrKata(&string, Prep(S)); 
    }
    
    writeAString(string, fp);
    writeAChar(CC = '\n', fp);
}

void ldMDP(char* mdp, State *S)
{
    if (mdp == "money")
    {
        Money(*S) = ConvertKata(CKata);
    }
    else if (mdp == "day")
    {
        Day(*S) = ConvertKata(CKata);
    }
    else if (mdp == "prep")
    {
        Prep(*S) = ConvertKata(CKata); 
    }
    ADVKATA(',');
}

void svPos(FILE** fp, State S)
{
    int i, j;
    char* string;
    for (i = 0; i < 6; ++i)
    {
        if (i == 0)
        {
            convert2StrKata(&string, Position(S).X);
        }
        else if (i == 1)
        {
            convert2StrKata(&string, Position(S).Y);
        }
        else if (i == 2)
        {
            convert2StrKata(&string, Office(S).X);
        }
        else if (i == 3)
        {
            convert2StrKata(&string, Office(S).Y);
        }
        else if (i == 4)
        {
            convert2StrKata(&string, LocAntrian(S).X);
        }
        else if (i == 5)
        {
            convert2StrKata(&string, LocAntrian(S).Y);
        }

        writeAString(string, fp);
        if (i != 5)
        {
            writeAChar(CC = ',', fp);
        }
    }
    writeAChar(CC = '\n', fp);
}

void ldPos(State* S, boolean isInput)
{
    if (isInput)
    {
        int i;
        for (i = 0; i < 6; ++i)
        {
            ADVKATA(',');
        }
    }
    else
    {
        Position(*S).X = ConvertKata(CKata);
        ADVKATA(',');
        Position(*S).Y = ConvertKata(CKata);
        ADVKATA(',');
        Office(*S).X = ConvertKata(CKata);
        ADVKATA(',');
        Office(*S).Y = ConvertKata(CKata);
        ADVKATA(',');
        LocAntrian(*S).X = ConvertKata(CKata);
        ADVKATA(',');
        LocAntrian(*S).Y = ConvertKata(CKata);
        ADVKATA(',');
    }
}

void svTime(FILE** fp, State S)
{
    int i, j;
    char* string;
    for (i = 0; i < 3; ++i)
    {
        if (i == 0)
        {
            convert2StrKata(&string, JAMToMenit(Time(S)));
        }
        else if (i == 1)
        {
            convert2StrKata(&string, JAMToMenit(OpenTime(S)));
        }
        else if (i == 2)
        {
            convert2StrKata(&string, JAMToMenit(CloseTime(S)));
        }

        for (j = 0; j < strlen(string); ++j)
        {
            fputc(CC = string[j], *fp);
        }
        if (i != 2)
        {
            fputc(CC = ',', *fp);
        }
    }
    fputc(CC = '\n', *fp);
}

void ldTime(State *S, boolean isInput)
{
    if (isInput)
    {
        int i;
        for (i = 0; i < 3; ++i)
        {
            ADVKATA(',');
        }
    }
    else
    {
        Time(*S) = MenitToJAM(ConvertKata(CKata));
        ADVKATA(',');
        OpenTime(*S) = MenitToJAM(ConvertKata(CKata));
        ADVKATA(',');
        CloseTime(*S) = MenitToJAM(ConvertKata(CKata));
        ADVKATA(',');
    }  
}

void svInfoActs(FILE** fp, State S)
{
    int i, j;
    char* string;
    for (i = 0; i < 3; ++i)
    {
        if (i == 0)
        {
            convert2StrKata(&string, TempActs(S));
        }
        else if (i == 1)
        {
            convert2StrKata(&string, TimeNeeded(S));
        }
        else if (i == 2)
        {
            convert2StrKata(&string, MoneyNeeded(S));
        }

        writeAString(string, fp);
        if (i != 2)
        {
            writeAChar(CC = ',', fp);
        }
    }
    writeAChar(CC = '\n', fp);
}

void ldInfoActs(State *S)
{
    TempActs(*S) = ConvertKata(CKata);
    ADVKATA(',');
    TimeNeeded(*S) = ConvertKata(CKata);
    ADVKATA(',');
    MoneyNeeded(*S) = ConvertKata(CKata);
    ADVKATA(',');
}

void svQuantityMaterial(FILE** fp, State S)
{
    int i, j;
    char* string;
    for (i = 0; i < 5; ++i)
    {
        convert2StrKata(&string, Storage(S)[i].quantity);
        writeAString(string, fp);
        if (i != 4)
        {
            writeAChar(CC = ',', fp);
        }
    }
    writeAChar(CC = '\n', fp);
}

void ldQuantityMaterial(State* S)
{
    int i;
    for (i = 0; i < 5; ++i)
    {
        Storage(*S)[i].quantity = ConvertKata(CKata);
        ADVKATA(',');
    }
}

void ldDefMaterial(State* S)
{
    STARTKATA("../../file/material.txt", ',');
    int i = 0;
    for (i = 0; i < 5; ++i)
    {
        CopyKata(CKata, &Storage(*S)[i].nama);
        ADVKATA(',');
        Storage(*S)[i].harga = ConvertKata(CKata);
        ADVKATA(',');
    }
}   

void svActList(FILE** fp, State S)
{
    int i = 0, j;
    char* string;
    if (IsEmptyStackt(Act(S)))
    {
        string = "-1\n";
        writeAString(string, fp);
    }
    else
    {
        while (i != (Top(Act(S)) + 1))
        {
            convert2StrKata(&string, Act(S).T[i++]);
            writeAString(string, fp);
            if (i != (Top(Act(S)) + 1))
            {
                writeAChar(CC = ',', fp);
            }
        }
        writeAChar(CC = '\n', fp);
    }
}

void ldActList(State* S)
{
    int i = 0, j = 0;
    if (CKata.TabKata[0] != '-')
    {
        CreateEmptyStackt(&Act(*S));
        ADVKATA(',');
    }
    else
    {
        while (j != -1)
        {
            Act(*S).T[i++] = ConvertKata(CKata);
            if (counterNL)
            {   
                --j; 
                counterNL = false;
            }
            ADVKATA(',');
        }
        Top(Act(*S)) = i - 1;
    }
}

void svQueue(FILE** fp, State S)
{
    if (First(DataCustomers(S)) == Nil)
    {
        char* string = "-1;\n";
        writeAString(string, fp);
    }
    else
    {
        int j, i = 0;;
        /* int i sebagai index suatu elemen pada infoqueue T (antrean ke-n) */
        /* int j sebagai index suatu elemen pada array of integer play (banyaknya wanna play wahana tiap pengantre) */
        /* int halt penanda bahwa semicolon is found sehingga looping berhenti */
        char* string;
        address_c P = First(DataCustomers(S));
        while (P != Nil)
        {
            for (j = 0; j < 9; ++j)
            {
                if (j == 0)
                {
                    convert2StrKata(&string, Prio(P));
                }
                else if (j > 0 && j < 6)
                {
                    convert2StrKata(&string, Play(P, i));
                    ++i;
                }
                else if (j == 6)
                {
                    convert2StrKata(&string, Loc(P));
                }
                else if (j == 7)
                {
                    convert2StrKata(&string, Playtime(P));
                }
                else
                {
                    convert2StrKata(&string, Kesabaran(P));
                }

                writeAString(string, fp);

                if (j != 8)
                {
                    writeAChar(CC = ',', fp);
                }
            }
            i = 0;
            if (Next(P) == Nil)
            {
                writeAChar(CC = ';', fp);
            }
            P = Next(P);
            writeAChar(CC = '\n', fp);
        }
        writeAChar(CC = '\n', fp);
    }   
}

void ldQueue(State* S)
{
    int i, j = 0, k = 0, halt = 0;
    /* int i sebagai penunjuk komponen-komponen infolist */
    /* int j sebagai index suatu elemen pada infoqueue T (antrean ke-n) */
    /* int k sebagai index suatu elemen pada array of integer play (banyaknya wanna play wahana tiap pengantre) */
    /* int halt penanda bahwa semicolon is found sehingga looping berhenti */
    address_c P;
    CreateEmpty(&DataCustomers(*S));
    MakeEmptyQueue(&Antrian(*S), 10);
    if (MaxEl(Antrian(*S)) != 0)
    {
        if (CKata.TabKata[0] == '-')
        {
            First(DataCustomers(*S)) = Nil;
            ADVKATA(',');
        }

        else
        {
            while (halt != -1)
            {
                P = Alokasi();
                if (P != Nil)
                {
                    for (i = 0; i < 9; ++i)
                    {   
                        if (i == 0)
                        {
                            Prio(P) = ConvertKata(CKata);
                        }
                        else if (i > 0 && i < 6)
                        {
                            Play(P, k) = ConvertKata(CKata);
                            ++k;
                        }
                        else if (i == 6)
                        {
                            Loc(P) = ConvertKata(CKata);
                            if(Loc(P) == -1)
                            {
                                Enqueue(&Antrian(*S), ElmtQueue(Antrian(*S), j));
                            }
                        }
                        else if (i == 7)
                        {
                            Playtime(P) = ConvertKata(CKata);
                        }
                        else if (i == 8)
                        {
                            if (counterSC)
                            {
                                --CKata.Length;
                                --halt;
                                counterSC = false;
                            }
                            Kesabaran(P) = ConvertKata(CKata);
                        }
                        ADVKATA(',');
                    }
                    InsertLast(&DataCustomers(*S), P);
                    k = 0;
                }
                else
                {
                    break;
                }   
                ++j;
            }
        }
    }
}

void ldWahanaPlayer(State* S)
{
    /* Search wahana yang dimiliki pemain terhadap data wahana yang tersedia berdasarkan ID-nya */
    int halt = 0, i, j = 0, posX, posY, idWahana, idxWahana, lahan, id_prev;
    while (halt != -1)
    {
        idWahana = ConvertKata(CKata);
        PrintKata(CKata);
        idxWahana = idxWahanaEQbyID(idWahana, DataWahana(*S));
        printf("%d", idxWahana);
        ListWahana(*S)[j] = &DataWahana(*S)[idxWahana];
        for (int i = 0; i < 9; i++)
        {
            if (i == 0)
            {
                ListWahana(*S)[j]->ID = idWahana;
            }
            else if (i == 1)
            {
                posX = ConvertKata(CKata);
            }
            else if (i == 2)
            {
                posY = ConvertKata(CKata);
                ListWahana(*S)[j]->position = MakePOINT(posX, posY);
            }
            else if (i == 3)
            {
                ListWahana(*S)[j]->count_used = ConvertKata(CKata);
            }
            else if (i == 4)
            {
                ListWahana(*S)[j]->income = ConvertKata(CKata);
            }
            else if (i == 5)
            {
                ListWahana(*S)[j]->count_used1 = ConvertKata(CKata);
            }
            else if (i == 6)
            {
                ListWahana(*S)[j]->income1 = ConvertKata(CKata);
            }
            else if (i == 7)
            {
                ListWahana(*S)[j]->broke = ConvertKata(CKata);
            }
            else if (i == 8)
            {
                if (counterSC)
                {
                    --CKata.Length;
                    --halt;
                    counterSC = false;
                }
                ListWahana(*S)[j]->lahan = ConvertKata(CKata);
                lahan = ListWahana(*S)[j]->lahan;
            }
            ADVKATA(',');
        }
        SetStateWahana(S, ListWahana(*S)[j]);
        ++j;
    }
    NWahana(*S) = j;
}

void svWahanaPlayer(FILE** fp, State S)
{
    char* str; 
    int i, j, halt = 0;
    while (j < NWahana(S))
    {
        for (i = 0; i < 8; ++i)
        {
            if (i == 0)
            {
                convert2StrKata(&str, ListWahana(S)[i]->ID);
            }
            else if (i == 1)
            {
                convert2StrKata(&str, ListWahana(S)[i]->position.X);
            }
            else if (i == 2)
            {
                convert2StrKata(&str, ListWahana(S)[i]->position.Y);
            }
            else if (i == 3)
            {
                convert2StrKata(&str, ListWahana(S)[i]->count_used);
            }
            else if (i == 4)
            {
                convert2StrKata(&str, ListWahana(S)[i]->income);
            }
            else if (i == 5)
            {
                convert2StrKata(&str, ListWahana(S)[i]->count_used1);
            }
            else if (i == 6)
            {
                convert2StrKata(&str, ListWahana(S)[i]->income1);
            }
            else if (i == 7)
            {
                convert2StrKata(&str, ListWahana(S)[i]->broke);
            }
            writeAString(str, fp);
            if (i != 7)
            {
                writeAChar(CC = ',', fp);
            }
        }
        if (j == NWahana(S)-1)
        {
            writeAChar(CC = ';', fp);
        }
        else
        {
            writeAChar(CC = '\n', fp);
        }
        ++j;
    }
}

void ldMap(State* S, boolean isInput)
{
    if (!isInput) {
        for(int i = 0; i<4; i++) 
        {
            inputManualPeta(&(*S).peta[i], &(*S).peta_address[i], isInput);
            if (i == 0) {
                Elmt((*S).peta[i], NBrsEff((*S).peta[i])/2, NKolEff((*S).peta[i])-1) = '>';
                Elmt((*S).peta[i], NBrsEff((*S).peta[i])-1, NKolEff((*S).peta[i])/2) = 'V';
            } else if (i == 1) {
                Elmt((*S).peta[i], NBrsEff((*S).peta[i])/2, 0) = '<';
                Elmt((*S).peta[i], NBrsEff((*S).peta[i])-1, NKolEff((*S).peta[i])/2) = 'V';
            } else if (i == 2) {
                Elmt((*S).peta[i], NBrsEff((*S).peta[i])/2, NKolEff((*S).peta[i])-1) = '>';
                Elmt((*S).peta[i], 0, NKolEff((*S).peta[i])/2) = '^';
            } else {
                Elmt((*S).peta[i], NBrsEff((*S).peta[i])/2, 0) = '<';
                Elmt((*S).peta[i], 0, NKolEff((*S).peta[i])/2) = '^';
            }
        }
        printf("booyeahh!!!\n");
        MakeGraph(&Area(*S));
        SetAntrian(&Peta(*S), LocAntrian(*S));
        SetForbiddenAddress(&PetaAddress(*S), LocAntrian(*S));
        SetOffice(&Peta(*S), Office(*S));
        SetForbiddenAddress(&PetaAddress(*S), Office(*S));
        Position(*S) = MakePOINT(Absis(Office(*S)),Ordinat(Office(*S)));
        SetPlayer(&Peta(*S), Position(*S));
    }
}


void ldDefWahana(State* S)
{
    START("../../file/wahana.txt");
    int i = 0;
    while (!EOP)
    {
        LoadWahana(&DataWahana(*S)[i]);
        SetPohonWahana(S,&DataWahana(*S)[i++]);
        //ADVKATA(',');
    }
}