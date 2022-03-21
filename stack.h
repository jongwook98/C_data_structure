#ifndef STACK_H
#define SATCK_H

#include "linked_list.h"

typedef struct stack
{
	struct linked_list* ptr;
}st;

st* init_stack(void);
void exit_stack(st* sp);
int s_push(st* sp, int data);
int s_pop(st* sp);
int is_empty(st* ptr);

#endif