#ifndef MAINMENUS_H
#define MAINMENUS_H

#include "state.h"

typedef int optiontype;

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

#endif