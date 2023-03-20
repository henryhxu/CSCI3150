#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//The implementation of the node in single linked list
typedef struct node{
    int page_no;
    struct node * next;
} node_t;