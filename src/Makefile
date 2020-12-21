all: header main clean

header: 
	gcc -c commands/commands.c matriks/matriks.c graph/graph.c map/map.c jam/jam.c listcustomer/listcustomer.c listhistory/listhistory.c mainmenus/mainmenus.c material/material.c mechanic/mechanic.c mesinkar/mesinkar.c mesinkata/mesinkata.c phases/phases.c point/point.c prioqueuechar/prioqueuechar.c stackt/stackt.c state/state.c treewahana/treewahana.c wahana/wahana.c

main:
	gcc -o willygame willygame.c mainmenus.o matriks.o point.o map.o commands.o phases.o jam.o mesinkata.o mesinkar.o state.o mechanic.o listcustomer.o prioqueuechar.o wahana.o stackt.o listhistory.o treewahana.o graph.o

clean: 
	rm -rf *.o