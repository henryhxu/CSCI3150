# Question1: Priority-based Read-Write Lock Implementation via Condition Variables (60 Marks)

## Introduction

In this question, you are required to implement a priority-based read-write lock using condition variables. More specifically, the lock shall follow the following policies:

### Basic Features

- **Exclusive Write Lock**: Only one writer can hold the lock at a time, blocking all readers and other writers.
- **Shared Read Lock**: Multiple readers can hold the lock simultaneously, as long as no writers are active.

### New Policies

1. **Priority Levels**:
   - Locks can be acquired with high or low priority. Example usage: `rwlock_acquire_write(&lock, "high priority")`. Check `src/main.c` to see detailed usage.

2. **Priority Hierarchy**:
   - High priority write
   - High priority read
   - Low priority write
   - Low priority read

3. **Reader Limit**:
   - Up to 5 readers can hold the lock concurrently.

4. **Writer Preference**:
   - Under the same priority, waiting write requests are served before waiting read ones.

5. **High Priority Preference**:
   - High priority requests are served before low priority ones.

## Instructions

1. Implement the functions in `src/rwlock.c`. This is the ONLY file you need to modify.
2. Use `make` to build the project.
3. Use `.\Readwritelock` to run the program. It shall be done in 15s and 2 logs will be generated under `logs/`.
4. Run tests with `make test`. We provide two test cases as stated in Hint for you to debug. Passing the test DOESN'T necessarily mean your program is FULLY correct. You are encouraged to check the output log on your own.
5. You are NOT allowed to use `pthread_rwlock_t` and related functions. Instead, implement the lock with the struct `rwlock_t` defined in `src/rwlock.h`.

## File Descriptions

- **src/rwlock.h**: Header file with function prototypes.
- **src/rwlock.c**: Implement your lock here. This is the ONLY file you need to modify.
- **src/main.c**: Example usage of the lock.
- **logs/**: Dir the output log will be stored.
- **tests/analyze_logs.c**: A simple script to analyze log outputs. 

## Hint
1. You need to use `pthread_cond_broadcast()` instead of `pthread_cond_signal()` when you want to wake up some waiting threads, because the scheduling inside read or write threads is also priority-based instead of FIFO. Think of the case where a high-priority writer waits behind a low-priority writer (or many) in the waiting queue for `&rwlock->writers_cond`.


2. At least, you should consider the following two cases:
- Set all readers as "high priority" and all writers as "low priority". In this case, your lock should behave as reader preference and you may observe the starvation of writers.
- Set all writers as "high priority" and all readers as "low priority". In this case, your lock should behave as writer preference and you may observe the starvation of readers. Specifically, when a reader has acquired a read lock, another reader can acquire the read lock only if (1) no other writer is waiting (writer preference), and (2) the number of active readers is less than 5 (reader limit).

You are encouraged to test more complicated cases to ensure correctness.

## Grading

We will grade your implementation by using your `rwlock.c` with our version of other files. Different (and more) test cases will be used, so you may still lose some marks even if you pass the `make test`. Think carefully about the rules and edge cases. You may add your own test cases in the `src/main.c` to observe your lock's behavior under different cases.

## Submission

Push your code to this repository for grading.
