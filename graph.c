#include "graph.h"

void initGraph(Graph *g, int numTickets) {
    g->numTickets = numTickets;

    for (int i = 0; i < numTickets; i++) {
        for (int j = 0; j < numTickets; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addLink(Graph *g, int t1, int t2) {
    // Adjusting because our ticket IDs start from 1 (not 0)
    t1--; 
    t2--;

    if (t1 < 0 || t1 >= g->numTickets || t2 < 0 || t2 >= g->numTickets) {
        printf("Invalid ticket IDs.\n");
        return;
    }

    g->adjMatrix[t1][t2] = 1;
    g->adjMatrix[t2][t1] = 1; // undirected
    printf("Ticket #%d and Ticket #%d linked successfully.\n", t1 + 1, t2 + 1);
}

void showRelatedTickets(Graph *g, int ticketId) {
    ticketId--;

    if (ticketId < 0 || ticketId >= g->numTickets) {
        printf("Invalid Ticket ID.\n");
        return;
    }

    printf("\nTickets related to #%d: ", ticketId + 1);
    int hasRelated = 0;

    for (int j = 0; j < g->numTickets; j++) {
        if (g->adjMatrix[ticketId][j] == 1) {
            printf("%d ", j + 1);  // print as 1-based ID
            hasRelated = 1;
        }
    }

    if (!hasRelated)
        printf("None");
    printf("\n");
    return;
}
