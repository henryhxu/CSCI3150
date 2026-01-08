# Q&As

## Purpose of each file?

The `src` directory contains an incomplete simple shell program. The following files are included in it:
  (1) simple-execute.c: the file that you need to revise and submit.
  (2) simple-shell.c:
  (3) Makefile

## How to compile?

We provide a Makefile for quick compilation. To compile, input:

make

You can revise the Makefile to add your own compilation targets. However note that we will only use the original version of Makefile to compile your program when grading.

## How to run?

To run thr program after compilation, input:
./SimpleShell

## What do I need to implement?

For assignment one:
  (1) Revise simple-execute.c to implement the functions mentioned in documentation of Assignment One. In simple-execute.c, you can define your own functions and add header files if needed. However, you must use "dup()", "pipe()", "execvp()" and functions in their family to execute the commands.(try "man dup()" for details about these functions)
  (2) As simple-execute.c is the ONLY file you need to modify, please make sure all your implementations are resided in simple-execute.c. If any modifications are made in other files such as simple-shell.c or newly-added files, we may fail to compile your sources, which will lead to severe grade loss.

## How to test my program?

At least, your shell program should be able to correctly execute and porduce the correct output for the following commands:

```shell
cd ..
ls
ls -l
ls -l | wc -l
ls -l | grep simple | wc -l
ls -l | grep simple | sort -k 9
```

We provide these testcases in the autograding workflow of repos in Github classroom. Each time you commit to your project, checks will be triggered and grading results can be viewed.

## How to submit the assignment?

Due: 23:59 p.m., Sun, Feb. 1
Please join the github classroom before due. You only need to modify simple-execute.c.
Note: To use grace token, we provide a separate assignment in github classroom named "assignment_1_grace_token" for your submission. The entrance to this assignment will be released immediately after the normal deadline. DO NOT accept grace token assignment unless you do want to use grace token.

Have fun!!!
