#include<iostream>

using namespace std;

int printer(int **p)
{
	cout<<**p<<" "<<*p<<" "<<p<<" "<<&p;
	**p = 5;
	
}

int printer2(int *p)
{
	cout<<*p<<" "<<p<<" "<<&p;
}
int main()
{
 int *ptr, t = 4;
 ptr = &t;
 cout<<&ptr<<" "<<ptr<<" "<<&t<<" "<<endl;
 printer(&ptr);
 
 cout<<" "<<*ptr;

}



