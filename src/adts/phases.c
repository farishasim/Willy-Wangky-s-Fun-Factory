#include "phases.h"
#include <stdio.h>
#include <string.h>

void phasesFlow(State *S)
{
    if (options == (int)'w' || options == (int)'W')
    {
        W(S);
        if (Prep(*S))
        {
            prepPhase(S);
        }
        
        else
        {
            mainPhase(S);
        }
        
        phasesFlow(S);
    }

    else if (options == (int)'a' || options == (int)'A')
    {
        A(S);
        if (Prep(*S))
        {
            prepPhase(S);
        }
        
        else
        {
            mainPhase(S);
        }

        phasesFlow(S);
    }

    else if (options == (int)'s' || options == (int)'S')
    {
        Su(S);
        if (Prep(*S))
        {
            prepPhase(S);
        }
        
        else
        {
            mainPhase(S);
        }

        phasesFlow(S);
    }

    else if (options == (int)'d' || options == (int)'D')
    {
        D(S);
        if (Prep(*S))
        {
            prepPhase(S);
        }
        
        else
        {
            mainPhase(S);
        }

        phasesFlow(S);
    }

    else if (Prep(*S))
    {
        if (options == (int)'1')
        {
            //build
            prepPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'2')
        {
            //upgrade
            prepPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'3')
        {
            //buy
            prepPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'4')
        {
            //undo
            prepPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'5')
        {
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

        else if (options == (int)'6')
        {
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

        else if (options == (int)'0')
        {
            //info();
            listMenuPrepPhase(options);
            isMove = true;
            validateOptions(&options, '1', '6', isMove);
            phasesFlow(S);
        }
        else 
        {
            prepPhase(S);
            phasesFlow(S);
        }
    }

    else
    {
        if (options == (int)'1')
        {
            Serve(S);
            mainPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'2')
        {
            Repair(S);
            mainPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'3')
        {
            Detail(S);
            mainPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'4')
        {
            OFFice(S);
            mainPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'5')
        {
            prepPhase(S);
            Prep(*S) = true;
            phasesFlow(S);
        }

        else if (options == (int)'0')
        {
            //info();
            listMenuMainPhase(options);
            isMove = true;
            validateOptions(&options, '1', '5', isMove);
            phasesFlow(S);
        }
        else {
            mainPhase(S);
            phasesFlow(S);
        }
    }
}

void prepPhase(State *S)
{
    printf("\n***** Preparation Phase Day %d *****\n\n", Day(*S));
    TulisMATRIKS(Peta(*S));
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("^, <, v, > = Pagar\n\n");

    printf("Name: %s\n", Name(*S).TabKata);
    printf("Money: %d\n", Money(*S));
    printf("Current time: ");
    TulisJAM(Time(*S));
    printf("Opening time: ");
    TulisJAM(OpenTime(*S));
    printf("Time remaining: "); TulisDurasi(Durasi(OpenTime(*S),Time(*S)));
    printf("Total aksi yang akan dilakukan: %d\n", TempActs(*S));
    printf("Total waktu yang dibutuhkan: "); TulisDurasi(TimeNeeded(*S));
    printf("Total uang yang dibutuhkan: %d\n\n", MoneyNeeded(*S));
    listMenuPrepPhase(options);
    isMove = true;
    validateOptions(&options, '1', '6', isMove);
}

void mainPhase(State *S)
{
    printf("\n***** Main Phase Day %d *****\n\n", Day(*S));
    TulisMATRIKS(Peta(*S));
    printf("Legend:\n");
    printf("A = Antrian\n");
    printf("P = Player\n");
    printf("W = Wahana\n");
    printf("O = Office\n");
    printf("^, <, v, > = Pagar\n\n");

    printf("Name: %s\n", Name(*S).TabKata);
    printf("Money: %d\n", Money(*S));
    printf("Current time: ");
    TulisJAM(Time(*S));
    printf("Closing time: ");
    TulisJAM(CloseTime(*S));
    printf("Time remaining: "); TulisDurasi(Durasi(CloseTime(*S), Time(*S)));
    printf("Daftar antrian [%%d/%%d]:\n");
    //queue
    printf("\n");
    listMenuMainPhase(options);
    isMove = true;
    validateOptions(&options, '1', '5', isMove);
}