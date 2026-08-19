#include<iostream>
using namespace std;

struct node
{
	int item;
	node *l, *r;
	int level;
	
	node(int x)
	{
		item = x;
		l=0;
		r=0;
		level=0;
	}
};
typedef node* link;

template<class Item>
class QUEUE
{
	private:
		struct qnode
		{
			Item item;
			qnode *next;
			qnode(Item x)
			{
				item = x;
				next = 0;
			}
		};
		qnode *head, *tail;
		
		public:
			QUEUE(int)
			{
				head = 0;
				tail = 0;
			}
			
			int empty() const
			{
				return head == 0;
			}
			
			void put(Item x)
			{
				qnode *t=tail;
				tail = new qnode(x);
				if(head == 0)
				{
				head = tail;
			    }
				else
				{
				t->next = tail;
			    }
				
			}
		
		Item get()
		{
			Item v=head->item;
			qnode *t= head->next;
			delete head;
			head = t;
			return v;
		}
	};
	
	void traverse(link root,int n)
	{
	    link h;	
		QUEUE<link> q(n);
		q.put(root);
		
		while(!q.empty())
		{
			h=q.get();
			cout<<h->item<< " ";
			if(h->l !=0) q.put(h->l);
			if(h->r !=0) q.put(h->r);
			
		}
	}


link findNode(link root,int x)
{
	if(root == 0)
	return 0;
	
	QUEUE<link> q(500);
	q.put(root);
	
	while(!q.empty())
	{
		link h=q.get();
		if(h->item == x)
		return h;
		
		if(h->l != 0)
		q.put(h->l);
		
		if(h->r !=0)
		q.put(h->r);	
		
	}
	return 0;
}


int computeHeight(link root)
{
	if(root == 0)
	return 0;
	
	QUEUE<link> q(500);
	root->level = 1;
	q.put(root);
	
	int maxlevel = 1;
	
	while(!q.empty())
	{
		link h = q.get();
		
		if(h->level > maxlevel)
		maxlevel = h->level;
		
		if(h->l != 0)
		{
			h->l->level = h->level + 1;
			q.put(h->l);
		}
		
		if(h->r != 0)
		{
			h->r->level = h->level + 1;
			q.put(h->r);
		}
	}
	
	return maxlevel;
}

int main()
{
	link root = 0;
	char cmd;
	
	while(cin >> cmd)
	{
		if(cmd == 'C')
		{
		int r;
		cin>>r;
		
		if(root != 0)
		{
			cout<< "Error : Tree is not empty\n";
		}	
		else
		{
			root = new node(r);
			cout<<"Root node with item "<< r <<" has been created\n";
		}
		}
		
		else if(cmd == 'L')
		{
			int p,l;
			cin>>p>>l;
			
			link u=findNode(root,p);
			if(u==0)
			{
				cout<<"Error : Parent not found\n";
			}
			
			else if(u->l != 0)
			{
				cout<<"Error : left child exists\n";
			}
			
			else
			{
				u->l = new node(l);
				cout<<"Node with item "<< l <<" has been added\n";
			}
		}
		else if(cmd == 'R')
		{
			int p,r;
			cin>>p>>r;
			
			link u = findNode(root,p);
			if(u==0)
			{
				cout<<"Error : Parent not found\n";
			}
			else if(u->r != 0)
			{
				cout<<"Error : right child exists\n";
			}
			else
			{
				u->r = new node(r);
				cout<<"Node with item "<< r << " has been added\n";
				
			}
		}
		
		else if(cmd == 'P')
		{
			cout<<"Level order traversal: ";
			traverse(root,500);
			cout<<"\n";
			
			int height = computeHeight(root);
			cout<<"The tree height is "<<height<<" (using the level order traversal of the entire tree)";
			cout<<"\n";
		}
		
	
	}
	return 0;
}





/*----------------------Sample Run----------------------

C 5
Root node with item 5 has been created
C 10
Error : Tree is not empty
L 5 3
Node with item 3 has been added
R 5 4
Node with item 4 has been added
P
Level order traversal: 5 3 4
The tree height is 2 (using the level oder traversal of the entire tree)
L 4 7
Node with item 7 has been added
R 7 8
Node with item 8 has been added
R 3 9
Node with item 9 has been added
L 9 11
Node with item 11 has been added
R 4 12
Node with item 12 has been added
L 7 13
Node with item 13 has been added
L 8 14
Node with item 14 has been added
R 12 15
Node with item 15 has been added
R 8 16
Node with item 16 has been added
L 13 17
Node with item 17 has been added
P
Level order traversal: 5 3 4 9 7 12 11 13 8 15 17 14 16
The tree height is 5 (using the level order traversal of the entire tree)
L 14 19
Node with item 19 has been added
P
Level order traversal: 5 3 4 9 7 12 11 13 8 15 17 14 16 19
The tree height is 6 (using the level order traversal of the entire tree)
L 15 8
Node with item 8 has been added
P
Level order traversal: 5 3 4 9 7 12 11 13 8 15 17 14 16 8 19
The tree height is 6 (using the level order traversal of the entire tree)
R 20 1
Error : Parent not found


--------------------------------------------------------------------------------*/












