#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int   id;
    void* next;
} node_t;

typedef node_t head_t;

node_t* 
create_list(int id);

int
insert_node_at_end(int id, head_t* head);

int
insert_node_at_start(int id, head_t** head);

int
insert_node_sorted(int id, head_t** head);

int
delete_node_at_end(head_t* head);

int
delete_node_at_start(head_t** head);

int
delete_node_by_id(head_t** head, int id);

int
print_list(head_t* head);

int 
destroy_list(head_t** head);

#endif