#include "player.h"
#include "colors.h"
#include "input.h"

#include <limits.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    player* mainPlayer = newPlayer("", 0, 0);
    printf("%sWelcome to Craps!%s\n", ANSI_BLUE, ANSI_RESET);
    printf("%sPlease enter your name.%s\n", ANSI_GREEN, ANSI_RESET);
    strcpy(mainPlayer->name, getStringInput(">"));
    system("cls");
    printf("%sHow much cash did you bring?%s\n", ANSI_MAGENTA, ANSI_RESET);
    mainPlayer->cash = getIntInput(">", 1, INT_MAX);
    freePlayer(mainPlayer);
    return 0;
}