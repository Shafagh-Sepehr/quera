#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//////////////
typedef struct tree {
	struct tree * prev,**child;
	int data,childcount;
}node;
node* head,*INDEX;
//////////////

node* create_node(int data) {
	node* p;
	p = (node*)malloc(sizeof(node));
	p->data = data;
	p->childcount = 0;
	p->prev =p->child= NULL;
	return p;
}



void add_kid(int data) {
	node* kid;
	//if(INDEX->child)
		INDEX->child = (node**)realloc(INDEX->child, (INDEX->childcount + 1) * sizeof(node*));
	//else
	//	INDEX->child= (node**)calloc(1, sizeof(node*));
	INDEX->child[INDEX->childcount]=kid = create_node(data);
	kid->prev = INDEX;
	INDEX->childcount+=1;
	return;
}


int main() {
	printf("salam dadash\nALERT: this program should be given the orders it can run or it will break. so if there is not a child[m] don ask the program to print it. I was a (((little bit tired))) and didnt add options to the program to avoid errors. it's easy but I had done it in another program so you know that I can do it.\n");
	int n, a, b;
	printf("enter head data:");
	scanf("%d", &a);
	head = create_node(a);
	INDEX = head;
	while (1) {
		printf("salam dash\nenter the option's number to choose it\n");
		printf("0-exit\n");
		printf("1-go to child[n]\n");
		printf("2-go back\n");
		printf("3-add child\n");
		printf("4-print child[n]\n");
		printf("5-print self\n");
		printf("enter the number:");
		scanf("%d", &a);
		printf(".....................................................\n");
		
		switch (a)
		{
		case 0:
			return 0;
		case 1:
			printf("enter the child's number starting from 0:");
			scanf("%d", &a);
			INDEX = INDEX->child[a];
			break;
		case 2:
			INDEX = INDEX->prev;
			break;
		case 3:
			printf("enter the data:");
			scanf("%d", &n);
			add_kid(n);
			break;
		case 4:
			printf("enter the child's number starting from 0:");
			scanf("%d", &a);
			printf("%d\n", INDEX->child[a]->data);
			break;
		case 5:
			printf("%d\n", INDEX->data);
			break;
		case 6:
			scanf("%d", &a);
			head = create_node(a);
			break;

		default:
			printf("#################################\nwrong input! please try again\n#################################\n");
			break;
		}
		printf(".....................................................\n");


		//_sleep(1500);
	}


	//free();
	return 0;
}
