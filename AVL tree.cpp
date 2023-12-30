//basic code for AVL Tree 
#include<iostream>
using namespace std;

struct node
{
 string name;
 int data;
 int balance;
 node *lchild;
 node *rchild;
 
};

struct node* search(node *ptr, int item)
{
	if(ptr!= NULL)
	{
		if(item < ptr->data)
		{
			ptr=search(ptr->lchild, item);
		}
		else if(item > ptr->data)
		{
			ptr=search(ptr->rchild, item);
		}	
	}
	return (ptr);

}

struct node *insert (int item, node *pptr, bool *ht_inc)
{
	node *aptr;
	node *bptr;
  
	if(pptr == NULL)
	{
		pptr = new (struct node);
		pptr->data = item;
		pptr->lchild = NULL;
	    pptr->rchild = NULL; 
        pptr->balance = 0;
        *ht_inc = true;
        return (pptr);
	}
	
	if(item < pptr->data)
	{
		pptr->lchild = insert(item, pptr->lchild, ht_inc);
		
		if(*ht_inc = true)
		{
			switch(pptr->balance)
			{
				case -1:  //Right Heavy
				   pptr->balance = 0; 
				   *ht_inc = false;
				   break;
				   
				case 0:  //Balanced
			    	pptr->balance = 1;
				    break;
				    
				case 1:  //Left Heavy
				  aptr=pptr->lchild;
				  
				  if(aptr->balance == 1)
				  {
				  	cout<<" Left to Left Rotation "<<endl;
				  	pptr->lchild = aptr->rchild; 
				    aptr->rchild = pptr; 
				    pptr->balance = 0; 
				    aptr->balance=0;
				    pptr = aptr;
				  }
				  else
				  {
				  	cout<<" Left to Right Rotation " <<endl;
				  	bptr = aptr->rchild;
					aptr->rchild = bptr->lchild; 
					bptr->lchild = aptr;
					pptr->lchild = bptr->rchild;
					bptr->rchild = pptr;
					
					if(bptr->balance == 1)
					{
						pptr->balance = -1;
					}
					else
					{
						pptr->balance = 0;
					}
					if(bptr->balance ==	-1)
					{
						aptr->balance = 1;
					}
					else
					{
						aptr->balance = 0;
						bptr->balance = 0;
					    pptr = bptr;
					}
				  }
				  *ht_inc = false;
			}
		}
	}
	
	if(item > pptr->data)	
	{
		pptr->rchild = insert(item , pptr->rchild , ht_inc);
		
		if(*ht_inc == true)
		{
			switch(pptr->balance)
			{
				case 1 : //Left Heavy 
					pptr->balance = 0;
					*ht_inc = false ;
					break;
					
				case 0 :  //Balanced
					pptr->balance = -1;
					break;
					
				case -1 :  //Right Heavy
					aptr = pptr->rchild;
					
					if(aptr->balance == -1)
					{
						cout<<" Right to Right Rotation "<<endl;
			            pptr->rchild = aptr->lchild;
			            aptr->lchild = pptr;
			            pptr->balance=0;
			            aptr->balance=0;
			            pptr= aptr;
					}
					else
					{
						cout<<" Right to Left Rotation ";
						bptr = aptr->lchild;
						aptr->lchild = bptr->rchild;
						bptr->rchild = aptr;
						pptr->rchild = bptr->lchild;
						bptr->lchild = pptr;
						
						if(bptr->balance == -1)
						{
							pptr->balance = 1;
						}
						else
						{
							pptr->balance = 0;
						}
						if(bptr->balance == 1)
						{
							aptr->balance = -1;
						}
						else
						{
							aptr->balance = 0;
							bptr->balance = 0;
						    pptr = bptr;
						}
						
					}
					*ht_inc = false;
			}
		}	
	}
	return(pptr);
}

void display(node *ptr, int level)
{
	if(ptr != NULL)
	{
		display(ptr->rchild , level + 1 ); 
	    cout<<" \n ";
	    
	    for(int i=0 ; i<level ; i++)
	    {
	    	cout <<"    "; 
		}
		cout<< ptr->data;
	    display(ptr->lchild , level + 1);
	}
}

void inorder(node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	else
	{
		inorder(ptr->lchild); 
		cout<<ptr->data<<" "; 
		inorder(ptr->rchild);
	}
}

int main()
{
 bool ht_inc; 
 int info;
 int choice;
 struct node *root = NULL;
 while(1)
  {
  	 cout<<endl;
  	 cout<<"Enter your choice: "<<endl;
	 cout<<"1. Insert "<<endl;
	 cout<<"2. Display "<<endl; 
	 cout<<"3. Quit "<<endl;
	 cin>>choice;
	 switch(choice)
	
	{
		case 1:
			 cout<<" Enter the value to be inserted: ";
			 cin>>info;
			 
			 if(search(root , info) == NULL)
			 {
			   root = insert(info, root, &ht_inc);
			 }
			else
			{
				cout<<" Duplicate value ignored "<<endl;
			}
	       	break;
	       	
		case 2:
		     if(root == NULL)
	    	 {	
		      cout<<" Tree is empty! "<<endl;
		     }
		     else
		     {
		       cout<<" Tree is : "<<endl;
		       display(root, 0);
			   cout<<endl;
			   cout<<" Inorder Traversal is : "<<endl; 
			   inorder(root);
			   cout<<endl;
			 }
			  break;
			  
		case 3:
		     exit(1);
		     
		default:
		     cout<<"Invalid Choice "<<endl;
		     
	}
  }
}
