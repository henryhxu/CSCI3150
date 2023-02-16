#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void outprint(int time_x, int time_y, int pid, int arrival_time, int remaining_time);

void scheduler(Process* proc, LinkedQueue** ProcessQueue, int proc_num, int queue_num, int period){
    printf("Process number: %d\n", proc_num);
    for (int i = 0;i < proc_num; i++)
        printf("%d %d %d\n", proc[i].process_id, proc[i].arrival_time, proc[i].execution_time);

    printf("\nQueue number: %d\n", queue_num);
    printf("Period: %d\n", period);

    for (int i = 0;i < queue_num; i++){
        printf("%d %d %d\n", i, ProcessQueue[i]->time_slice, ProcessQueue[i]->allotment_time);
    }

    /*
       Test outprint function, it will output "Time_slot:1-2, pid:3, arrival-time:4, remaining_time:5" to output.log file.
    */
    outprint(1,2,3,4,5);


}

