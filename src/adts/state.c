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
    svInfoActs(&fp, S);
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