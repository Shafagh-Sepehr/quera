#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define mem (Node*)malloc(sizeof(Node))//be soorate: Node *node=mem; ---> Node *node=(Node*)malloc(sizeof(Node)); 
#pragma warning(disable:4996)

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* head = NULL;
Node* tail = NULL;

int link_size() {
	Node* index = head;
	int ctr = 0;
	while (index) {
		ctr++;
		index = index->next;
	}
	return ctr;
}

Node* creatNode(int data) {

	Node* x;
	x = mem;
	x->data = data;
	x->next = NULL;
	return x;
}



void push_back(int data) {
	Node* temp_pointer;
	if (head == NULL) {
		head = creatNode(data);
		return;
	}
	temp_pointer = head;

	while (1) {

		if (temp_pointer->next == NULL) {
			temp_pointer->next = creatNode(data);
			tail = temp_pointer->next;
			return;
		}
		else {
			temp_pointer = temp_pointer->next;
		}
	}
}



void pop_front() {
	if (head == NULL) {
		return;
	}
	else {
		Node* temp = head;
		head = head->next;
		free(temp);
	}
}

void pop_back() {
	if (head == NULL) {
		return;
	}
	bool headnull=false;
	if (head->next == NULL)
		headnull = true;
	Node* temp_pointer;
	Node* temp_pointer_save = NULL;
	temp_pointer = head;
	bool head1 = true;
	while (1)
		if (temp_pointer->next == NULL) {
			if (!head1)
				temp_pointer_save->next = NULL;
			free(temp_pointer);
			if (headnull)
				head = NULL;
			return;
		}
		else {
			temp_pointer_save = temp_pointer;
			temp_pointer = temp_pointer->next;
			head1 = false;
		}
	

}






void print_top() {
	Node* index=head;
	if (index == NULL) {
		printf("stack is empty\n");
		return;
	}
	while (index->next != NULL) {
		index = index->next;
	}
	printf("%d\n", index->data);

}



void kill_list() {
	while (head != NULL)
		pop_front();
	return;
}

int main() {
	int a, b;
	
	while (1) {
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			//printf("enter the data as an int:");
			scanf("%d", &a);
			push_back(a);
			break;
			
		case 2:
			if (!head) {
				printf("stack is empty\n");
				break;
			}
			print_top();
			pop_back();
			break;
		case 3:
			print_top();
			break;
		
		case 4:
			kill_list();
			return 0;
		default:
			
			break;
		}
		//printf(".....................................................\n");


		
	}




	kill_list();
	//free();
	return 0;
}
