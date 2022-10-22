#ifndef __C_CRAPS_SRC_PLAYER_H__
#define __C_CRAPS_SRC_PLAYER_H__

#include <stdlib.h>
#include <string.h>

typedef struct Player {
    char name[256];
    int cash;
    int chips;
} player;

player* newPlayer(char *name, int cash, int chips);

void freePlayer(player *p);

#endif