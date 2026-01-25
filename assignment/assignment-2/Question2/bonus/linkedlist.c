#include "linkedlist.h"

LinkedList* Create(){
    LinkedList* head;
    head = (LinkedList*)malloc(sizeof(LinkedList));
    head -> next = NULL;
    return head;
}

int IsEmpty(LinkedList* Llist){
    return (Llist->next == NULL);
}

Node Find(LinkedList* Llist, Process proc){
    Node node = Llist -> next;
    while(node != NULL && node->proc.process_id != proc.process_id){
        node = node -> next;
    }
    return node;
}

LinkedList* AddTail(LinkedList* Llist, Process proc){
    // Node node = (Node)malloc(sizeof(Node));
    LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
    node->proc = proc;
    node->next = NULL;
    LinkedList* pt = Llist;
    while ( pt -> next){
        pt = pt->next;
    }
    pt -> next = node;
    return Llist;
}

LinkedList* AddHead(LinkedList* Llist, Process proc){
    LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
    node-> proc = proc;
    node-> next = Llist->next;
    Llist->next = node;
    return Llist;
}

LinkedList* Add(LinkedList* Llist, Process proc, int position){
    LinkedList* node = (LinkedList*)malloc(sizeof(LinkedList));
    node->proc=proc;
    node->next=NULL;
    int i = 0;
    for (LinkedList* pt = Llist; pt->next != NULL; pt = pt-> next){
        if (i == position){
            node->next = pt->next;
            pt->next = node;
            break;
        }
        i++;
    }
    return Llist;
}

LinkedList* DeleteTail(LinkedList* Llist){
    LinkedList* pt = Llist;
    while ( pt -> next){
        if (pt->next->next == NULL){
            pt->next = NULL;
            break;
        }
        pt = pt->next;
    }
    return Llist;
}

LinkedList* DeleteHead(LinkedList* Llist){
    if (Llist -> next == NULL){
        printf("Delete Error. Input is NULL. \n");
        return NULL;
    }else {
        Llist -> next = Llist -> next -> next;
        return Llist;
    }
}

LinkedList* Delete(LinkedList* Llist, int position){
    int i = 0;
    for (LinkedList* pt = Llist; pt != NULL; pt = pt-> next){
        if (i == position){
            pt->next = pt->next->next;
            break;
        }
        i++;
    }
    if (i != position){
        printf("Delete Error!\n");
    }
    return Llist;
}

void LlistPrint(LinkedList* Llist){
    // printf("LinkedList: ");
    LinkedList* pt = Llist;
    while (pt->next){
        pt = pt->next;
        printf("Process%d ", pt->proc.process_id);
    } 
    printf("\n");
}
