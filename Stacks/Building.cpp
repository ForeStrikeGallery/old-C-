#include<iostream>

using namespace std;

struct Node{
	int data;
	int max;
	struct Node* front;
	struct Node* back;
};

void Insert( Node **head_ref, int height)
{
	Node *temp = new Node;
	temp->data = height;
	temp->front = NULL;
	temp->back = NULL;

	Node *tem = *head_ref;

	if(*head_ref == NULL)
		*head_ref = temp;
	else{
		temp->front = *head_ref;
		tem->back = temp;
		*head_ref = temp;
	}

}

void traverse(Node * head){
	Node * temp = head;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->front;
	}
}
int main()
{
	Node * head = NULL;	
	
	int N, height;
	cin>>N;
	for(int i=0;i<N;i++){
		Node * temp = new Node;
		cin>>height;
		Insert(&head, height);
		traverse(head);
	}
	
}
