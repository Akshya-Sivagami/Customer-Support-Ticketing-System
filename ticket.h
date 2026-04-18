#ifndef TICKET_H
#define TICKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TICKETS 100
#define MAX_NAME_LEN 50
#define MAX_ISSUE_LEN 100

// ------------------ STRUCTURES ------------------

// Ticket structure
typedef struct {
    int id;                        // Unique ticket ID
    char customerName[MAX_NAME_LEN];
    char issue[MAX_ISSUE_LEN];
    int priority;                  // 1 = High, 2 = Medium, 3 = Low
    int assignedAgentId;           // -1 if unassigned
    int isResolved;                // 0 = open, 1 = resolved
    time_t createdAt;
    time_t resolvedAt;
} Ticket;

// Agent structure
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int isAvailable;               // 1 = free, 0 = busy
} Agent;

// Queue structure for tickets (linear DS)
typedef struct {
    Ticket *tickets[MAX_TICKETS];
    int front;
    int rear;
} TicketQueue;

// ------------------ FUNCTION DECLARATIONS ------------------

// Queue operations
void initQueue(TicketQueue *q);
int isQueueFull(TicketQueue *q);
int isQueueEmpty(TicketQueue *q);
void enqueue(TicketQueue *q, Ticket *t);
Ticket* dequeue(TicketQueue *q);
void displayQueue(TicketQueue *q);

// Ticket operations
Ticket* createTicket(int id, char *customerName, char *issue, int priority);
void assignAgent(Ticket *t, Agent *a);
void resolveTicket(TicketQueue *q, Agent agents[], int agentCount);
void displayTicket(TicketQueue *q, int id);
void escalatePriority(TicketQueue *q, int ticketId);
void displayAllTickets(TicketQueue *q);

#endif
