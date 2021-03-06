#include<iostream>
#include<string>
using namespace std;

struct Node{
	char data;
	struct Node* next;
};  	


class Stack 
{
	private:
		Node* top;
	public:
		Stack();
		void push(char x);
		void pop();
		char peek();
		void display();
};

Stack :: Stack(){
	top = NULL;
}

char Stack :: peek(){
	if( top == NULL)
		return '0';
	return top->data;
}

void Stack :: push(char x){
	
	Node *new_node = new Node();
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

void Stack :: display()
{
	struct Node* temp = top;

	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}


void Stack :: pop(){

	Node *temp = new Node;	
	if(top == NULL)
		return;
	else
	{
		
		temp = top;
		top = temp->next;
		
	}
}

char rev(char c){
	if (c == ']')
		return '[';
	else if(c == '}')
		return '{';
	else if(c == ')')
		return '(';
	else
		return 'I';	
}

int main()
{
 int T;
 string S;
 
 cin>>T;
 while(T--)
	{
		Stack st;	
		cin>>S;
		for(int i=0;i<S.length();i++)
		{
			
			if(st.peek() == rev(S[i])){
				st.pop();
				
			}
			else{
			st.push(S[i]);
			
			}
			
			
		
		}

		if(st.peek() == '0')
			cout<<"YES";
		else
			cout<<"NO";
		
		
	}
 
 return 0;
}
