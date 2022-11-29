#include "player.h"
#include "colors.h"
#include "input.h"
#include "board.h"

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    player* mainPlayer = newPlayer("", 0, 0);
    board* board;
    printf("%sWelcome to Craps!%s\n", ANSI_BLUE, ANSI_RESET);
    printf("%sPlease enter your name.%s\n", ANSI_GREEN, ANSI_RESET);
    strcpy(mainPlayer->name, getStringInput(">"));
    system("cls");
    printf("%sHow much cash did you bring?%s\n", ANSI_MAGENTA, ANSI_RESET);
    mainPlayer->cash = getIntInput(">", 1, INT_MAX); 
    while (true) {
        printf("%sYou go to another table to play some more craps. Place down the money you want to give in return for chips.%s\n", ANSI_ORANGE, ANSI_RESET);
        printf("%sYou have $%d%s\n", ANSI_CYAN, mainPlayer->cash, ANSI_RESET);
        mainPlayer->chips = getIntInput(">", 1, mainPlayer->cash);
        mainPlayer->cash -= mainPlayer->chips;
        printBoard(board);
    }
    free(mainPlayer);
    free(board);
    return 0;
}