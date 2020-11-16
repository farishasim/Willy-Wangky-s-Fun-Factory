#include "mainmenus.h"
#include "commands.h"
#include "map.h"
#include "phases.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    if (!isPlaying)
    {
        printf("\n******************** Welcome to Willy Wangky's fum factory!!! ********************\n");
        isLoad = false;
        isName = false;
    }

    isPlaying = true;
    isInput = false;
    isMove = false;
    listMenu(options);
    validateOptions(&options, '1', '5', isMove);

    if (options == (int)'1')
    {
        newGame(&S);
        chooseState(options);
        validateOptions(&options, '1', '2', isMove);

        if (options == (int)'1') //pilih manual
        {
            inputManual(&S);
            isInput = true;
        }
        isLoad = false;
        loading(&S, "state.txt", isInput, isLoad);
        isLoad = true;
        Prep(S) = true;
        prepPhase(&S);
        phasesFlow(&S);

        if (options == (int)'9')
        {
            main();
        }
    }
    
    else if (options == (int)'2')
    {
        isLoad = true;
        loadGame(&S);
        isName = true;
        main();
    }

    else if (options == (int)'3')
    {
        if (!isLoad)
        {
            printf("\nGame belum dimuat. Silakan pilih New Game atau Load Game terlebih dahulu.\n");
        }

        else
        {
            saveGame(S);
        }
        main();
    }

    else if (options == (int)'4')
    {
        Continue(&S, isLoad, Prep(S), options);

        if (isLoad)
        {
            phasesFlow(&S);
            if (options == (int)'9')
            {
                main();
            }
        }

        else
        {
            main();
        }
    }

    else if (options == (int)'5')
    {
        Exit(S);
    }

    else if (options == (int)'0')
    {
        //info(curMenu)
        main();
    }

    return 0;
}

//gcc -o willygame willygame.c mainmenus.o matriks.o point.o map.o commands.o phases.o jam.o mesinkata.c mesinkar.o state.o
//Linux OS