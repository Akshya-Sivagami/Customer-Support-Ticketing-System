**A Modular C-Based System Using Queue & Graph Data Structures**

## Overview
The Customer Support Ticketer is a simple modular C project that simulates a very basic real world ticket management system for customer service teams. It demonstrates how linear (Queue) and non-linear (Graph) data structures can be integrated to manage ticket flow and relationships between them efficiently.

## Core functionalities
1. Creating and managing customer tickets.
2. Assigning tickets to available agents.
3. Linking related tickets using a graph (adjacency matrix).
4. Escalating ticket priority.
5. Displaying Ticket(s).
6. Showing related tickets
7. Marking tickets as resolved.

## Data Structures Used
1. Queue (Linear DS): Manages ticket flow (creation, assignment, resolution).
2. Graph (Non-Linear DS): Represents relationships between related tickets using an adjacency matrix.
3. Structures (Structs): Used for defining `Ticket`, `Agent`, `Graph`, and `TicketQueue`.

## Technologies Used
1. Language: C  
2. Compiler: GCC  
3. Environment: Command-line 
4. Data Structures: Queue, Graph (Adjacency Matrix) 

## How to Run (Windows)
bash
```
gcc main.c ticket.c graph.c -o ticketer
ticketer.exe
```
## Sample Menu Interface
========= CUSTOMER SUPPORT TICKETER =========
1. Create Ticket
2. Assign Agent
3. Link Related Tickets
4. Escalate Priority
5. Display Ticket by ID
6. Display All Tickets
7. Show Related Tickets
8. Resolve Ticket
9. Exit

## Example Output
Enter your choice: 1
Enter customer name: Name
Enter issue: login error
Enter priority (1=High, 2=Medium, 3=Low): 1
Ticket #1 created successfully!
Ticket #1 added to queue successfully.