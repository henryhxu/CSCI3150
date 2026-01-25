# Question 2: Multi-Level Feedback Queue (40 Marks + 10 Bonus)

## Introduction

Question 2 is divied into two sub-questions. Sub-question 1 is worth 40 points and you need to understand the MLFQ algorithm and fill in the scheduling result table. Sub-question 2 is worth 10 bonus and you need to implement a MLFQ in C.

## Sub-question 1 (40 Marks)

Given the following MFLQ scheduling information below, fill in the blanks of the scheduling result table (`Question2/answer.md`).

### Rule

1. If Priority($A$) > Priority($B$), $A$ runs ($B$ doesn’t). 
2. If Priority($A$) = Priority($B$), $A$ & $B$ run in round-robin fashion using the time slice (quantum length) of the given queue.
3. When a job enters the system, it is placed at the highest priority (the topmost queue). For the jobs arriving at the same time, schedule the job with ***smallest*** pid first. 
4. Once a job uses up its time allotment at a given level (regardless of how many  times it has given up the CPU), its priority is reduced (i.e., it moves down one queue and will be at the tail of the target queue, which means it will be scheduled last).
5. After some time period S, move all the jobs in the system to the topmost queue, and sort all the jobs by pid. The job with the ***smallest*** pid will be scheduled first.

Note: Sorting will happen every time it arrives the `Period_S`.

### Process information
- `ProcessNum`: 5
- `pid`:31, `arrival_time`:5, `execution_time`:120
- `pid`:87, `arrival_time`:5, `execution_time`:106
- `pid`:152, `arrival_time`:68, `execution_time`:130
- `pid`:246, `arrival_time`:165, `execution_time`:86
- `pid`:389, `arrival_time`:398, `execution_time`:76

### Queue information
- `QueueNum`: 3
- `Period_S`: 380
- `Time_Slice_Q3`: 10, `Allotmenttime_Q3`: 30 (the highest priority)
- `Time_Slice_Q2`: 45, `Allotmenttime_Q2`: 90
- `Time_Slice_Q1`: 55, `Allotmenttime_Q1`: 110 (the lowest priority)

### Instructions

Fill in the table `Question2/answer.md` by referring to the first three rows given in the table.

### Hint

You could refer to the last row of the table to verify your answer to some extent.

### Grading

Sub-question 1 will be graded based on your `answer.md`.

## Sub-question 2 (10 Bonus)

Implement the MLFQ in C. Specifically, your are only required to revise the function `void scheduler(Process* proc, LinkedQueue** ProcessQueue, int proc_num, int queue_num, int period)` body in `Question2/bonus/scheduler-impl.c` according to the following information.

### Rule
Scheduling rules are the same as sub-question 1.

The inputs of your program: `process.file` and `queue.cfg`.

`process.file` contains the process information and its format is as follows:
```
ProcessNum N
pid:X1, arrival_time:X11, execution_time:X12
pid:X2, arrival_time:X21, execution_time:X22
…
pid:XN, arrival_time:XN1, execution_time:XN2
```
Here, the first line denotes there are `N` processes to be scheduled (there is at least one space character 
between `ProcessNum` and `N`), and from the second line to the (`N+1`)th line, each shows the pid (process 
id), arrival time and execution time of a process with the format like `pid:X1, arrival_time:X11, 
execution_time:X12` (separated by `,`). To make it simple, you can assume that all pids are different. 
An example is given below.
```
ProcessNum 4
pid:123, arrival_time:60, execution_time:90
pid:13, arrival_time:70, execution_time:100
pid:1023, arrival_time:10, execution_time:160
pid:12, arrival_time:80, execution_time:28
```

`queue.cfg` contains the queue information and its format is as follows:
```
QueueNum n
Period_S S 
Time_Slice_QN Xn Allotmenttime_QN Yn
…
Time_Slice_Q2 X2 Allotmenttime_Q2 Y2
Time_Slice_Q1 X1 Allotmenttime_Q1 Y1
```
Here, the first line denotes the number of queues we will use in the scheduler, the second line denotes 
the period `S` to move up all jobs to the topmost queue (Rule 5), the third line denotes the time slice for 
Queue `n` that is the topmost queue with the highest priority (the smallest time slice), and the subsequent 
lines define other queues with descending order in terms of priority. In each line, between the keyword 
and number, there should be at least one space character. One example is shown below.
```
QueueNum 3
Period_S 300 
Time_Slice_Q3 10 Allotmenttime_Q3 30
Time_Slice_Q2 40 Allotmenttime_Q2 80
Time_Slice_Q1 60 Allotmenttime_Q1 120
```

The output of your program: `output.log`
- Your program should output the schedule to the file (`output.log`).
- The format in output.log is as `Time_slot:x-y, pid:x1, arrival-time:x2, remaining_time:x3`. (E.g. `Time_slot:10-20, pid:57, arrival-time:10, remaining_time:115`)
- The correctness of your implementation will be checked based on `output.log`.

### File Discription
- `bonus/linkedlist.c`: a source file for implementing a linked list.
- `bonus/linkedlist.h`: a head file for implementing a linked list.
- `bonus/Makefile`: a set of rules to determine the tasks in the compilation and linking (build) phase. 
- `bonus/output.log`: a file including the output.
- `bonus/process.file`: a file containing the process infomation.
- `bonus/queue.c`: a source file for implementing a queue.
- `bonus/queue.cfg`: a file containing the MLFQ queue information.
- `bonus/queue.h`: head file for implementing a queue.
- `bonus/scheduler-exec.c`: a source file including the main function. You are not required to modify it.
- `bonus/scheduler-impl.c`: You are required to modify the `scheduler` function in this file to get bonus.

### Instructions
1. Use `cd bonus` to switch to the bonus directory.
2. Implement the `scheduler` function in `scheduler-impl.c`. You may also write some helper functions in this file.
3. Use `make` to build the project. You could also use `make clean` to clean the object and executable files if you do not need them.
4. Use `./Scheduler` to run the program which will output the result in the `output.log`. You could check whether the result is as expected or not. 
5. You could use `make test` to test your implementation with given inputs. Same as question 1, passing the test dose NOT necessarily mean that your program is FULLY correct.
6. You could also change the conditions in `process.file` or `queue.cfg` and run `Scheduler` again to test your implementation.  

### Grading

Your implementation will be graded based on your `scheduler-impl.c` with our version of other files. Different (and more) test cases will be used.

## Submission

Push your file and code (at least `answer.md`, and `scheduler-impl.c` for bonus) to this repository for grading.


