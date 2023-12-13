#include "stack.h"
#include <stdio.h>

int main() {
    TStack stack;
    init(&stack);

    printf("Is stack empty? %s\n", empty(&stack) ? "Yes" : "No");

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Is stack empty? %s\n", empty(&stack) ? "Yes" : "No");

    printf("Popped value: %d\n", pop(&stack));

    printf("Is stack empty? %s\n", empty(&stack) ? "Yes" : "No");

    print(&stack);

    return 0;
}
