#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
	x = (Node*)malloc(sizeof(Node));
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

void push_front(int data) {
	if (head == NULL) {
		head = creatNode(data);
	}
	else {
		Node* temp, * node = creatNode(data);
		node->next = head;
		head = node;
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
	bool headnull = false;
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

void insert(int data, int index) {
	if (index > link_size() || index < 0) {
		printf("####....invalid input size!....####\n");
		return;
	}

	int ctr = 0;
	Node* index_pointer, * inserted_Node, * before_index = NULL, * before_before_index = NULL;
	index_pointer = head;


	while (1) {
		

		if (index == 0) {
			push_front(data);
			return;
		}
		else if (index == ctr && before_index != NULL) {

			inserted_Node = creatNode(data);
			inserted_Node->next = index_pointer;
			before_index->next = inserted_Node;

			return;


		}
		else if (index == ctr && before_index == NULL) {
			before_before_index->next = creatNode(data);
			return;
		}
		else if (before_index == NULL && index > ctr && ctr>1) {
			printf("invalid input size!\n");
			return;
		}
		before_before_index = before_index;
		before_index = index_pointer;
		if(index_pointer)
			index_pointer = index_pointer->next;

		ctr++;
	}

}

void delet(int index) {
	if (index > link_size()-1 || index < 0) {
		printf("####....invalid input size!....####\n");
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
			printf("invalid input size!\n");
			return;
		}

		before_index = index_pointer;
		index_pointer = index_pointer->next;

		ctr++;
	}
}
Node* Max() {
	Node* ans = NULL, * index = head->next;
	int x;
	if (head == NULL) {
		printf("list is empty!!");
		return;
	}
	x = head->data;
	ans = head;
	while (1) {
		if (index == NULL) {
			return ans;
		}
		if (index->data > x) {
			ans = index;
			x = index->data;
		}
		index = index->next;

	}
}

int average() {
	if (head == NULL) {
		printf("list is empty!!");
		return;
	}
	int ctr = 1, sum = 0;
	Node* index = head->next;
	sum += head->data;
	while (1) {
		if (index == NULL) {
			return sum / ctr;
		}
		sum += index->data;
		ctr++;
		index = index->next;
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

void swap(int index1, int index2) {
	Node* _1 = NULL, * _2 = NULL, * index = head;
	int ctr = 0, temp;;

	if (index1 == index2)
		return;
	while (1) {
		if (index == NULL)
			break;
		if (index1 == ctr) {
			_1 = index;
		}
		if (index2 == ctr) {
			_2 = index;
		}
		ctr++;
		index = index->next;
	}
	if (_1 == NULL || _2 == NULL) {
		return;
	}
	else {
		temp = _1->data;
		_1->data = _2->data;
		_2->data = temp;
	}
	return;
}
void print() {
	if (!head) {
		printf("list is empty!\n");
		return;
	}
	Node* index = head;
	int ctr = 0;
	while (index) {
		printf("%d: ",ctr);
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
	int a, b;
	while (1) {
		printf("salam dash\nenter the option's number to choose it\n");
		printf("0-exit\n");
		printf("1-push front\n");
		printf("2-push back\n");
		printf("3-pop front\n");
		printf("4-pop back\n");
		printf("5-insert node\n");
		printf("6-delete node\n");
		printf("7-swap two nodes\n");
		printf("8-average\n");
		printf("9-search\n");
		printf("10-max\n");
		printf("11-print all\n");
		printf("12-kill all data\n");
		printf("enter the number:");
		scanf("%d", &a);
		printf(".....................................................\n");
		switch (a)
		{
		case 0:
			kill_list();
			return 0;
		case 1:
			printf("enter the data as an int:");
			scanf("%d", &a);
			push_front(a);
			break;
		case 2:
			printf("enter the data as an int:");
			scanf("%d", &a);
			push_back(a);
			break;
		case 3:
			pop_front();
			break;
		case 4:
			pop_back();
			break;
		case 5:
			printf("enter the data as an int:");
			scanf("%d", &a);
			printf("where to insert the data? enter the index:");
			scanf("%d", &b);
			insert(a, b);
			break;
		case 6:
			printf("enter the index of the node you want to delete:");
			scanf("%d", &a);
			delet(a);
			break;
		case 7:
			printf("to swap two node's data enter their index in this form:\"x y\"\nenter them now: ");
			scanf("%d %d", &a, &b);
			swap(a, b);
			break;
		case 8:
			printf("%d\n", average());
			break;
		case 9:
			printf("enter the data as an int:");
			scanf("%d", &a);
			printf("%d\n", search(a));
			break;
		case 10:
			printNode(Max());
			printf("\n");
			break;
		case 11:
			print();
			break;
		case 12:
			kill_list();
			break;
		default:
			printf("#################################\nwrong input! please try again\n#################################\n");
			break;
		}
		printf(".....................................................\n");


		//_sleep(1500);
	}




	kill_list();
	//free();
	return 0;
}
