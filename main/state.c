#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loading(State* S, char* filename, boolean isInput, boolean isLoad)
{
    STARTKATA(filename, ',');
    ldPlayerName(S, isLoad);
    ldPos(S, isInput);    
    ldTime(S, isInput);
    ldMDP("money", S);
    ldMDP("day", S);
    ldMDP("prep", S);
    ldInfoActs(S);
    ldActList(S);
    ldQueue(S);
    while (!EndKata)
    {
        ADVKATA(',');
    }
    ldMaterial(S);
    ldDefWahana(S);
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
    svInfoActs(&fp, S);
    svActList(&fp, S);
    svQueue(&fp, S);
    svCurMaterial(&fp, S);
    fputc(CC = MARK, fp);
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
    
    for (i = 0; i < strlen(string); ++i)
    {
        fputc(CC = string[i], *fp);
    }
    fputc(CC = '\n', *fp);
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

        for (j = 0; j < strlen(string); ++j)
        {
            fputc(CC = string[j], *fp);
        }
        if (i != 5)
        {
            fputc(CC = ',', *fp);
        }
    }
    fputc(CC = '\n', *fp);
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

void ldInfoActs(State *S)
{
    TempActs(*S) = ConvertKata(CKata);
    ADVKATA(',');
    TimeNeeded(*S) = ConvertKata(CKata);
    ADVKATA(',');
    MoneyNeeded(*S) = ConvertKata(CKata);
    ADVKATA(',');
}

void svCurMaterial(FILE** fp, State S)
{
    int i, j;
    char* string;
    for (i = 0; i < 5; ++i)
    {
        convert2StrKata(&string, Materials(S)[i].quantity);

        for (j = 0; j < strlen(string); ++j)
        {
            fputc(CC = string[j], *fp);
        }
        if (i != 4)
        {
            fputc(CC = ',', *fp);
        }
    }
    fputc(CC = '\n', *fp);
}

void ldMaterial(State* S)
{
    STARTKATA("../files/material.txt", ',');
    int i = 0;
    while (!EndKata)
    {
        LoadMaterial(&Materials(*S)[i++]);
        ADVKATA(',');
    } 
}   

void svActList(FILE** fp, State S)
{
    int i = 0, j;
    char* string;
    while (i != (Top(Act(S)) + 1))
    {
        convert2StrKata(&string, Act(S).T[i++]);
        writeAString(string, fp);
        if (i != (Top(Act(S)) + 1))
        {
            writeAChar(CC = ',', fp);
        }
    }
    fputc(CC = '\n', *fp);
}

void ldActList(State* S)
{
    int i = 0, j = 0;
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

void svQueue(FILE** fp, State S)
{
    if (MaxEl(Antrian(S)) == 0)
    {
        char* string = "-1;\n";
        writeAString(string, fp);
    }
    else
    {
        int i = 0, j = 0, k;
        /* int i sebagai index suatu elemen pada infoqueue T (antrean ke-n) */
        char* string;
        while (i < MaxEl(Antrian(S)))
        {
            for (j = 0; j < 9; ++j)
            {
                if (j == 0)
                {
                    convert2StrKata(&string, Prio(ElmtQueue(Antrian(S), i)));
                }
                else if (j > 0 && j < 6)
                {
                    convert2StrKata(&string, Play(ElmtQueue(Antrian(S), i), j));
                    ++j;
                }
                else if (j == 6)
                {
                    convert2StrKata(&string, Loc(ElmtQueue(Antrian(S), i)));
                }
                else if (j == 7)
                {
                    convert2StrKata(&string, Playtime(ElmtQueue(Antrian(S), i)));
                }
                else
                {
                    convert2StrKata(&string, Kesabaran(ElmtQueue(Antrian(S), i)));
                }

                writeAString(string, fp);

                if (i != 8)
                {
                    writeAChar(CC = ',', fp);
                }
            }
            if ((i == MaxEl(Antrian(S))-1) && i == 8)
            {
                writeAChar(CC = ';', fp);
            }
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
    if (CKata.TabKata[0] == '-')
    {
        Head(Antrian(*S)) = Nilqueue;
        Tail(Antrian(*S)) = Nilqueue;
        Antrian(*S).T = Nil;
        MaxEl(Antrian(*S)) = 0;
    }

    else
    {
        Head(Antrian(*S)) = 0;
        while (halt != -1)
        {
            for (i = 0; i < 9; ++i)
            {
                if (i == 0)
                {
                    Prio(ElmtQueue(Antrian(*S), j)) = ConvertKata(CKata);    
                }/*
                else if (i > 0 && i < 6)
                {
                    printf("i = %d\n", i);
                    Play(ElmtQueue(Antrian(*S), j), k) = ConvertKata(CKata);
                    ++k;
                }
                else if (i == 6)
                {
                    //Loc(ElmtQueue(Antrian(*S), j)) = ConvertKata(CKata);
                }
                else if (i == 7)
                {
                    Playtime(ElmtQueue(Antrian(*S), j)) = ConvertKata(CKata);
                }*/
                else if (i == 8)
                {
                    if (counterSC)
                    {
                        --CKata.Length;
                        --halt;
                        counterSC = false;
                    }
                    Kesabaran(ElmtQueue(Antrian(*S), j)) = ConvertKata(CKata);
                }
                ADVKATA(',');
            }
            ++j;
        }
        MaxEl(Antrian(*S)) = j;
        Tail(Antrian(*S)) = j-1;
    }
    
    
}

void ldDefWahana(State* S)
{
    STARTKATA("../files/wahana.txt", ',');
    int i = 0;
    while (!EndKata)
    {
        LoadWahana(&DataWahana(*S)[i++]);
        ADVKATA(',');
    }
}