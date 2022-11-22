#ifndef __C_CRAPS_SRC_PLAYER_H__
#define __C_CRAPS_SRC_PLAYER_H__

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Player {
    char name[256];
    int cash;
    int chips;
    bool isMainPlayer;
    int chipsOnPass;
    int chipsOnDontPass;
} player;

player* newPlayer(char *name, int cash, int chips, bool isMainPlayer);

#endif