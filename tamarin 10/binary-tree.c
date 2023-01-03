#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#pragma warning(disable:4996)

//////////////
typedef struct tree {
	struct tree* left, * right, * prev;
	int data;
	bool printed;
	//bool self_printed,left_printed,right_printed;
}node;
node* head;
//////////////

node* create_node(int data) {
	node* p;
	p = (node*)malloc(sizeof(node));
	p->data = data;
	p->left = p->right = p->prev = NULL;
	p->printed = false;
	//p->self_printed = p->left_printed = p->right_printed = false;
	return p;
}

void print(node* ind) {
	printf("%d ", ind->data);
	return;
}

void add_node(int ndata) {
	node* index = head, *index_prev = NULL;
	if (head == NULL) {
		head = create_node(ndata);
		return;
	}
	while (index!=NULL) {
		if (index->data <= ndata) {//ndata is bigger. go right
			index_prev = index;
			index = index->right;
			if (index == NULL) {
				index = create_node(ndata);
				index->prev = index_prev;
				index_prev->right = index;
				return;
			}
		}
		else if (index->data > ndata) {//ndata is smaller. go left
			index_prev = index;
			index = index->left;
			if (index == NULL) {
				index = create_node(ndata);
				index->prev = index_prev;
				index_prev->left = index;
				return;
			}
		}
	}
	

}

void in_order_print(int n) {
	node* index = head, * deltemp;
	while (n) {
		if (index->left && index->left->printed==false) {
			index = index->left;
		}
		else if (index->printed == false) {
			print(index);
			index->printed = true;
			n--;
		}
		else if (index->right && index->right->printed == false) {
			index = index->right;
		}
		else {
			deltemp = index;
			index = index->prev;
			free(deltemp);
		}
	}
	return;
}
int main() {
	int n,nh,a;
	scanf("%d", &n);
	nh = n;
	while (n) {
		scanf("%d", &a);
		add_node(a);
		n--;
	}
	in_order_print(nh);

	//free();
	return 0;
}
