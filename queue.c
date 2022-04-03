#include "linked_list.h"

typedef struct queue
{
	struct linked_list* node_ptr;
}que;

que* init_queue(void);
int exit_queue(que* q_name);
int enqueue(que* q_name, int data);
int dequeue(que* q_name);
int is_empty_queue(que* q_name);
int print_list_all(que* q_name);
int search_data(que* q_name, int data);

que* init_queue(void) {

	que* index = (que*)calloc(1, sizeof(que));
	if (index == NULL) {
		printf("memory error");
		return -1;
	}
	index->node_ptr = init_node();

	return index;
}

int exit_queue(que* q_name) {

	if (q_name == NULL) {
		printf("queue is not exist");
		return -1;
	}

	Node* top = q_name->node_ptr;
	while (top->next) {

		exit_node(top);
	}
	free(q_name);
	return 0;
}

int enqueue(que* q_name, int data) {
	add_data(q_name->node_ptr, data);

	return 1;
}

int dequeue(que* q_name) {
	if (is_empty_queue(q_name)) {
		printf("queue is empty ! \n");
		return 0;
	}
	Node* front = q_name->node_ptr;
	Node* front_ptr = q_name->node_ptr->next;

	int dequeue_data = front->next->data;

	if (front->next->next != NULL) {
		front->next = front->next->next;
	}

	exit_node(front_ptr);
	return dequeue_data;
}

int is_empty_queue(que* q_name) {
	if (q_name->node_ptr->next)
		return 0;
	else
		return 1;
}
/*
int main(void) {

	que* int_queue1 = init_queue();
	printf("%d \n", is_empty_queue(int_queue1));
	dequeue(int_queue1);

	enqueue(int_queue1, 10);
	printf("%d \n", is_empty_queue(int_queue1));
	printf("dequeue data = %d \n", dequeue(int_queue1));

	for (int i = 0; i < 10; i++) {
		enqueue(int_queue1, i);
	}

	print_list_all(int_queue1);

	printf("dequeue data = %d \n", dequeue(int_queue1));
	printf("dequeue data = %d \n", dequeue(int_queue1));
	printf("dequeue data = %d \n", dequeue(int_queue1));

	print_list_all(int_queue1);

	printf("%d \n", is_empty_queue(int_queue1));

	search_data(int_queue1, 5);

	return 0;
}

int print_list_all(que* q_name) {

	Node* prt = q_name->node_ptr;
	int num = 0;
	while (prt->next) {
		prt = prt->next;
		printf("%d node = %d\n", num++, prt->data);
	}
	return 1;
}
int search_data(que* q_name, int data) {
	int num = 0;
	while (q_name->node_ptr->next) {
		num++;
		q_name->node_ptr = q_name->node_ptr->next;
		if (q_name->node_ptr->data == data) {
			printf("search %d data node = %d", num, q_name->node_ptr->data);
			return 1;
		}
	}
	printf("not search %d data", data);
	return 1;
}
*/