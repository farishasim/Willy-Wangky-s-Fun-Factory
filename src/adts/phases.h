#ifndef PHASES_H
#define PHASES_H

#include "boolean.h"
#include "commands.h"
#include "mechanic.h"

void phasesFlow(State *S);

void prepPhase(State *S);

void mainPhase(State *S);

#endif