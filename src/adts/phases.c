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
<<<<<<< HEAD
=======
    //else if (cekCommand("A\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
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
<<<<<<< HEAD
=======
    //else if (cekCommand("S\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
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
<<<<<<< HEAD
=======
    //else if (cekCommand("D\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
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
<<<<<<< HEAD
=======
        //if (cekCommand("build\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Build(S);
            prepPhase(S);
            phasesFlow(S);
        }
            
        else if (options == (int)'2')
<<<<<<< HEAD
=======
        //else if (cekCommand("upgrade\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Upgrade(S);
            prepPhase(S);
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'3')
=======
        else if (options == (int)'3') // (cekCommand("buy\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Buy(S);
            prepPhase(S);
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'4')
=======
        else if (options == (int)'4')// (cekCommand("undo\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Undo(S);
            prepPhase(S);
            phasesFlow(S);
        }
            
<<<<<<< HEAD
        else if (options == (int)'5')
=======
        else if (options == (int)'5')// (cekCommand("execute\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Execute(S);
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'6')
=======
        else if (options == (int)'6')//(cekCommand("main\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Main(S);
            mainPhase(S);
            Prep(*S) = false;
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'0')
=======
        else if (options == (int)'9')
        {
            return;
        }

        else if (options == (int)'0')// (cekCommand("info options\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
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
<<<<<<< HEAD
        if (options == (int)'1')
        {
=======
        if (options == (int)'1')// (cekCommand("serve\n"))
        {
            //serve
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
            Serve(S);
            mainPhase(S);
            phasesFlow(S);
        }
            
<<<<<<< HEAD
        else if (options == (int)'2')
=======
        else if (options == (int)'2') //(cekCommand("repair\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Repair(S);
            mainPhase(S);
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'3')
=======
        else if (options == (int)'3')// (cekCommand("detail\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            Detail(S);
            mainPhase(S);
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'4')
=======
        else if (options == (int)'4')// (cekCommand("office\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
        {
            OFFice(S);
            mainPhase(S);
            phasesFlow(S);
        }
            
<<<<<<< HEAD
        else if (options == (int)'5')
        {
=======
        else if (options == (int)'5')// (cekCommand("prepare\n"))
        {
            //prepare
            Prepare(S);
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
            prepPhase(S);
            Prep(*S) = true;
            phasesFlow(S);
        }

<<<<<<< HEAD
        else if (options == (int)'0')
=======
        else if (options == (int)'9')
        {
            return;
        }

        else if (options == (int)'0')// (cekCommand("info options\n"))
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
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
    //TulisMATRIKSW(PetaAddress(*S)); //  buat debug
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
    // TulisMATRIKSW(PetaAddress(*S)); //  buat debug
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
<<<<<<< HEAD
    printf("Daftar antrian [%%d/%%d]:\n");
    //queue
=======
    printf("Daftar antrian [%d/%d]:\n", NBElmtQueue(Antrian(*S)), MaxEl(Antrian(*S)));
    PrintInfo(DataCustomers(*S));   //  buat debug
    printf("\n");  //  buat debug
    PrintPrioQueueChar(Antrian(*S));  //  buat debug
    PrintAntrian(S);
>>>>>>> 5cfa79ab5dd61cf352085529d1ec6a1a41635143
    printf("\n");
    listMenuMainPhase(options);
    isMove = true;
    validateOptions(&options, '1', '5', isMove);
}