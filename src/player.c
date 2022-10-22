#include "player.h"

player* newPlayer(char *name, int cash, int chips) {
    player* p = (player*) malloc(sizeof(player));
    if (p) {
        strcpy(p->name, name);
        p->cash = cash;
        p->chips = chips;
    }
    return p;
}