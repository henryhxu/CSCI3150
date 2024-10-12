### CSCI3150 Fall2024 Lab Quiz 1: Unix Shell Implementations

#### Question

Which of the following is incorrect about Unix Shell and its implementations?

A. Unix Shell is designed to provide easy access and interaction with OS.

B. exec() is used in a child process and overwrites parent address space. 

C. fork() returns the process id of the child in the parent process.

D. To pass a message from the parent process to the child process via the pipe shared by them, the parent and child process should close the read end and write end of the pipe, respectively.  

#### Solution

2/B.

**Explanations**: exec() will replace the current process image with another image, but will not have effects on the parent process.