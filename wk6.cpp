//include library
#include<iostream>

using namespace std;

//create class for Node
class Node
{
      public:
	//initialization
	int data;
	Node *lft;
	Node *rgt;
	//create constructor
	Node(int val)
	{
		data=val;
		lft=NULL;
		rgt=NULL;
	}
};

//create class for binary searching tree
class BST
{
      public:
	Node *root;
	//creating constructor
	BST()
	{
		root=NULL;
	}

	//creating function to help in insertion of values in tree
	void inserthpr(int val)
	{
		insert(root,val);
	}

	//creating function to insert value
	void insert(Node *cur,int val)
	{
		//if root is null then create a new node as root
		if(root==NULL)
			root=new Node(val);
		else
		//decide to go left or right
		{
			if(val<cur->data)
			//have to go left
			{
				//if left side is null then create a new node and link it
				if(cur->lft==NULL)
					cur->lft=new Node(val);
				else
				//move left and insert value there
					insert(cur->lft,val);
			}
			else
			//have to go right									
			{
				//if right is null then create a new node and link it
				if(cur->rgt==NULL)
					cur->rgt=new Node(val);
				else
				//move right and insert value there
					insert(cur->rgt,val);
			}
		}
	}

	//creating function to help display
	void displayhpr()
	{
		display(root);
	}

	//creating function to display values of tree
	void display(Node *cur)
	{
		//case for empty tree
		if(cur==NULL)
			return;
		//print left
			display(cur->lft);
		//print data
			cout<<cur->data<<" , ";
		//print right
			display(cur->rgt);
	}

	//creating node to help search of tree
	Node *searchhpr(int val)
	{
		return search(root,val);
	}

	//creating node to search the tree
	Node *search(Node *cur,int val)
	{
		//if it's value or null return current
		if(cur==NULL||cur->data==val)
			return cur;
		else
		//search left or right
		//search left
			if(val<cur->data)
				return search(cur->lft,val);
		//search right
			else
				return search(cur->rgt,val);
	}
};

//creating main
int main()
{
	//create object of the class
	BST b;

	//call for the working of the functions in the class
	b.inserthpr(4);	
	b.inserthpr(2);
	b.inserthpr(5);
	b.inserthpr(3);
	b.displayhpr();
	cout<<endl;
	if(b.searchhpr(3)!=NULL)
		cout<<b.searchhpr(3)->data<<endl;
	//terminating main function

	return 0;
}

