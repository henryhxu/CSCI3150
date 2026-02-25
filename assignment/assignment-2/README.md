# CSCI 3150 Introduction to Operating Systems: Assignment Two

## 1. Basic Information

- Topic: Synchronization, Process Scheduling
- Total Marks: 100 + 10 bonus
- **Deadline: 23:59:59 p.m., Sun, Mar 1st, 2026**
- Submission: Github classroom
- High-level aim:
  - Understanding how to ensure synchronization via mutex and condition variables.
  - Understanding the implementation of mutex lock in C.
  - Understanding the multilevel feedback queue (MLFQ) algorithm.
  - Understanding the implementation of MLFQ in C.

## 2. Task Overview

In assignment two, you have two separate questions. Please refer to the question folders for detailed information for each question.

### 2.1. Question 1: Read-Write Lock (60 marks)

Instead of directly using `pthread_rwlock_t` provided by pthread library, you are required to implement a priority-based read-write lock using condition variables, with some additional rules. More details are stated in `Question1/README.md`.
 

### 2.2. Question 2: Multilevel Feedback Queue (40 marks + 10 bonus)

In this question, you are required to fill in the blanks of MLFQ scheduling table for 40 marks and implement the MLFQ in C for 10 bonus. More details are stated in `Question2/README.md`.


## 3. Submission Content

For Question 1, you only need to modify `Question1/src/rwlock.c`.

For Question 2, you are required to modify `Question2/answer.md` (and `Question2/bonus/scheduler-impl.c` for bonus).

Before submission, please ensure you have completed (1) the declaration of originality at `declaration_en.doc`.


## 4. Other Notes

- Note that we can only grade what you submit in the github repo. You will lose write access to the github repo after deadline. Please find related policies on the [course website](https://github.com/henryhxu/CSCI3150). To use grace token, we provide a separate assignment in github classroom named "assignment_2_grace_token" for your submission. The entrance to this assignment will be released immediately after the normal deadline. DO NOT accept grace token assignment unless you do want to use grace token.


## 5. FQA (Frequently Questioned Answers)
0. Is the reader or writer in the reader-writer lock preemptible?
    - No.

1. When `period_S` occurs, if a new process arrives, what is the order between sort and the arrival of the new process? Does the new process participate in sort?
    - Whether it participates in the sort or not is fine. This will not affect your assignment grade.

2. If no process is currently executing, how should the MLFQ table be filled out or output?
    - These situations do not need to be recorded. The MLFQ table only needs to document the state when a thread is actively running.

3. If a process runs for a very long time and exhausts the allotment time of all queues, what should be done?
    - You can ignore this case.  This will not affect your assignment grade.

4. What does the sentence 'Sorting will happen every time it arrives the Period_S and the length of one time slice is 10.' in `README.md` mean?
    - It is a typo. It should be 'Sorting will happen every time it arrives the Period_S.' I updated it in assignment two.

5. Where will the new process be inserted into the queue? At the head or the tail?
    - Because the queues in multilevel feedback queue algorithm are first-in-first-out (FIFO) data structure. The new process will be inserted at the end of the topmost queue.

6. At a certain moment, process X finishes running its current time slice and is about to re-enter the topmost queue, when process Y arrives. How is the enqueue order of process X and process Y determined?
    - Process X is enqueued before process Y.

7. Does the sorting repeat every time period `S`?
    - Yes.

8. Is the MLFQ scheduler preemptive within a time slice?
    - No. For simplicity in this assignment, a running process will NOT be preempted by a newly arrived higher-priority process until it finishes its current time slice or allotment. Note that in standard OS implementations, MLFQ is typically preemptive.

