#include "player.h"
#include "colors.h"
#include "input.h"
#include "board.h"

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    player* mainPlayer = newPlayer("", 0, 0, true);
    printf("%sWelcome to Craps!%s\n", ANSI_BLUE, ANSI_RESET);
    printf("%sPlease enter your name.%s\n", ANSI_GREEN, ANSI_RESET);
    strcpy(mainPlayer->name, getStringInput(">"));
    system("cls");
    printf("%sHow much cash did you bring?%s\n", ANSI_MAGENTA, ANSI_RESET);
    mainPlayer->cash = getIntInput(">", 1, INT_MAX);
    while (true) {
        printf("%sHow many computers do you want to player against (0-19)%s\n", ANSI_PURPLE, ANSI_RESET);
        const int numOfComputers = getIntInput(">", 0, 19);
        player **computers = malloc(numOfComputers*sizeof(player*));
        for (int i = 0; i < numOfComputers; i++)
            computers[i] = newPlayer(strcpy("Computer #", i), 1500, 0, false);
        printf("%sYou go to another table to play some more craps. Place down the money you want to give in return for chips.%s\n", ANSI_ORANGE, ANSI_RESET);
        printf("%sYou have $%d%s\n", ANSI_CYAN, mainPlayer->cash, ANSI_RESET);
        mainPlayer->chips = getIntInput(">", 1, mainPlayer->cash);
        mainPlayer->cash -= mainPlayer->chips;
        for (int i = 0; i < numOfComputers; i++) {
            computers[i]->chips = computers[i]->cash;
            computers[i]->cash = 0;
        }
        player* shooter = &mainPlayer;
        printf("%sIt is time for the come out roll%s\n", ANSI_PURPLE, ANSI_RESET);
        printf("%sYou pick up two die.%s\n", ANSI_YELLOW, ANSI_RESET);
        printf("%sEnter the amount of chips you want to place down. (You have %d chips)%s\n", ANSI_BLUE, shooter->chips, ANSI_RESET);
        int chipsToPlace = getIntInput(">", 1, mainPlayer->chips);
        printf("%sWhere do you want to place them?%s\n", ANSI_DARK_CYAN, ANSI_RESET);
        printf("%s1: Pass%s\n", ANSI_BROWN, ANSI_RESET);
        printf("%s2: Don't Pass%s\n", ANSI_GREEN, ANSI_RESET);
        int choice = getIntInput(">", 1, 2);
        if (choice == 1)
            shooter->chipsOnPass = chipsToPlace;
        else
            shooter->chipsOnDontPass = chipsToPlace;
    }
    free(mainPlayer);
    return 0;
}