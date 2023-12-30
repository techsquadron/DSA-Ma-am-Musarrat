// Queue implementation using Arrays (FIFO)
#include<iostream>
using namespace std;

int front = -1;
int rear = -1;
int n=10;
int arr[10];

void insert(int val)
{
	
}

int main()
{
	int choice;
	int m;
	while(1)
	{
		cout<<endl;
		cout<<"Enter your choice :"<<endl;
		cout<<"1) Insert "<<endl;
		cout<<"2) Delete "<<endl;
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
		        	insert(m);
		           }
		           break;
						
			case 2:
				   del();
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
