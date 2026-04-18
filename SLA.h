// sla.h
#ifndef SLA_H
#define SLA_H

#include "ticket.h"

void markTicketResolvedWithSLA(TicketQueue *q);
void generateSLAReport(TicketQueue *q);

#endif
