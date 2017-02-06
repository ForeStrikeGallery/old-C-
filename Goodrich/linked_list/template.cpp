#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
	int data;
	struct node* next;
}

void push_at_beg(struct node** head_ref, int data) {
	struct node* new_node = new node();
	new_node->data = data;
	new_node->next = (*head_ref)
	(*head_ref) = new_node;
}

void push_at_given(struct node* prev_node, int data) {
	struct node* new_node = new node();
	new_node->data = data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void push_at_end(struct node** head_ref, int data){
	struct node* new_node = new node();
	struct node* last = *head_ref;
	new_node->data = data;
	new_node->next = NULL;

	while(last->next != NULL) {
		last = last->next;
	}

	if (*head_ref == NULL ) {
		*head_ref = new_node;
		return;
	}

	last->next = new_node;
}

	

int main() {
	return 0;
}