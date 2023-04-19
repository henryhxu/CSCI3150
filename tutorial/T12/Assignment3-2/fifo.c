#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int GetCurrentSize_FIFO(node_t **head_fifo)
{
    int queue_length = 0;
    node_t *p;
    p = *head_fifo;

    while(p!=NULL)
    {
        p = p->next;
        queue_length++;
    }


    return queue_length;

}


int IsinCache_FIFO(int Newpageno, node_t **head_fifo)
{
    node_t *curr;
    curr = *head_fifo;

    while(curr!=NULL)
    {
        if(curr->page_no == Newpageno)
            return 1;
        curr = curr->next;
    }

    return 0;
}



int FIFO_cache_put(int Newpageno, node_t **head_fifo, int cache_capacity)
{
    int current_length = 0;
    current_length = GetCurrentSize_FIFO(head_fifo);
    int lack_page_flag = 0;

    if(!IsinCache_FIFO(Newpageno, head_fifo))
    {
        lack_page_flag = 1;

        //insert the new element from the head
        if(cache_capacity > 0)
        {
            node_t * new_node = malloc(sizeof(node_t));
            new_node->page_no = Newpageno;

            if(*head_fifo==NULL)
            {
                *head_fifo = new_node;
                new_node->next = NULL;
            }
            else
            {
                new_node->next = *head_fifo;
                *head_fifo = new_node;
            }


            node_t *curr;
            node_t *prev;
            curr = *head_fifo;

            //If the size of the block sequence is larger than the capacity, delete the first come-in one
            if(current_length+1>cache_capacity)
            {
                while(curr->next!=NULL)
                {
                    prev = curr;
                    curr = curr->next;
                }

                if(prev!=NULL)
                    prev->next = NULL;
                else
                    *head_fifo = NULL;
            }
        }

    }
   
    return lack_page_flag;
    
}