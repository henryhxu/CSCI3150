#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int FIFO_cache_put(int Newpageno, node_t **head_fifo, int cache_capacity);
int LRU_cache_put(int Newpageno, node_t **head_lru, int cache_capacity);
void DisplayResult(node_t *head, FILE *fp_out);

int main(int argc, char *argv[])
{

    printf("------------------------------------------------------------\n");
    printf("Page Replacement Simulated Program for CSCI 3150 (Hong Xu, Henry@CSE,CUHK)\n");

    FILE *fp_in = NULL;
    FILE *fp_out = NULL;

    int cache_capacity; //The size of FIFO cache and LRU cache
    int refer_total; //The total of elements in refernce row

    fp_in = fopen(argv[2], "r");
    fscanf(fp_in, "%d", &cache_capacity);
    fscanf(fp_in, "%d", &refer_total);

    int pageno[refer_total]; //The reference row

    for(int i=0; i<refer_total; i++)
        fscanf(fp_in, "%d", &pageno[i]);

    fclose(fp_in);

    //int pageno[12] = {4,3,2,1,4,3,5,4,3,2,1,5};
    //int cache_capacity = 4;

    node_t *head_fifo=NULL;
    node_t *head_lru=NULL;

    int page_fault_time_FIFO = 0;
    int page_fault_time_LRU = 0;

    int page_fault_flag_FIFO;
    int page_fault_flag_LRU;

    fp_out = fopen(argv[4], "w+");



    for(int i=0; i<refer_total; i++)
    {
        page_fault_flag_FIFO = FIFO_cache_put(pageno[i], &head_fifo, cache_capacity);
        printf("After assessing %d, the elements in FIFO cache:", pageno[i]);
        fprintf(fp_out, "After assessing %d, the elements in FIFO cache:", pageno[i]);
        DisplayResult(head_fifo, fp_out);
        
        page_fault_flag_LRU = LRU_cache_put(pageno[i], &head_lru, cache_capacity);
        printf("the elements in LRU cache:");
        fprintf(fp_out, "the elements in LRU cache:");
        DisplayResult(head_lru, fp_out);

        printf("\n");
        fprintf(fp_out, "\n");

        if(page_fault_flag_FIFO)
            page_fault_time_FIFO++;

        if(page_fault_flag_LRU)
            page_fault_time_LRU++;
    }

    printf("Total times of missing in FIFO:%d\n", page_fault_time_FIFO);
    fprintf(fp_out, "Total times of missing in FIFO:%d\n", page_fault_time_FIFO);
    printf("Total times of missing in LRU:%d\n", page_fault_time_LRU);
    fprintf(fp_out, "Total times of missing in LRU:%d\n", page_fault_time_LRU);  

    return 0;

}


void DisplayResult(node_t *head, FILE *fp_out)
{
    node_t *curr;
    curr = head;

    while(curr!=NULL)
    {
        printf("%d ", curr->page_no);
        fprintf(fp_out, "%d ", curr->page_no);
        curr = curr->next;
    }
}