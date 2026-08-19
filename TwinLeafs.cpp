#include<iostream>
using namespace std;

struct node   // Tree node definition
{
	int item;
	node *l,*r; // l - left child ,r - right child
	node(int x)
	{
		item = x;
		l=0;
		r=0;
	}
};
typedef node* link;

class QUEUE // QUEUE class interface
{
    private:
		struct qnode
		{
			link item;
			qnode *next;
			qnode(link x)
			{
				item=x;
				next=0;
			}
		};
		qnode *head, *tail;
		
	public:
		QUEUE(int)
		{
			head=0;
			tail=0;
		}
			
		int empty() const
		{
			return head==0;
		}
			
		void put(link x)
		{
			qnode *t=tail;
			tail=new qnode(x);
			if(head==0)
			{
				head=tail;
			}
			else
			{
				t->next=tail;
			}
		}
			
		link get()
		{
			link v=head->item;
			qnode *t=head->next;
			delete head;
			head=t;
			return v;
		}
						
};

int TwinLeafsFound(link root,int n) // function to return 1 if two leaf nodes are identical otherwise return 0
{
	if(root==0)
	
	return 0;
    
	
	link h;
	QUEUE q(n);
	q.put(root);
	
	while(!q.empty())
	{
	h=q.get();
	if(h->l !=0 && h->r !=0)
	{
		link a=h->l;
		link b=h->r;
			
		if(a->l == 0 && a->r == 0 && b->l == 0 && b->r == 0) //checks if both children are leaf nodes
		{
			if(a->item == b->item)//return 1 if twin leaf-nodes found
				
			return 1;		
		}
	}
		
		if(h->l != 0)
		q.put(h->l);
		
		if(h->r != 0)
		q.put(h->r);
	}

return 0; // if  two leaf-nodes are not identical
}



int main()
{
	link root = new node(5);
	root->l = new node(5);
	root->r = new node(7);
	
	int ans = TwinLeafsFound(root,50);
	cout<<"twin leafs found: "<<ans<<endl;
	return 0;
}













