#include "player.h"

struct Player newPlayer(char *name, int cash, int chips, bool isMainPlayer) {
    struct Player p;
    strcpy(p.name, name);
    p.cash = cash;
    p.chips = chips;
    p.isMainPlayer = isMainPlayer;
    p.chipsOnPass = 0;
    p.chipsOnDontPass = 0;
    return p;
}