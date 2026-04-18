# Customer Support Ticketer
### A Modular C-Based System Using Queue & Graph Data Structures

## Overview
The **Customer Support Ticketer** is a modular C-based project that simulates a basic real-world ticket management system used by customer service teams.

It demonstrates how **linear (Queue)** and **non-linear (Graph)** data structures can be combined to efficiently manage ticket flow, relationships, and service performance tracking.

## Core Functionalities
* Create and manage customer tickets
* Assign tickets to available agents
* Link related tickets using a graph (adjacency matrix)
* Escalate ticket priority
* Display ticket by ID / display all tickets
* Show related tickets
* Mark tickets as resolved
* Perform case-insensitive search to find tickets
* SLA compliance through classification of tickets as **Met** or **Breached** based on SLA thresholds

## Data Structures Used
* **Queue (Linear DS):**
  Manages ticket lifecycle (creation → assignment → resolution)

* **Graph (Non-Linear DS):**
  Represents relationships between related tickets using an adjacency matrix

* **Structures (Structs):**
  Used for defining:
  * Ticket
  * Agent
  * Graph
  * TicketQueue

## Technologies Used
* **Language:** C
* **Compiler:** GCC
* **Environment:** Command-line
* **Concepts:** Queue, Graph (Adjacency Matrix), String Handling, Time Functions

## How to Run
### Compile
```bash
gcc main.c ticket.c graph.c search.c SLA.c -o ticketer
```

### Run
```bash
./ticketer
ticketer.exe 
```

## Sample Menu Interface
```
========= CUSTOMER SUPPORT TICKETER =========

1. Create Ticket  
2. Assign Agent  
3. Link Related Tickets  
4. Escalate Priority  
5. Display Ticket by ID  
6. Display All Tickets  
7. Show Related Tickets  
8. Search by Keyword  
9. Generate SLA Report  
10. Resolve Ticket  
11. Exit
```

## Example Output
```
Enter your choice: 1  
Enter customer name: Alex  
Enter issue: Login error  
Enter priority (1=High, 2=Medium, 3=Low): 1  

Ticket #1 created successfully!  
Ticket #1 added to queue successfully.
```


