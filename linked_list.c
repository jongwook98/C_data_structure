#include "linked_list.h"

Node* init_node(void) {

	Node* node = (Node*)calloc(1, sizeof(Node));
	
	if (node == NULL) {
		printf("init_node error : memory is not allocated");
		return NULL;
	}
	return node;
}

int exit_node(Node* linked_list) {
	if (linked_list == NULL) {
		printf("exit_node error : memory is not existed");
		return -1;
	}
	free(linked_list);
	return 0;
}

int add_data(Node* linked_list, int data) {

	Node* add_node = init_node();
	if (add_node == NULL || linked_list == NULL) {
		printf("node is not allocate");
		return -1;
	}
	while (linked_list->next) {
		linked_list = linked_list->next;
	}
	linked_list->next = add_node;
	add_node->data = data;

	return 0;
}

int delete_data(Node* linked_list) {

	if (linked_list == NULL) {
		printf("linked list is empty");
		return -1;
	}

	else if (linked_list->next->next){
		Node* temp = linked_list->next->next;
		exit_node(linked_list->next);
		linked_list->next = temp;
	}                 
	else {
		exit_node(linked_list->next);
		linked_list->next = NULL;
	}
}
/*
int main(void) {
	
	Node* head = init_node();
	for (int i = 0; i < 10; i++) {
		add_data(head, i);
	}

	print_list_all(head);

	search_data(head, 12);

	return 0;
}

int print_list_all(Node* linked_list) {
	int num = 0;
	while (linked_list->next) {
		linked_list = linked_list->next;
		printf("%d node = %d\n", num++, linked_list->data);
	}
	return 1;
}
int search_data(Node* linked_list, int data) {
	int num = 0;
	while (linked_list->next) {
		num++;
		linked_list = linked_list->next;
		if (linked_list->data == data) {
			printf("search %d data node = %d", num, linked_list->data);
			return 1;
		}
	}
	printf("not search %d data", data);
	return 1;
}
*/