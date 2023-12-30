// Stack implementation using Arrays (LIFO)
#include<iostream>
using namespace std;

int top = -1;
int n=10;
int arr[10];

void push(int item)
{
	if(top == (n-1))
	{
		cout<<"Stack Overflow!"<<endl;
	}
	else
	{
		top = top+1;
		arr[top] = item;
	}
}

void pop()
{
	if(top == -1)
	{
		cout<<"Stack Underflow!"<<endl;
	}
	else
	{
		cout<<"Popped element is :"<<arr[top]<<endl;
		top = top-1;
	}
}

void display()
{
	if(top == -1)
	{
		cout<<"Stack is empty "<<endl;
	}
	else
	{
		cout<<"Stack Elements :"<<endl;
		for(int i=top; i>=0 ; i-- )
		{
			cout<<arr[i]<<endl;
		}
	}
}

int main()
{
	int choice;
	int m;
	while(1)
	{
		cout<<endl;
		cout<<"Enter your choice :"<<endl;
		cout<<"1) Push "<<endl;
		cout<<"2) Pop "<<endl;
		cout<<"3) Display "<<endl;
		cout<<"4) Quit "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: 
			       cout<<"Enter the number of elements you want : ";
		           cin>>n;
		           for(int i=0 ; i<n ; i++)
		           {
		         	cout<<"Enter element : ";
		        	cin>>m;
		        	push(m);
		           }
		           break;
						
			case 2:
				   pop();
				   break;
			
			case 3:
				  display();
				  break;
				  
			case 4:
				  exit(1);
				  
			default: 
			      cout<<"Invalid Choice !"<<endl;
			
		}
	}

}
