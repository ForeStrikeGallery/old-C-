#include<iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
	
};


class stack{
	private:
		struct node* top;
		
	public:
		stack();
		void push(int x);
		int pop();
		int findMax();
		void display();	
};

void stack :: display()
{
	struct node* temp = top;

	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

stack :: stack()
{
	top = NULL;
}

void stack :: push(int x)
{	
	node *new_node = new node();
	new_node->data = x;
	new_node->next = NULL;
	if(top == NULL)
	{
		top = new_node;
	}
	else
	{
		new_node->next = top;
		top = new_node;		
	}
}

int stack :: pop()
{
	
	node *temp = new node;	
	if(top == NULL)
		return -1;
	else
	{
		
		temp = top;
		top = temp->next;
		
	}
	return temp->data;
}

int stack :: findMax()
{	
	cout<<top->data<<endl;
	int max = top->data;
	struct node* temp = new node();
	temp = top;
	while(temp != NULL)
	{
		if(temp->data > max)
			max = temp->data; 
		temp = temp->next;
	}

	return max;
}

void enterSortedArray(int *arr, int key)
{
	if(high < low)
	{
		high = low;
		arr[high] = key;
		return ;
	}

	high++;
	
	int i = high -1;
	while(i>=low && key<arr[i])
	{
		arr[i+1] = arr[i];
		i--;
	}
	arr[i+1] = key;
	
}

void popMax(int *arr)
{
	return arr[low++];                                                                                                         
}

int low = 0;
int high = 0;

int main()
{
 stack S;
 int T;
 int arr[T];

 cin>>T;
 while(T--)
 {
	int c,d;
	cin>>c;
	switch(c)
	{
		case 1: 
			cin>>d;
			S.push(d);
			arr(d);
			S.display();
			break;
		case 2:
			S.pop();
			
			S.display();
			break;
		case 3:
					
			cout<<S.findMax()<<endl;
			S.display(); 	
	}
 }
 
 return 0;
}
