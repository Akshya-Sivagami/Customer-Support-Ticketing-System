#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TICKETS 100

// Graph structure (Adjacency Matrix)
typedef struct {
    int adjMatrix[MAX_TICKETS][MAX_TICKETS]; // 1 = linked, 0 = not linked
    int numTickets;                          // how many tickets exist
} Graph;

// Function declarations
void initGraph(Graph *g, int numTickets);
void addLink(Graph *g, int t1, int t2);
void showRelatedTickets(Graph *g, int ticketId);

#endif
