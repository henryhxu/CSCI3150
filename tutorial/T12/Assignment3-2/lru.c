#include <stdio.h>
#include <stdlib.h>
#include "node.h"


int GetCurrentSize_LRU(node_t **head_lru)
{
    int queue_length = 0;
    node_t *p;
    p = *head_lru;

    while(p!=NULL)
    {
        p = p->next;
        queue_length++;
    }

    return queue_length;
}


int IsinCache_LRU(int Newpageno, node_t **head_lru)
{
    node_t *curr;
    node_t *prev;
    curr = *head_lru;

    while(curr!=NULL)
    {
        if(curr->page_no == Newpageno)
        {
            if(curr == *head_lru)
                return 1;
            else
            {
                prev->next = curr->next;
                curr->next = *head_lru;
                *head_lru = curr;
                return 1;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return 0;
}



int LRU_cache_put(int Newpageno, node_t **head_lru, int cache_capacity)
{
    int current_length = 0;
    current_length = GetCurrentSize_LRU(head_lru);
    int lack_page_flag = 0;

    if(!IsinCache_LRU(Newpageno, head_lru))
    {
        lack_page_flag = 1;

        if(cache_capacity>0)
        {
            node_t * new_node = malloc(sizeof(node_t));
            new_node->page_no = Newpageno;

            if(*head_lru==NULL)
            {
                *head_lru = new_node;
                new_node->next = NULL;
            }
            else
            {
                new_node->next = *head_lru;
                *head_lru = new_node;
            }

            node_t *curr;
            node_t *prev;
            curr = *head_lru;

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
                    *head_lru = NULL;
            }
        }
    }


    return lack_page_flag;
    
}