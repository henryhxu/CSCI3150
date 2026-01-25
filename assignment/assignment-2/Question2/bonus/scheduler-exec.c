#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Process* proc_tmp; // Used to temporarily store the input process.

// Make sure that process.file and queue.cfg are in the same directory as your code.
int ReadProcessFile(); // Return the number of process in process.file, all the processes are stored in proc.
int min(int x, int y); // Return the less one between x and y.
Process MinProc(Process x, Process y); // Return the process arrive earlier; if arrive at the same time, return the one have less pid.
void SortProcess(Process* p, int num); // Sort proc arrording to both arrival_time and pid 

int GetQueueNum(); // Return the number of queue in queue.cfg.
int GetPeriod(); // Return the value of Period_S in queue.cfg.
void ReadQueueCfg(LinkedQueue** LQueue, int num); // Store queues into LQueue.

void InitOutputFile(); // Create void output.log file.
void outprint(int time_x, int time_y, int pid, int arrival_time, int remaining_time); // Print one line to output.log file.

void scheduler(Process* proc, LinkedQueue** ProcessQueue, int proc_num, int queue_num, int period);

int main(){
    /* 
       Following codes will read and sort processes from process.file,
       and store the sorted processes into array proc[].
    */
    int proc_num = ReadProcessFile();
    Process proc[proc_num];
    for (int i = 0;i < proc_num; i++){
        proc[i].process_id = proc_tmp[i].process_id;
        proc[i].arrival_time = proc_tmp[i].arrival_time;
        proc[i].execution_time = proc_tmp[i].execution_time;
    }
    SortProcess(proc, proc_num);

    /* 
       Following codes will read queues from queue.cfg, and store them into ProcessQueue.
    */
    int queue_num = GetQueueNum();
    int period = GetPeriod();
    LinkedQueue** ProcessQueue = (LinkedQueue**)malloc(sizeof(LinkedQueue*) * queue_num);
    ReadQueueCfg(ProcessQueue, queue_num);

    /* 
       Initiate output.log file.
    */
    InitOutputFile();

    //Call scheduler() here.
    scheduler(proc, ProcessQueue, proc_num, queue_num, period);

    return 0;
}

int ReadProcessFile(){
    int ProcessNum = 0;
    FILE* process_file = fopen("./process.file", "r");
    char chache_line[1000];
    int LineNum = 0;
    while (!feof(process_file)){
        fgets(chache_line, 1000, process_file);
        char* pch = strtok(chache_line, " ,:");
        if (LineNum == 0){
            int i = 0;
            while (pch != NULL){
                if (i == 1){
                    ProcessNum = atoi(pch);
                    proc_tmp = (Process*)malloc(ProcessNum * sizeof(Process));
                }
                pch = strtok(NULL, " ,:");
                i++;
            }
        }else{
            int i = 0;
            while (pch != NULL){
                if (i == 1){
                    proc_tmp[LineNum-1].process_id = atoi(pch);
                }else if (i == 3){
                    proc_tmp[LineNum-1].arrival_time = atoi(pch);
                }else if (i == 5){
                    proc_tmp[LineNum-1].execution_time = atoi(pch);
                }
                pch = strtok(NULL, " ,:");
                i++;
            }
        }
        LineNum++;
    }
    fclose(process_file);
    return ProcessNum;
}

int GetQueueNum(){
    int QueueNum = 0;
    FILE* queue_file = fopen("./queue.cfg", "r");
    char chache_line[1000];
    int LineNum = 0;
    while (!feof(queue_file)){
        fgets(chache_line, 1000, queue_file);
        char* pch = strtok(chache_line, " ,:");
        if (LineNum == 0){
            int i = 0;
            while (pch != NULL){
                if (i == 1){
                    QueueNum = atoi(pch);
                    break;
                }
                pch = strtok(NULL, " ,:");
                i++;
            }
            break;
        }
    }
    fclose(queue_file);
    return QueueNum;          
}

int GetPeriod(){
    int Period = 0;
    FILE* queue_file = fopen("./queue.cfg", "r");
    char chache_line[1000];
    int LineNum = 0;
    while (!feof(queue_file)){
        fgets(chache_line, 1000, queue_file);
        char* pch = strtok(chache_line, " ,:");
        if (LineNum == 1){
            int i = 0;
            while (pch != NULL){
                if (i == 1){
                    Period = atoi(pch);
                    break;
                }
                pch = strtok(NULL, " ,:");
                i++;
            }
            break;
        }
        LineNum ++;
    }
    fclose(queue_file);
    return Period;          
}

void ReadQueueCfg(LinkedQueue** LQueue, int num){
    int QueueNum = num;
    FILE* queue_file = fopen("./queue.cfg", "r");
    char chache_line[1000];
    int LineNum = 0;
    for (int i=0;i<QueueNum;i++){
        LQueue[i] = (LinkedQueue*)malloc(sizeof(LinkedQueue));
        LQueue[i] -> next = NULL;
    }
    while (!feof(queue_file)){
        fgets(chache_line, 1000, queue_file);
        char* pch = strtok(chache_line, " ,:");
        if (LineNum == 0 || LineNum == 1){
            while (pch != NULL){
                pch=strtok(NULL, " ,:");
            }
        }else if (LineNum != 0){
            int i = 0;
            while (pch != NULL){
                if (i == 1){
                    LQueue[QueueNum-LineNum+1]->time_slice = atoi(pch);
                } else if (i == 3){
                    LQueue[QueueNum-LineNum+1]->allotment_time = atoi(pch);
                }
                pch = strtok(NULL, " ,:");
                i++;
            }
        }
        LineNum++;
    }
    fclose(queue_file);
}

int min(int x, int y){
    return x < y ? x : y;
}

Process MinProc(Process x, Process y){
    Process min_proc;
    if (x.arrival_time < y.arrival_time)
        min_proc = x;
    else if (x.arrival_time == y.arrival_time){
        if (x.process_id < y.process_id)
            min_proc = x;
        else if (x.process_id > y.process_id)
            min_proc = y;
    }else if (x.arrival_time > y.arrival_time)
        min_proc = y;
    return min_proc;
}

void SortProcess(Process* p, int num){
    Process* a = p;
    Process* b = (Process*)malloc(num * sizeof(Process));
    int seg, start;
    for (seg = 1; seg < num; seg += seg) {
        for (start = 0; start < num; start += seg + seg) {
            int low = start, mid = min(start + seg, num), high = min(start + seg + seg, num);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            // printf("------------4\n");
            while (start1 < end1 && start2 < end2){
                Process minproc = MinProc(a[start1], a[start2]);
                if (minproc.process_id == a[start1].process_id)
                    b[k++] = a[start1++];
                else 
                    b[k++] = a[start2++];
            }
                // b[k++] = MinProc(a[start1], a[start2]);
            // printf("------------5\n");
            while (start1 < end1)
                b[k++] = a[start1++];
            // printf("------------6\n");
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        Process* tmp = a;
        a = b;
        b = tmp;
    }
    if (a != p) {
        int i;
        for (i = 0; i < num; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}

void InitOutputFile(){
    FILE* outputfile = fopen("./output.log", "w");
    fclose(outputfile);
}

void outprint(int time_x, int time_y, int pid, int arrival_time, int remaining_time){
    FILE* outputfile = fopen("./output.log", "a");
    fprintf(outputfile, "Time_slot:%d-%d, pid:%d, arrival-time:%d, remaining_time:%d\n",\
            time_x, time_y, pid, arrival_time, remaining_time);
    fclose(outputfile);          
}