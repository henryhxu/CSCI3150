#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int page_no;
    struct node * next;
} node_t;