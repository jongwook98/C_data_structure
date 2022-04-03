#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
	int data;
	struct linked_list* next;
}Node;

Node* init_node(void);
int exit_node(Node* linked_list);
int add_data(Node* linked_list, int data);
int delete_data(Node* linked_list);

#endif