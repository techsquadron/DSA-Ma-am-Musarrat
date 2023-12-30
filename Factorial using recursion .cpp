// factorial of a number using recursion 
#include<iostream>
using namespace std;


int factorial(int k)
{
	int fact = 1;
	if(k>1)
	fact = k*factorial(k-1);
	return (fact);
}


int main()
{
	int n , val;
	cout<<"Enter the number: ";
	cin>>n;
	if(n<0)
	{
		cout<<"No factorial of negative number !"<<endl;
	}
	else
	if(n == 0)
	{
		cout<<"Factorial of zero is 1 "<<endl;
	}
	else
	{
		val = factorial(n);
		cout<<"Factorial of "<<n<< " = "<<val;
	}
	
}
