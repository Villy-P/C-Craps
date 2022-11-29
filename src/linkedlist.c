#include "linkedlist.h"

struct LinkedList createNewLinkedList() {
    struct LinkedList list;
    list.head = NULL;
    return list;
}

void addToLinkedList(struct LinkedList *list, struct Node *node) {
    if (list->head == NULL) {
        list->head = node;
        return;
    }
    struct Node *current = list->head;
    while (current->next != NULL)
        current = current->next;
    current->next = node;
}