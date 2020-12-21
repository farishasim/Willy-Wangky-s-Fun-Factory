#ifndef PHASES_H
#define PHASES_H

#include "../boolean/boolean.h"
#include "../commands/commands.h"
#include "../mechanic/mechanic.h"

void phasesFlow(State *S);

void prepPhase(State *S);

void mainPhase(State *S);

#endif