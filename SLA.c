#include <stdio.h>
#include <time.h>
#include "ticket.h"

#define SLA_HIGH    4   
#define SLA_MEDIUM  24                                 
#define SLA_LOW     72  

void generateSLAReport(TicketQueue *q) {
    if (isQueueEmpty(q)) {
        printf("No tickets available.\n");
        return;
    }

    printf("\n=========== SLA COMPLIANCE REPORT ===========\n");
    printf("ID | Priority | Status      | Time Taken (hrs)\n");
    printf("----------------------------------------------\n");

    for (int i = q->front; i <= q->rear; i++) {
        Ticket *t = q->tickets[i];
        if (t->isResolved) {
            double timeTaken = difftime(t->resolvedAt, t->createdAt) / 3600.0;
            int slaLimit;
            if (t->priority == 1) slaLimit = SLA_HIGH;
            else if (t->priority == 2) slaLimit = SLA_MEDIUM;
            else slaLimit = SLA_LOW;

            const char *status = (timeTaken <= slaLimit) ? "Met" : "Breached";
            printf("%2d | %-8d | %-10s | %.2f\n",
                   t->id, t->priority, status, timeTaken);
        }
    }
    printf("----------------------------------------------\n");
}
