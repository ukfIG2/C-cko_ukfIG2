#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void init(TStack *s) {
    s->z = NULL;
    s->n = 0;
}

static TItem *createItem(int value, TItem *next) {
    TItem *v = (TItem *)malloc(sizeof(TItem));

    if (v == NULL) {
        printf("malo pamati !\n");
        exit(1);
    }

    v->value = value;
    v->next = next;

    return v;
}

void push(TStack *s, int value) {
    s->z = createItem(value, s->z);
    s->n++;
}

int pop(TStack *s) {
    if (empty(s)) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }

    int h = s->z->value;

    TItem *v = s->z;
    s->z = s->z->next;
    free(v);

    s->n--;

    return h;
}

int empty(TStack *s) {
    return s->n == 0;
}

void print(TStack *s) {
    if (empty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack contents: ");
    TItem *current = s->z;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}
