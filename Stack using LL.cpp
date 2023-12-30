// Stack implementation using linked list (LIFO)
#include<iostream>
using namespace std;

struct stack
{
	int data;
	node *link;
	
}*top;

void pop()
{
	node *tmp;
	if (top == NULL)
	{
		cout<<"Stack is Empty !"<<endl;
	}
	else
	{
		tmp= top;
		cout<<"Popped item is : "<<tmp->data<<endl;
		top = top->link;
		delete(tmp);
		
	}
}

void push(int val)
{
	node *tmp;
	tmp = new (struct node);
	tmp->data = val;
	tmp->link = top;
	top = tmp;
}


void display()
{
	node*q;
	q = top;
	if(top == NULL)
	{
		cout<<"Stack is Empty !"<<endl;
		
	}
	else
	{
		cout<<"Stack Elements :"<<endl;
		while(q!=NULL)
		{
			cout<<q->data<<" "<<endl;
			q = q->link;
		}
	}
}

int main()
{
	int n , m , choice;
	while(1)
	{
	cout<<"..... Enter your choice ..... "<<endl;
	cout<<endl;
	cout<<"1. Push  "<<endl;
	cout<<"2. Pop "<<endl;
	cout<<"3. Display "<<endl;
	cout<<"4. Quit "<<endl;
	cout<<endl;
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