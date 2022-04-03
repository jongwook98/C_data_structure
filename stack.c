#include "linked_list.h"

typedef struct stack
{
	struct linked_list* node_ptr;
}st;

st* init_stack(void);
int exit_stack(st* s_name);
int s_push(st* s_name, int data);
int s_pop(st* s_name);
int is_empty_stack(st* s_name);
int print_list_all(st* s_name);
int search_data(st* s_name, int data);

st* init_stack(void) {
	
	st* index = (st*)calloc(1, sizeof(st));
	if (index == NULL) {
		printf("memory error");
		return -1;
	}
	index->node_ptr = init_node();

	return index;
}

int exit_stack(st* s_name) {

	if (s_name == NULL) {
		printf("stack is not exist");
		return -1;
	}

	Node* top = s_name->node_ptr;
	while (top->next) {

		exit_node(top);
	}
	free(s_name);
	return 0;
}

int s_push(st* s_name, int data) {
	add_data(s_name->node_ptr, data);

	return 1;
}

int s_pop(st* s_name) {
	if (is_empty_stack(s_name)) {
		printf("stack is empty ! \n");
		return 0;
	}
	Node* top = s_name->node_ptr;
	Node* pre_top = s_name->node_ptr;

	while (top->next) {
		pre_top = top;
		top = top->next;
	}
	pre_top->next = NULL;
	int pop_data = top->data;
	exit_node(top);
	return pop_data;
}

int is_empty_stack(st* s_name) {
	if (s_name->node_ptr->next)
		return 0;
	else
		return 1;
}
/*
int main(void) {

	st* int_stack1 = init_stack();
	printf("%d \n", is_empty_stack(int_stack1));
	s_pop(int_stack1);

	s_push(int_stack1, 10);
	printf("%d \n", is_empty_stack(int_stack1));
	printf("%d \n", s_pop(int_stack1));

	for (int i = 0; i < 10; i++) {
		s_push(int_stack1, i);
	}

	print_list_all(int_stack1);

	printf("pop data = %d \n", s_pop(int_stack1));
	printf("pop data = %d \n", s_pop(int_stack1));
	printf("pop data = %d \n", s_pop(int_stack1));

	print_list_all(int_stack1);

	printf("%d \n", is_empty_stack(int_stack1));

	search_data(int_stack1, 5);

	return 0;
}

int print_list_all(st* s_name) {
	
	Node* prt = s_name->node_ptr;
	int num = 0;
	while (prt->next) {
		prt = prt->next;
		printf("%d node = %d\n", num++, prt->data);
	}
	return 1;
}
int search_data(st* s_name, int data) {
	int num = 0;
	while (s_name->node_ptr->next) {
		num++;
		s_name->node_ptr = s_name->node_ptr->next;
		if (s_name->node_ptr->data == data) {
			printf("search %d data node = %d", num, s_name->node_ptr->data);
			return 1;
		}
	}
	printf("not search %d data", data);
	return 1;
}
*/