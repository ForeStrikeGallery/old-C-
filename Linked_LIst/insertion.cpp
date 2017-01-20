#include<iostream>

using namespace std;

struct node{
	int data;
	node *next;
};

void append(struct node **head_ref, int data)
{
	struct node* new_node = new node();
	new_node->data = data;
	
	new_node->next = (*head_ref); // Next of new_node should point to where head used to point.
	(*head_ref) = new_node; // making head pointer point to new_node	
}


void insertAfter(struct node* prev_node, int data) // not reference to pointer as we're not changing prev node. Only changing prev_node->next; 
{
	if(prev_node == NULL)
		return;

	struct node *new_node = new node();
	new_node->data = data;
	new_node->next = prev_node->next;

	prev_node->next = new_node;	
	
	
}

void insertLast(struct node** head_ref, int new_data )
{
	struct node *new_node = new node();
	struct node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	while(last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
}

void traverse(node *head)
{
 	while(head != NULL)
	{
		
		cout<<head->data<<"-->";
		head = head->next;
	}
}

void deleteNode(struct node **head_ref,int key)
{
	struct node* temp = *head_ref;
	struct node* prev = new node();
	if(temp != NULL && temp->data == key)
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

		if(temp == NULL) return;
		
		prev->next = temp->next;
		delete temp; 
		
	}
}

int findLength(struct node* head)
{
	int count = 0;
	struct node* temp = head;
	while(head != NULL)
	{
		count++;
		cout<<head->data<<" ";
		head = head->next;
	}
	return count;

}

int main()
{
	
	struct node* map = NULL;
	append( &map,33);
	append( &map,44);
	traverse(map);
	cout<<findLength(map);
		

}
