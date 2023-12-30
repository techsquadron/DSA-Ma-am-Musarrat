// Binary search in arrays using iterative method 
#include<iostream>
using namespace std;

int main()
{
	int arr[10];
	int n, mid, start, end, loc;
	start = 0;
	end = 9;
	loc = -1;
	
	for(int i=0; i<10; i++)
	{
		cout<<"Enter integer :  ";
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Array Elements : "<<endl;
	for(int i=0; i<10; i++)
	{
		cout<<arr[i]<<endl;
	}
	cout<<endl;
	cout<<"Enter number you want to find"<<endl;
	cin>>n;
	while(start<=end)
	{
		mid = (start + end)/2;   // middle point
		if(arr[mid]==n)
		{
			loc = mid;
			break;
		}
		else if(n<arr[mid])
		     end = mid -1;
		else
		     start = mid +1;
		
	}
	if(loc == -1)
	{
		cout<<n<<"not found!"<<endl;
	}
	else
	cout<<n<<" Found at index "<<loc<<endl;
}
