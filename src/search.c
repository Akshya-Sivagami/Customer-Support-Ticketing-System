#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "search.h"

// Helper function to convert string to lowercase (for case-insensitive search)
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Search tickets by keyword in customer name or issue description
void searchTicketsByKeyword(TicketQueue *q, const char *keyword) {
    if (isQueueEmpty(q)) {
        printf("No tickets available.\n");
        return;
    }

    char lowerKeyword[100];
    strcpy(lowerKeyword, keyword);
    toLowerCase(lowerKeyword);

    int found = 0;
    printf("\n=========== SEARCH RESULTS ===========\n");

    for (int i = q->front; i <= q->rear; i++) {
        Ticket *t = q->tickets[i];
        char nameCopy[MAX_NAME_LEN];
        char issueCopy[MAX_ISSUE_LEN];

        strcpy(nameCopy, t->customerName);
        strcpy(issueCopy, t->issue);

        toLowerCase(nameCopy);
        toLowerCase(issueCopy);

        if (strstr(nameCopy, lowerKeyword) || strstr(issueCopy, lowerKeyword)) {
            printf("\nTicket ID: %d\n", t->id);
            printf("Customer: %s\n", t->customerName);
            printf("Issue: %s\n", t->issue);
            printf("Priority: %d\n", t->priority);
            printf("Resolved: %s\n", t->isResolved ? "Yes" : "No");
            found = 1;
        }
    }

    if (!found) {
        printf("No tickets found matching keyword: \"%s\"\n", keyword);
    }

    printf("======================================\n");
}
