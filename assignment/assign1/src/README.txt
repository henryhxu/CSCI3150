1. What is inside the .zip file?
Assign1.zip contains an incomplete simple shell program. The following files are included in it:
  (1) simple-execute.c: the file that you need to revise and submit.
  (2) simple-shell.c: 
  (3) Makefile


2. How to compile?
We provide a Makefile for quick compilation. To compile, input:

make

You can revise the Makefile to add your own compilation targets. However note that we will only use the original version of Makefile to compile your program when grading. 


3. How to run?
To run thr program after compilation, input:
./SimpleShell


4. What do I need to implement?
For Assignment One:
  (1) Revise simple-execute.c to implement the functions mentioned in documentation of Assignment One. In simple-execute.c, you can define your own functions and add header files if needed. However, you must use "dup()", "pipe()", "execvp()" and functions in their family to execute the commands.(try "man dup()" for details about these functions)
  (2) As simple-execute.c is the ONLY file you need to submit, please make sure all your implementations are resided in simple-execute.c. If any modifications are made in other files such as simple-shell.c or newly-added files, we may fail to compile your sources, which will lead to grade loss.  


5. How to test my program?
At least, your shell program should be able to correctly execute the following commands:

user@OSLAB1:/$ ls
user@OSLAB1:/$ ps
user@OSLAB1:/$ ls -l
user@OSLAB1:/$ ps -al
user@OSLAB1:/$ ls -l | wc -l
user@OSLAB1:/$ ls -l | grep simple | wc -l
user@OSLAB1:/$ ls -l | grep simple | sort -k 9

Note: we may use some new test cases when grading.


6. How to submit the assignment?
Due: 18:00:00 p.m., Mon, Feb 13th
Please submit to blackboard before due. You only need to submit simple-execute.c. 
Note: One grace token will be automatically used if your last submission are made within 24 hours after the deadline mentioned above. Later submissions will be graded as zero mark.     

Have fun!!!