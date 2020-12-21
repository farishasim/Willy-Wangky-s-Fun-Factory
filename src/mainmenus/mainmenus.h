#ifndef MAINMENUS_H
#define MAINMENUS_H

#include "../state/state.h"

typedef int optiontype;

extern char command[20];
extern optiontype options;
extern boolean isName, isLoad, isMove, isPlaying, isInput;
extern State S;

void newGame(State *S);

void saveGame(State S);

void loadGame(State *S);

void Continue(State *S, boolean isLoad, boolean curState, optiontype menu);

void Exit(State S);

void validateOptions(optiontype* menu, char l, char g, boolean isMove);

void inputPName(State* S);

boolean cekCommand(char * command_name);

#endif
