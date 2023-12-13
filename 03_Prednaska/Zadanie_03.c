#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[50];
    int startHour;
    int endHour;
} TUdalost;

bool overlap(TUdalost event1, TUdalost event2) {
    return (event1.startHour < event2.endHour && event1.endHour > event2.startHour);
}


int compareByName(const void *a, const void *b) {
    return strcmp(((TUdalost*)a)->name, ((TUdalost*)b)->name);
}

int compareByStartHour(const void *a, const void *b) {
    return ((TUdalost*)a)->startHour - ((TUdalost*)b)->startHour;
}

int compareByDuration(const void *a, const void *b) {
    return (((TUdalost*)b)->endHour - ((TUdalost*)b)->startHour) - (((TUdalost*)a)->endHour - ((TUdalost*)a)->startHour);
}

int main() {
    int numEvents;
    printf("Enter the number of events: ");
    scanf("%d", &numEvents);

    TUdalost *events = (TUdalost *)malloc(numEvents * sizeof(TUdalost));

    printf("Enter details for each event:\n");
    for (int i = 0; i < numEvents; i++) {
    }

    qsort(events, numEvents, sizeof(TUdalost), compareByName);

    printf("\nSorted by name:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("Event %d: %s\n", i + 1, events[i].name);
    }

    qsort(events, numEvents, sizeof(TUdalost), compareByStartHour);

    printf("\nSorted by start hour:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("Event %d: %s\n", i + 1, events[i].name);
    }

    qsort(events, numEvents, sizeof(TUdalost), compareByDuration);

    printf("\nSorted by duration:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("Event %d: %s\n", i + 1, events[i].name);
    }

    free(events);

    return 0;
}
