#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef LinkedList LinkedQueue;

/*You could use these helper function and create some cutomized function in the scheduler-impl.c file.*/
/*Scheduler-impl.c is the only file you could modify.*/

LinkedQueue* InitQueue(int time_slice);
int IsEmptyQueue(LinkedQueue* LQueue);
int Length(LinkedQueue* LQueue);
LinkedQueue* EnQueue(LinkedQueue* LQueue, Process proc);
Process DeQueue(LinkedQueue* LQueue);
LinkedQueue* FrontQueue(LinkedQueue* LQueue);
void QueuePrint(LinkedQueue* LQueue);

#endif