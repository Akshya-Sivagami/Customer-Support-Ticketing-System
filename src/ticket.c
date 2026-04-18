#include "ticket.h"


void initQueue(TicketQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueFull(TicketQueue *q) {
    return q->rear == MAX_TICKETS - 1;
}

int isQueueEmpty(TicketQueue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(TicketQueue *q, Ticket *t) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot add more tickets.\n");
        return;
    }

    if (isQueueEmpty(q)) {
        q->front = 0;
    }

    q->rear++;
    q->tickets[q->rear] = t;
    printf("Ticket #%d added to queue successfully.\n", t->id);
}

Ticket* dequeue(TicketQueue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty.\n");
        return NULL;
    }

    Ticket *temp = q->tickets[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    return temp;
}

// ------------------ TICKET OPERATIONS ------------------

Ticket* createTicket(int id, char *customerName, char *issue, int priority) {
    Ticket *t = (Ticket*) malloc(sizeof(Ticket));

    if (!t) {
        printf("Memory allocation failed for ticket.\n");
        exit(1);
    }

    t->id = id;
    strcpy(t->customerName, customerName);
    strcpy(t->issue, issue);
    t->priority = priority;
    t->assignedAgentId = -1; // unassigned initially
    t->isResolved = 0;       // all are open initially
    t->createdAt = time(NULL);

    printf("Ticket #%d created successfully!\n", t->id);
    return t;
}

void assignAgent(Ticket *t, Agent *a) {
    if (!a->isAvailable) {
        printf("Agent %s is currently busy.\n", a->name);
        return;
    }

    t->assignedAgentId = a->id;
    a->isAvailable = 0;
    printf("Agent %s assigned to Ticket #%d successfully.\n", a->name, t->id);
}

void resolveTicket(TicketQueue *q, Agent *agents, int numAgents) {
    if (isQueueEmpty(q)) {
        printf("No tickets available.\n");
        return;
    }

    int id;
    printf("Enter Ticket ID to resolve: ");
    scanf("%d", &id);

    for (int i = q->front; i <= q->rear; i++) {
        if (q->tickets[i]->id == id) {
            Ticket *t = q->tickets[i];

            if (t->isResolved) {
                printf("Ticket %d is already resolved.\n", id);
                return;
            }

            // Mark resolved
            t->isResolved = 1;
            q->tickets[i]->resolvedAt = time(NULL);
            printf("Ticket %d marked as resolved.\n", id);

            // Free up the agent if assigned
            if (t->assignedAgentId != -1) {
                for (int j = 0; j < numAgents; j++) {
                    if (agents[j].id == t->assignedAgentId) {
                        agents[j].isAvailable = 1;
                        printf("Agent %s is now available.\n", agents[j].name);
                        break;
                    }
                }
            }
            return;
        }
    }

    printf("Ticket with ID %d not found.\n", id);
}

void escalatePriority(TicketQueue *q, int ticketId) {
    if (isQueueEmpty(q)) {
        printf("No tickets in the queue.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        if (q->tickets[i]->id == ticketId) {
            if (q->tickets[i]->priority == 1) {
                printf("Ticket #%d is already at highest priority.\n", ticketId);
                return;
            }
            q->tickets[i]->priority--;
            printf("Ticket #%d priority escalated successfully.\n", ticketId);
            return;
        }
    }

    printf("Ticket with ID %d not found.\n", ticketId);
}

void displayTicket(TicketQueue *q, int id) {
    if (isQueueEmpty(q)) {
        printf("No tickets to display.\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++) {
        if (q->tickets[i]->id == id) {
            Ticket *t = q->tickets[i];
            char agentStr[10];
            if (t->assignedAgentId == -1)
                strcpy(agentStr, "-");
            else
                sprintf(agentStr, "%d", t->assignedAgentId);

            printf("\n--- Ticket Details ---\n");
            printf("Ticket ID: %d\n", t->id);
            printf("Customer Name: %s\n", t->customerName);
            printf("Issue: %s\n", t->issue);
            printf("Priority: %d\n", t->priority);
            printf("Agent ID: %s\n", agentStr);
            printf("Status: %s\n", t->isResolved ? "Resolved" : "Open");
            return;
        }
    }

    printf("Ticket with ID %d not found.\n", id);
}

void displayAllTickets(TicketQueue *q) {
    if (isQueueEmpty(q)) {
        printf("No tickets to display.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("ID | Customer       | Priority | AgentID | Status\n");
    printf("-------------------------------------------------\n");

    for (int i = q->front; i <= q->rear; i++) {
        Ticket *t = q->tickets[i];
        char agentStr[10];

        if (t->assignedAgentId == -1)
            strcpy(agentStr, "---");
        else
            sprintf(agentStr, "%d", t->assignedAgentId);

        printf("%2d | %-13s | %-8d | %-7s | %-8s\n",
               t->id,
               t->customerName,
               t->priority,
               agentStr,
               t->isResolved ? "Resolved" : "Open");
    }
    printf("-------------------------------------------------\n");
}
