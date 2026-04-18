#include <stdio.h>
#include "ticket.h"
#include "graph.h"
#include "sla.h"
#include "search.h"

int main() {
    TicketQueue queue;
    initQueue(&queue);

    Graph g;
    int ticketCount = 0;
    initGraph(&g, MAX_TICKETS);

    // Random agents
    Agent agents[3] = {
        {101, "Rahul", 1},
        {102, "Meera", 1},
        {103, "Arjun", 1}
    };

    int choice;

    do {
        printf("\n========= CUSTOMER SUPPORT TICKETER =========\n");
        printf("1. Create Ticket\n");
        printf("2. Assign Agent\n");
        printf("3. Link Related Tickets\n");
        printf("4. Escalate Priority\n");
        printf("5. Display Ticket by ID\n");
        printf("6. Display All Tickets\n");
        printf("7. Show Related Tickets\n");
        printf("8. Resolve Ticket\n");
        printf("9. Exit\n");
        printf("10. Generate SLA report\n");
        printf("11. Search Tickets by Keyword\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // newline

        if (choice == 1) {
            char name[MAX_NAME_LEN], issue[MAX_ISSUE_LEN];
            int priority;

            printf("Enter customer name: ");
            fgets(name, MAX_NAME_LEN, stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Enter issue: ");
            fgets(issue, MAX_ISSUE_LEN, stdin);
            issue[strcspn(issue, "\n")] = '\0';

            printf("Enter priority (1=High, 2=Medium, 3=Low): ");
            scanf("%d", &priority);

            Ticket *t = createTicket(ticketCount + 1, name, issue, priority);
            enqueue(&queue, t);
            ticketCount++;
        }

        else if (choice == 2) {
            int tId, aId;
            printf("Enter Ticket ID: ");
            scanf("%d", &tId);
            printf("Enter Agent ID (101-Rahul, 102-Meera, 103-Arjun): ");
            scanf("%d", &aId);

            Ticket *ticket = NULL;
            for (int i = queue.front; i <= queue.rear; i++) {
                if (queue.tickets[i]->id == tId) {
                    ticket = queue.tickets[i];
                    break;
                }
            }

            if (!ticket) {
                printf("Ticket not found.\n");
                continue;
            }

            Agent *selectedAgent = NULL;
            for (int i = 0; i < 3; i++) {
                if (agents[i].id == aId) {
                    selectedAgent = &agents[i];
                    break;
                }
            }

            if (!selectedAgent) {
                printf("Invalid agent ID.\n");
                continue;
            }

            assignAgent(ticket, selectedAgent);
        }

        else if (choice == 3) {
            int t1, t2;
            printf("Enter Ticket IDs to link (e.g. 1 2): ");
            scanf("%d %d", &t1, &t2);
            addLink(&g, t1, t2);
        }

        else if (choice == 4) {
            int tId;
            printf("Enter Ticket ID to escalate: ");
            scanf("%d", &tId);
            escalatePriority(&queue, tId);
        }

        else if (choice == 5) {
            int id;
            printf("Enter Ticket ID to view details: ");
            scanf("%d", &id);
            displayTicket(&queue, id);
        }

        else if (choice == 6) {
            displayAllTickets(&queue);
        }

        else if (choice == 7) {
            int tId;
            printf("Enter Ticket ID to view related tickets: ");
            scanf("%d", &tId);
            showRelatedTickets(&g, tId);
        }

        else if (choice == 8) {
            // Pass agents list to update availability on resolve
            resolveTicket(&queue, agents, 3);
        }

        else if (choice == 9) {
            printf("Exiting program...\n");
        }

        else if (choice == 10) {
            generateSLAReport(&queue);
        }

        else if (choice == 11) {
            char keyword[100];
            printf("Enter keyword to search: ");
            getchar(); // clear leftover newline if needed
            fgets(keyword, sizeof(keyword), stdin);
            keyword[strcspn(keyword, "\n")] = '\0';
            searchTicketsByKeyword(&queue, keyword);
}

        else {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 9);

    return 0;
}
