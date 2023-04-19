1. The current code base contains FIFO and LRU page replacement framework implemented by the single linked list. It includes:
   - main.c: The main function, and it includes the testcase reading part, the report for the status of cache after assessing each page in the reference row and the calculation of the total missing pages.
   - node.h: The definition about the node in the single linked list.
   - fifo.c: The implementation of FIFO algorithm
   - lru.c: The implementation of LRU algorithm
   - Makefile

    To compile, input in the terminal:
    -  make

    -  Then if you want to run case1.txt, you could run it: ./main -file ./testcase/case1.txt

2. For Problem2 in Assignment Three:
    - Revise fifo.c and lru.c (that is the only two files you need to modify/submit) to implement FIFO and LRU algorithm. You could write **some helper functions** in the files as well. 

    - Your program should be compiled by:
    make

  Submission: You only need to modify fifo.c and lru.c in your github repo. Do not modify other files.

PS: Make sure there is no compilation errors in your code. Otherwise, you may lose all points for this question.