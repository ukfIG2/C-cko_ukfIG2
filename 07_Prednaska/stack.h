#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct TItem {
    int value;
    struct TItem *next;
} TItem;

typedef struct {
    TItem *z;
    size_t n;
} TStack;

extern void init(TStack *s);
extern void push(TStack *s, int value);
extern int pop(TStack *s);
extern int empty(TStack *s);
extern void print(TStack *s);

#endif
