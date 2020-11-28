#include "phases.h"
#include <stdio.h>
#include <string.h>

void phasesFlow(State *S)
{
    //if (options == (int)'w' || options == (int)'W')
    if (cekCommand("W\n"))
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

    //else if (options == (int)'a' || options == (int)'A')
    else if (cekCommand("A\n"))
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

    //else if (options == (int)'s' || options == (int)'S')
    else if (cekCommand("S\n"))
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

    //else if (options == (int)'d' || options == (int)'D')
    else if (cekCommand("D\n"))
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
        //if (options == (int)'1')
        if (cekCommand("build\n"))
        {
            //build
            prepPhase(S);
            phasesFlow(S);
        }
            
        //else if (options == (int)'2')
        else if (cekCommand("upgrade\n"))
        {
            //upgrade
            prepPhase(S);
            phasesFlow(S);
        }

        else if /*(options == (int)'3')*/ (cekCommand("buy\n"))
        {
            //buy
            prepPhase(S);
            phasesFlow(S);
        }

        else if /*(options == (int)'4')*/ (cekCommand("undo\n"))
        {
            //undo
            prepPhase(S);
            phasesFlow(S);
        }
            
        else if /*(options == (int)'5')*/ (cekCommand("execute\n"))
        {
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

        else if /*(options == (int)'6')*/ (cekCommand("main\n"))
        {
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

        else if /*(options == (int)'0')*/ (cekCommand("info options\n"))
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
        if /*(options == (int)'1')*/ (cekCommand("serve\n"))
        {
            //serve
            mainPhase(S);
            phasesFlow(S);
        }
            
        else if /*(options == (int)'2') */(cekCommand("repair\n"))
        {
            // repair
            Repair(S);
            mainPhase(S);
            phasesFlow(S);
        }

        else if /*(options == (int)'3')*/ (cekCommand("detail\n"))
        {
            // detail
            Detail(S);
            mainPhase(S);
            phasesFlow(S);
        }

        else if /*(options == (int)'4')*/ (cekCommand("office\n"))
        {
            // office
            OFFice(S);
            mainPhase(S);
            phasesFlow(S);
        }
            
        else if /*(options == (int)'5')*/ (cekCommand("prepare\n"))
        {
            //prepare
            prepPhase(S);
            Prep(*S) = true;
            phasesFlow(S);
        }

        else if /*(options == (int)'0')*/ (cekCommand("info options\n"))
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
    printf("Money: \n");
    printf("Current time: ");
    TulisJAM(Time(*S));
    printf("Opening time: ");
    TulisJAM(OpenTime(*S));
    if (MenitToJAM(Durasi(OpenTime(*S),Time(*S))).MM == 0)
    {
        printf("Time Remaining: %d hour(s)\n", MenitToJAM(Durasi(OpenTime(*S),Time(*S))).HH);
    }

    else
    {
        printf("Time Remaining: %d hour(s) %d minute(s)\n", MenitToJAM(Durasi(OpenTime(*S),Time(*S))).HH, MenitToJAM(Durasi(OpenTime(*S),Time(*S))).MM);
    }
    
    
    printf("Total aksi yang akan dilakukan: \n");
    printf("Total waktu yang dibutuhkan: \n");
    printf("Total uang yang dibutuhkan: \n\n");

    listMenuPrepPhase(options);
    isMove = true;
    //validateOptions(&options, '1', '6', isMove);
    fgets(command, 20, stdin);
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
    printf("Money: \n");
    printf("Current time: ");
    TulisJAM(Time(*S));
    printf("Closing time: ");
    TulisJAM(CloseTime(*S));
    if (MenitToJAM(Durasi(CloseTime(*S),Time(*S))).MM == 0)
    {
        printf("Time Remaining: %d hour(s)\n", MenitToJAM(Durasi(CloseTime(*S),Time(*S))).HH);
    }

    else
    {
        printf("Time Remaining: %d hour(s) %d minute(s)\n", MenitToJAM(Durasi(CloseTime(*S),Time(*S))).HH, MenitToJAM(Durasi(OpenTime(*S),Time(*S))).MM);
    }
    
    
    printf("Daftar antrian [%%d/%%d]:\n");
    //queue
    printf("\n");
    listMenuMainPhase(options);
    isMove = true;
    //validateOptions(&options, '1', '5', isMove);
    fgets(command, 20, stdin);
}