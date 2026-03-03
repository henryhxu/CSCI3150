# CSCI 3150 Introduction to Operating Systems: Assignment Three

## 1. Basic Information

- Topic: Address Translation, Swapping
- Total Marks: 100 + 10 bonus
- **Deadline: 23:59:59, Sunday, March 29th**
- Submission: Github classroom
- High-level aim:
  - Gaining a deeper understanding of multi-level paging and virtual-to-physical address translation
  - Implementing three common swapping policies (LFU, LRU, and CLOCK algorithms) to simulate cache behavior, improving understanding of how different algorithms manage memory in constrained environments.

## 2. Task Overview

In assignment three, you have two separate questions. 

### 2.1. Question 1: Address Translation (40 marks)

(a)A certain computer has a 32-bit virtual address space, and the page size is 1024 bytes. Each page table entry is 4 bytes long. Since each page table must fit within a page, multi-level page tables are needed. Then:

1. How many levels of page tables are required?  
__________(number) levels.  

1. When mapping addresses, how many parts is needed to divide logical address, and how many bits are in each part?  
__________(number) parts.  
Part 1 with __________(number) bits. (if any)  
Part 2 with __________(number) bits. (if any)  
Part 3 with __________(number) bits. (if any)  
Part 4 with __________(number) bits. (if any)  
Part 5 with __________(number) bits. (if any)  
Part 6 with __________(number) bits. (if any)  

**(Note that when dividing up the logical address, although there can be many possible solutions, they differ in the utilization of page directory/table entries, since a partially utilized page cannot be addressed/used to save other data. For this reason, the best solution should minimize the total number of entries that cannot be addressed in all levels of the page table, i.e. the overall memory wastage.)**



(b)In a system where the main memory is byte-addressable and uses paging, the physical page frame size is 8 bytes. Each page table entry occupies 2 bytes. Process P has a logical address space of 64 bytes. The PCB of process P stores the physical page frame number of the outermost page table, which is 8. The diagram below shows the physical page frame numbers where each level of page tables for process P is stored (other contents of the page table entries are omitted). Please answer:	

1.	Into how many levels is process P’s page table divided?  
__________(number) levels.  

2. Calculate the physical address corresponding to logical address 20 generated during the execution of process P.  
Address: __________(number).  
   

