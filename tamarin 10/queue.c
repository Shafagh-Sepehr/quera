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

void printNode(Node* n) {
	printf("%d", (*n).data);
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





void delet(int index) {
	index++;
	if (index > link_size() - 1 || index < 0) {
		printf("ERROR3\n");
		return;
	}
	int ctr = 0;
	Node* index_pointer, * before_index = NULL;
	index_pointer = head;



	while (1) {


		if (index == 0) {
			pop_front();
			return;
		}
		else if (index == ctr) {

			before_index->next = index_pointer->next;
			free(index_pointer);
			return;
		}
		else if (index_pointer == NULL) {
			printf("ERROR3\n");
			return;
		}

		before_index = index_pointer;
		index_pointer = index_pointer->next;

		ctr++;
	}
}

void delet2(int index) {
	//index++;
	if (index > link_size() - 1 || index < 0) {
		printf("ERROR4\n");
		return;
	}
	int ctr = 0;
	Node* index_pointer, * before_index = NULL;
	index_pointer = head;



	while (1) {


		if (index == 0) {
			pop_front();
			return;
		}
		else if (index == ctr) {

			before_index->next = index_pointer->next;
			free(index_pointer);
			return;
		}
		else if (index_pointer == NULL) {
			printf("ERROR3\n");
			return;
		}

		before_index = index_pointer;
		index_pointer = index_pointer->next;

		ctr++;
	}
}
void show_Node(int index) {
	if (index > link_size()  || index < 0) {
		printf("ERROR1\n");
		return;
	}
	int ctr = 0;
	Node* index_pointer;
	index_pointer = head;



	while (1) {

		if (index-1 == ctr) {
			printf("%d\n", index_pointer->data);
			return;
		}
		
		index_pointer = index_pointer->next;

		ctr++;
	}
}





int search(int data) {
	int ctr = 0;
	Node* index_pointer;
	index_pointer = head;
	while (1) {
		if (index_pointer == NULL) {
			return -1;
		}
		else if (index_pointer->data == data) {
			return ctr;
		}
		else {
			ctr++;
			index_pointer = index_pointer->next;
		}
	}

}


void print() {
	if (!head) {
		printf("list is empty!\n");
		return;
	}
	Node* index = head;
	int ctr = 0;
	while (index) {
		printf("%d: ", ctr);
		printNode(index);
		printf("\n");
		index = index->next;
		ctr++;
	}
	return;
}

void kill_list() {
	while (head != NULL)
		pop_front();
	return;
}

int main() {
	int a, b,k;
	while (1) {
		
		scanf("%d", &a);
		switch (a)
		{
		
		case 1:
			scanf("%d", &a);
			push_back(a);
			break;
		case 2:
			if (!head) {
				printf("ERROR0\n");
				break;
			}
			printNode(head);
			printf("\n");
			pop_front();
			break;
		case 3:
			scanf("%d", &a);
			show_Node(a);
			break;
		case 4:
			scanf("%d", &a);
			k = search(a);
			if (k == -1) {
				printf("ERROR2");
			}
			else{
				k++;
				printf("%d\n",k );
			}
			break;
		case 5:
			scanf("%d", &a);
			delet(a);
			break;
		case 6:
			scanf("%d", &a);
			k = search(a);
			if (k == -1) {
				printf("ERROR4\n");
				break;
			}
			delet2(k);
			break;
		case 7: 
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
