#include<iostream>
using namespace std;

struct node{
	int data;	
	node *left;
	node *right;
};




struct node* newNode(int data)
{
	struct node* temp = new node();
	temp->right = NULL;
	temp->left = NULL;
}



int main()
{
 struct node* root = newNode(1);
	root->left = newNode(3);			//to get a revenue

/*


*/
	
 return 0;
}
