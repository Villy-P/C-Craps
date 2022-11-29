#include "player.h"
#include "colors.h"
#include "input.h"
#include "board.h"
#include "linkedlist.h"
#include "node.h"
#include "random.h"

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    struct Player mainPlayer = newPlayer("", 0, 0, true);
    printf("%sWelcome to Craps!%s\n", ANSI_BLUE, ANSI_RESET);
    printf("%sPlease enter your name.%s\n", ANSI_GREEN, ANSI_RESET);
    strcpy(mainPlayer.name, getStringInput(">"));
    system("cls");
    printf("%sHow much cash did you bring?%s\n", ANSI_MAGENTA, ANSI_RESET);
    mainPlayer.cash = getIntInput(">", 1, INT_MAX); 
    while (true) {
        printf("%sHow many computers do you want to play against? (0-19)%s\n", ANSI_PURPLE, ANSI_RESET);
        const int numOfComputers = getIntInput(">", 0, 19);
        struct LinkedList computers = createNewLinkedList();
        for (int i = 0; i < numOfComputers; i++) {
            char computerHashtag[] = "Computer #";
            char iAsString[2];
            sprintf(iAsString, "%d", i);
            char *computerName = strcpy(computerHashtag, iAsString);
            struct Player computer = newPlayer(computerName, 0, 1500, false);
            struct Node *computerNode = newNode(&computer);
            addToLinkedList(&computers, computerNode);
        }
        printf("%sYou go to another table to play some more craps. Place down the money you want to give in return for chips.%s\n", ANSI_ORANGE, ANSI_RESET);
        printf("%sYou have $%d%s\n", ANSI_CYAN, mainPlayer.cash, ANSI_RESET);
        mainPlayer.chips = getIntInput(">", 1, mainPlayer.cash);
        mainPlayer.cash -= mainPlayer.chips;
        struct Player* shooter = &mainPlayer;
        printf("%sIt is time for the come out roll%s\n", ANSI_PURPLE, ANSI_RESET);
        printf("%sThe stickman passes you five die.%s\n", ANSI_BLUE, ANSI_RESET);
        printf("%sYou pick up two die.%s\n", ANSI_YELLOW, ANSI_RESET);
        printf("%sEnter the amount of chips you want to place down. (You have %d chips)%s\n", ANSI_BLUE, shooter->chips, ANSI_RESET);
        int chipsToPlace = getIntInput(">", 1, mainPlayer.chips);
        printf("%sWhere do you want to place them?%s\n", ANSI_DARK_CYAN, ANSI_RESET);
        printf("%s1: Pass%s\n", ANSI_BROWN, ANSI_RESET);
        printf("%s2: Don't Pass%s\n", ANSI_GREEN, ANSI_RESET);
        int choice = getIntInput(">", 1, 2);
        if (choice == 1)
            mainPlayer.chipsOnPass = chipsToPlace;
        else
            mainPlayer.chipsOnDontPass = chipsToPlace;
        printf("%sThe computers will now place their bets.%s\n", ANSI_DARK_CYAN, ANSI_RESET);
        struct Node *currentComputer = computers.head;
        while (currentComputer != NULL) {
            int randomValue = randomInRange(0, 10);
            int chipsToPlaceDown = randomInRange(250, 750);
            if (randomValue <= 5) { // Bet on pass
                printf("%s%s placed %d $1 chips on the pass line.%s\n", ANSI_BLUE, currentComputer->player->name, chipsToPlaceDown, ANSI_RESET);
                currentComputer->player->chips -= chipsToPlaceDown;
                currentComputer->player->chipsOnPass = chipsToPlaceDown;
            } else if (randomValue <= 8) { // Bet on dont pass
                printf("%s%s placed %d $1 chips on the don't pass line.%s\n", ANSI_BLUE, currentComputer->player->name, chipsToPlaceDown, ANSI_RESET);
                currentComputer->player->chips -= chipsToPlaceDown;
                currentComputer->player->chipsOnDontPass = chipsToPlaceDown;
            } else {
                printf("%s%s did not place any chips down.%s\n", ANSI_BLUE, currentComputer->player->name, ANSI_RESET);
            }
            currentComputer = currentComputer->next;
        }
        unsigned int firstRoll = randomInRange(1, 6);
        unsigned int secondRoll = randomInRange(1, 6);
        printf("%s%s rolls the die...%s\n", ANSI_BLUE, shooter->name, ANSI_RESET);
        printf("%sThe die hit the back table...%s\n", ANSI_GREEN, ANSI_RESET);
        printf("%s+---+ +---+%s", ANSI_ORANGE, ANSI_RESET);
        printf("%s+ %d + + %d +%s");
    }
    return 0;
}