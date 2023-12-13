#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int start;
    int end;
} TUdalost;

// Comparison function for qsort - by name
int compareByName(const void *a, const void *b) {
    return strcmp(((TUdalost *)a)->name, ((TUdalost *)b)->name);
}

// Comparison function for qsort - by start time
int compareByStartTime(const void *a, const void *b) {
    return ((TUdalost *)a)->start - ((TUdalost *)b)->start;
}

// Comparison function for qsort - by duration
int compareByDuration(const void *a, const void *b) {
    return ((TUdalost *)b)->end - ((TUdalost *)b)->start - (((TUdalost *)a)->end - ((TUdalost *)a)->start);
}

bool overlap(TUdalost event1, TUdalost event2) {
    return (event1.start < event2.end && event1.end > event2.start);
}

void printEvents(TUdalost *events, int size) {
    for (int i = 0; i < size; i++) {
        printf("Event %d: %s (Start: %d, End: %d)\n", i + 1, events[i].name, events[i].start, events[i].end);
    }
    printf("\n");
}

int main() {
    int numEvents;
    printf("Enter the number of events: ");
    scanf("%d", &numEvents);

    // Consume the newline character left in the input buffer
    getchar();

    TUdalost *events = (TUdalost *)malloc(numEvents * sizeof(TUdalost));

    printf("Enter event details (name start end) for each event:\n");
    for (int i = 0; i < numEvents; i++) {
        printf("Event %d:\n", i + 1);

        printf("Name: ");
        fgets(events[i].name, MAX_NAME_LENGTH, stdin);
        events[i].name[strcspn(events[i].name, "\n")] = '\0';  // Remove newline if present

        printf("Start Hour (0-24): ");
        scanf("%d", &events[i].start);

        printf("End Hour (0-24): ");
        scanf("%d", &events[i].end);

        // Consume the newline character left in the input buffer
        getchar();
    }

    // Sort the array of events by name
    qsort(events, numEvents, sizeof(TUdalost), compareByName);
    printf("Sorted by name:\n");
    printEvents(events, numEvents);

    // Sort the array of events by start time
    qsort(events, numEvents, sizeof(TUdalost), compareByStartTime);
    printf("Sorted by start time:\n");
    printEvents(events, numEvents);

    // Sort the array of events by duration
    qsort(events, numEvents, sizeof(TUdalost), compareByDuration);
    printf("Sorted by duration:\n");
    printEvents(events, numEvents);

    // Check for overlap and print overlapping events
    char eventName[MAX_NAME_LENGTH];
    printf("Enter the name of the event to check for overlap: ");
    fgets(eventName, MAX_NAME_LENGTH, stdin);
    eventName[strcspn(eventName, "\n")] = '\0';  // Remove newline if present

    for (int i = 0; i < numEvents; i++) {
        if (strcmp(events[i].name, eventName) == 0) {
            for (int j = 0; j < numEvents; j++) {
                if (i != j && overlap(events[i], events[j])) {
                    printf("Overlap with event %s\n", events[j].name);
                }
            }
            break;
        }
    }

    // Free allocated memory
    free(events);

    return 0;
}
