#include "node.h"

struct Node *newNode(struct Player *player) {
    struct Node *node = malloc(sizeof(struct Node));
    node->player = player;
    node->next = NULL;
    return node;
}