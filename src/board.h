#ifndef __C_CRAPS_SRC_BOARD_H__
#define __C_CRAPS_SRC_BOARD_H__

typedef struct Board {
    int chipsOn;
} board;

void printBoard(board *board);

#endif