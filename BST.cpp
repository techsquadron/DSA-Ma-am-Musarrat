// basic code for binary trees 
#include<iostream>
using namespace std;
struct node
{
	int data;
	node *lchild = NULL;
	node *rchild = NULL;
	
} *root= NULL;

void find(int item, node *&parent, node *&loc)
{
	if(root == NULL)
	{
		loc = root;
		parent = NULL;
		return ;
	}
	
	else if(root->data == item)
	{
		loc = root;
		parent = NULL;
		return;
	}
	else if(root->data < item )
	{
		loc = root->rchild;
		parent = root;
	}
	else
	{
		loc = root->lchild;
		parent = root;
	}
	
	while( loc != NULL)
	{
		if(loc->data == item)
		{
			return ;
		}
		else if(loc->data < item)
		{
			parent = loc;
			loc = loc->rchild;
		}
		else
		{
			parent = loc;
			loc = loc->lchild;
		}
	}
}

void insert(int item)
{
	node *temp, *parent = NULL, *loc = NULL;
	
	find(item, parent, loc);
	
	if(loc != NULL)
	{
		cout<<"Item Already Exist"<<endl;
		return ;
	}
	
	temp = new (struct node );
	temp->data = item;
	if(parent == NULL)
	{
		root = temp;
	}
	else
	{
		if(parent->data < item)
		{
			parent->rchild = temp;
		}
		else
		{
			parent->lchild = temp;
		}
	}
}

void case_a(node *&parent, node *&loc) //if node has no child (leaf node)
{
	if(parent == NULL) //item to be deleted is root node 
	{
		root = NULL;
	}
	else
	{
		if(parent->lchild == loc)
		{
			parent->lchild = NULL;
		}
		else
		{
			parent->rchild = NULL;
		}
	}
}

void case_b(node *&parent, node *&loc) //if node has only 1 child 
{
	node *child;
	
	if(loc->lchild == NULL)
	{
		child = loc->rchild;
	}
	else
	{
		child = loc->lchild;
	}
	if(parent == NULL)
	{
		root = child;
	}
	else
	{
		if(parent->lchild == loc)
		{
			parent->lchild = child;
		}
		else
		{
			parent->rchild = child;
		}
	}
}

void case_c(node *&parent, node *&loc)
{
	node *ptr, *ptrsave;
	node *suc , *parsuc;
	
	ptrsave = loc;
	ptr = loc->rchild;
	
	while(ptr->lchild != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->lchild;
	}
	
	suc = ptr;
	parsuc = ptrsave;
	
	if(suc->lchild == NULL && suc->rchild == NULL) //delete the inorder successor 
	{
		case_a(parsuc , suc);
	}
	else
	{
		case_b(parsuc , suc);
	}
	
	if(parent == NULL) //item to be deleted is root node 
	{
		root = suc;
	}
	else
	{
		if(parent->lchild == loc)
		{
			parent->lchild = suc;
		}
		else
		{
			parent->rchild = suc;
		}
	}
	suc->lchild = loc->lchild;
	suc->rchild = loc->rchild;
}

void del(int item)
{
	node *parent, *loc;
	
	if(root == NULL)
	{
		cout<<"Tree is empty! "<<endl;
		return;
	}
	
	find(item, parent, loc);
	
	if(loc->lchild == NULL && loc->rchild == NULL)
	{
		case_a(parent, loc);
	}
	else if(loc->lchild != NULL && loc->rchild == NULL)
	{
		case_b(parent, loc);
	}
	else if(loc->lchild == NULL && loc->rchild != NULL)
	{
		case_b(parent, loc);
	}
	else //(loc->lchild != NULL && loc->rchild != NULL)
	{
		case_c(parent, loc);
	}
	delete(loc);
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
		cout<<ptr->data<<"  ";
		inorder(ptr->rchild);
	}
}

void preorder(node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	else
	{
		cout<<ptr->data<<"  ";
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}

void postorder(node *ptr)
{
	if(ptr == NULL)
	{
		return;
	}
	else
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		cout<<ptr->data<<"  ";
	}
}

int main()
{
	int choice , n, a;
	int count ;
	//root = NULL;
	
	while(1)
	{
		cout <<endl;
		cout << "Enter your choice: "<<endl;
        cout << "1.  Insert " <<endl;
        cout << "2.  Delete " <<endl;
        cout << "3.  Inorder Traversal " <<endl;
        cout << "4.  Preorder Traversal " <<endl;
        cout << "5.  Postorder Traversal " <<endl;
        cout << "6.  Quit " <<endl;
        cin >> choice;
        switch(choice) 
        {
        	case 1: 
        	      cout<<"Enter the Number you want to insert : ";
        	      cin>>n;
        	      insert(n);
        	      break;
				  
        	case 2:
        		cout<<"Enter the Node you want to delete : ";
        		cin>>n;
        		del(n);
        		break;
        		
        	case 3:
        		cout<<" Inorder Traversal : "<<endl;
        		inorder(root);
        		cout<<endl;
        		break;
        		
        	case 4:
        		cout<<" Preorder Traversal : "<<endl;
        		preorder(root);
        		cout<<endl;
        		break;
        		
        	case 5:
        		cout<<" Postorder Traversal : "<<endl;
        	    postorder(root);
        	    cout<<endl;
        		break;
        		
        	case 6:
        		exit(1);
        	
	        default:
			    cout<<"Invalid Choice !"<<endl;	  
        }
    }
}
        		