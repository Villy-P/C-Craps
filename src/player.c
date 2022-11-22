#include "player.h"

player* newPlayer(char *name, int cash, int chips, bool isMainPlayer) {
    player* p = (player*) malloc(sizeof(player));
    if (p) {
        strcpy(p->name, name);
        p->cash = cash;
        p->chips = chips;
        p->isMainPlayer = isMainPlayer;
        p->chipsOnPass = 0;
        p->chipsOnDontPass = 0;
    }
    return p;
}