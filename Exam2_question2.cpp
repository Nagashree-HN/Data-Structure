


struct node
{
	int item;
	node *l, *r;
	
	node(int x)
	{
		item = x;
		l = 0;
		r = 0;
	}
};
typedef node* link;

template <class Item>  //Queue implementation for level-order traversal
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
		  qnode *t = tail;
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
			Item v = head->item;
			qnode *t =head->next;
			delete head;
			head = t;
			return v;
		}
};

void traverse(link root,int n)   //level-order traversal
{
	if(root == 0)
	return;
	
	QUEUE<link> q(n);
	q.put(root);
	
	while(!q.empty())
	{
	   link h = q.get();
	   cout << h->item << " ";
	   
	   if(h->l != 0) 
	    q.put(h->l);
	   
	   if(h->r != 0)
	    q.put(h->r);
	   
	   }	
	}
	
void DuplicateLeaf(link root,int n)   // function to duplicate every leaf node that does not have a sibling
{
	if(root == 0)
	return;
	
	QUEUE<link> q(n);
	q.put(root);
	
	while(!q.empty())
	{
		link h = q.get();
		
		if(h->l != 0 && h->r == 0) // when h has only left child,check if that child is a leaf 
		{
			link c = h->l;
			if(c->l == 0 && c->r == 0)   // check if left child is a leaf
			{
	
		    	h->r = new node(c->item);  // to duplicate as right sibling
		    }
		}
		
		if(h->r != 0 && h->l == 0) // when h has only right child,check if that child is a leaf
		{
			link c = h->r;
			if(c->l == 0 && c->r == 0)  //check if right child is a leaf
			{
	
		    	h->l = new node(c->item);  // to duplicate as left sibling
		    }
		}
		
		if(h->l != 0) q.put(h->l);
		if(h->r != 0) q.put(h->r);
	}	
	
}









