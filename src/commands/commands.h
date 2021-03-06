/*Himpunan beberapa fungsi yang masing-masingnya menampilkan pilihan-pilihan menu/perintah selama runtime*/

#ifndef COMMANDS_H
#define COMMANDS_H

#include "../mainmenus/mainmenus.h"

void listMenu(optiontype menu);

void listMenuPrepPhase(optiontype menu);

void listMenuMainPhase(optiontype menu);

void chooseState(optiontype options);

void inputManual(State *S);
/*luas, buka, tutup, antrian, office, curTime*/

void inputManualCoba2(State * S);

void inputManualPeta(Map * peta, Map_wahana * petaAddress, boolean isInput);

#endif