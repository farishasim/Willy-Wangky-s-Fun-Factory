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
    //else if (cekCommand("A\n"))
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
    //else if (cekCommand("S\n"))
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
    //else if (cekCommand("D\n"))
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
        //if (cekCommand("build\n"))
        {
            Build(S);
            prepPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'2')
        //else if (cekCommand("upgrade\n"))
        {
            //upgrade
            prepPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'3') // (cekCommand("buy\n"))
        {
            //buy
            prepPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'4')// (cekCommand("undo\n"))
        {
            //undo
            prepPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'5')// (cekCommand("execute\n"))
        {
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

        else if (options == (int)'6')//(cekCommand("main\n"))
        {
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

        else if (options == (int)'0')// (cekCommand("info options\n"))
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
        if (options == (int)'1')// (cekCommand("serve\n"))
        {
            //serve
            mainPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'2') //(cekCommand("repair\n"))
        {
            // repair
            Repair(S);
            mainPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'3')// (cekCommand("detail\n"))
        {
            // detail
            Detail(S);
            mainPhase(S);
            phasesFlow(S);
        }

        else if (options == (int)'4')// (cekCommand("office\n"))
        {
            // office
            OFFice(S);
            mainPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'5')// (cekCommand("prepare\n"))
        {
            //prepare
            prepPhase(S);
            Prep(*S) = true;
            phasesFlow(S);
        }

        else if (options == (int)'0')// (cekCommand("info options\n"))
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
    TulisJAM(Time(*S)); printf("\n");
    printf("Opening time: ");
    TulisJAM(OpenTime(*S)); printf("\n");
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
    TulisJAM(Time(*S)); printf("\n");
    printf("Closing time: ");
    TulisJAM(CloseTime(*S)); printf("\n");
    printf("Time remaining: "); TulisDurasi(Durasi(CloseTime(*S), Time(*S)));
    printf("Daftar antrian [%%d/%%d]:\n");
    //queue
    printf("\n");
    listMenuMainPhase(options);
    isMove = true;
    validateOptions(&options, '1', '5', isMove);
}