![question description](https://pic.superbed.cc/item/6718a926fa9f77b4dc3c312c.png)




### 2.2. Question 2: Swapping (60 marks + 10 bonus )

In this question, you would be guided to implement three commonly used swapping policies, **LFU, LRU and CLOCK algorithm**. You will get 60 marks if you implement LFU and LRU algorithm correctly and 10 bonus marks if you implement Clock algorithm correctly. We provide a framework for you to implement these algorithms. The followings are some descriptions about the framework.

We simply simulate a cache that contains a reference to the cache line, a global time counter, and a Pointer of the Clock algorithm.

Assume that the cache can only hold 5 cache lines.

```C
#define CACHE_SIZE 5

typedef struct {
    CacheLine lines[CACHE_SIZE];
} CacheLinePool;

typedef struct {
    CacheLinePool *line_pool;
    unsigned int time;            // Global time counter
    int clock_pointer;            // Pointer of the Clock algorithm
} Cache;
```

You need to implement the cache line yourself, here are some tips: you need to store the corresponding memory addresses and variables for the LFU, LRU, and CLOCK algorithms.

You are also required to implement functions:

**create_cache, cache_access_lru, cache_access_lfu and cache_access_clock** in cache.c

For create_cache, we have already completed part of the initialization of cache. You only need to add the initialization of cacheline.

For cache_access_lru, cache_access_lfu and cache_access_clock, they are the specific implementations of the three swapping algorithms. You need to check whether the cache hits, replace it if it does not hit, and print relevant information.

You can use the following commands to get the result of your program:

> make clean
>
> make
>
> ./cache_simulator

Note: run make clean only when you have **new changes** to the code and want to see the new output

One testcase is provided for you to validate your implementation. We show  this test case for your better understandings of this problem.

```txt
0x1A2B
0x3C4D
0x1A2B
0x5E6F
0x7A8B
0x9A8B
0x7A9F
0x7A8B
0x7CAB
0x1A2B
0x3C4D
```

Each row represents an access request for that address.

The output of the program involves whether cache hits or not and the replacement status if missed like the followings for the case.

(If you don't implement the bonus part):

```
Using LRU replacement strategy：
LRU: Cache miss, replaced line 0
LRU: Cache miss, replaced line 1
LRU: Cache hit at line 0
LRU: Cache miss, replaced line 2
LRU: Cache miss, replaced line 3
LRU: Cache miss, replaced line 4
LRU: Cache miss, replaced line 1
LRU: Cache hit at line 3
LRU: Cache miss, replaced line 0
LRU: Cache miss, replaced line 2
LRU: Cache miss, replaced line 4

Use LFU replacement strategy:
LFU: Cache miss, replaced line 0
LFU: Cache miss, replaced line 1
LFU: Cache hit at line 0
LFU: Cache miss, replaced line 2
LFU: Cache miss, replaced line 3
LFU: Cache miss, replaced line 4
LFU: Cache miss, replaced line 1
LFU: Cache hit at line 3
LFU: Cache miss, replaced line 1
LFU: Cache hit at line 0
LFU: Cache miss, replaced line 1

Use Clock replacement strategy:
```

(If you implement the bonus part correctly):

```
Using LRU replacement strategy：
LRU: Cache miss, replaced line 0
LRU: Cache miss, replaced line 1
LRU: Cache hit at line 0
LRU: Cache miss, replaced line 2
LRU: Cache miss, replaced line 3
LRU: Cache miss, replaced line 4
LRU: Cache miss, replaced line 1
LRU: Cache hit at line 3
LRU: Cache miss, replaced line 0
LRU: Cache miss, replaced line 2
LRU: Cache miss, replaced line 4

Use LFU replacement strategy:
LFU: Cache miss, replaced line 0
LFU: Cache miss, replaced line 1
LFU: Cache hit at line 0
LFU: Cache miss, replaced line 2
LFU: Cache miss, replaced line 3
LFU: Cache miss, replaced line 4
LFU: Cache miss, replaced line 1
LFU: Cache hit at line 3
LFU: Cache miss, replaced line 1
LFU: Cache hit at line 0
LFU: Cache miss, replaced line 1

Use Clock replacement strategy:
Clock: Cache miss, replaced line 0
Clock: Cache miss, replaced line 1
Clock: Cache hit at line 0
Clock: Cache miss, replaced line 2
Clock: Cache miss, replaced line 3
Clock: Cache miss, replaced line 4
Clock: Cache miss, replaced line 0
Clock: Cache hit at line 3
Clock: Cache miss, replaced line 1
Clock: Cache miss, replaced line 2
Clock: Cache miss, replaced line 4
```

Meanwhile, your implementation would be verified by some hidden testcases. You could refer to the tutorial slides to get some hints about how to implement this.

**Please follow this format for output, because your answer will be scored based on the output**


## 3. Submission Content

For Question 1, you only need to put your answers in `a.txt` and `b.txt`. For example, if your answer for (a) is "**2** (number) levels, **2** (number) parts, Part 1 with **8** (number) bits, (if any) Part 2 with **10** (number) bits.(if any)", Your `a.txt` should be:
```
2
2
8
10
```
If your answer for (b) is "**2** (number) levels. Address: **36** (number).", Your `b.txt` should be:
```
2
36
```

For Question 2, you are required to modify `cache.h` and `cache.c`. **Do not modify any other files**

Before submission, please ensure you have completed (1) the declaration of originality at `declaration_en.doc`, and (2) acknowledgment of AI tools at `ai_declaration.txt`.

The last submission will be considered for the final score of this assignment. A few test cases will be used for the final score after the deadline. Marks will not be shown upon each submission, because the assignment is relatively straightforward. Two cases are provided for your reference.



## 4. Generative AI Policy

In assignment three, we don't allow usage of generative AI tools.

- Using AI tools without properly understanding of the generated code and answers can put you at risk in quizzes/exams.


## 5. Other Notes

- For coding questions, we will compile, run, and grade your program with Ubuntu latest, which is the same as the autograding environment. Please make sure your program sources are compatible with the corresponding version of Ubuntu. Otherwise, 0 marks will be given. 

- Note that we can only grade what you submit in the github repo. You will lose write access to the github repo after deadline. Please find related policies on the [course website](https://github.com/henryhxu/CSCI3150). To use grace token, we provide a separate assignment in github classroom named "assignment_3_grace_token" for your submission. The entrance to this assignment will be released immediately after the normal deadline. DO NOT accept grace token assignment unless you do want to use grace token.

- TA Deng, Yangtao is responsible for this assignment. Questions about the assignment via Piazza are welcomed. Due to massive class size, no individual email will be replied. Requests including but not limited to asking TA to set up environment, write code and debug for you will be rejected according to regulations.
