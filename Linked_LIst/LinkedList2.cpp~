#include<iostream>

using namespace std;

struct node{
	int data;
	struct node* next;
};


void push(struct node **head_ref, int data)
{
	struct node* new_node = new node();
	
	new_node->data = data;
	

	new_node->next = *head_ref;
	*head_ref = new_node;

}

void insertAt(struct node *prev, int data)
{
	struct node* temp = prev;
	if( temp == NULL)
		return;

	struct node* new_node = new node();
	new_node->data = data;
	
	new_node->next = prev->next;
	prev->next = new_node;

}

void deleteNode(struct node **head_ref, int key)
{
	struct node *temp = *head_ref;
	struct node* prev = new node();
	if( temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;
		delete temp;
		return;
	}
	else
	{
		while(temp != NULL && temp->data != key)
		{
			prev = temp;
			temp = temp->next;
		}

		if(temp == NULL)
			return;
		
		prev->next = temp->next;
		delete temp;
		return;
	}
}

void traverse(node *head)
{
 	while(head->next != NULL)
	{
		
		cout<<head->data<<"-->";
		head = head->next;
	}
}


int main()
{
	struct node* head = new node();
	push(&head,44);
	push(&head,55);
	insertAt(head,55);
	deleteNode(&head,44);
	traverse(head);

	

}









