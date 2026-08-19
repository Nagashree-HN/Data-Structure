Exam 2 :

Question 2 : Write a C++ function void DeleteLargestLeaf(link root, int n) that takes as a parameter a binary tree with n nodes, where root is a pointer to the tree's root. The function deletes the leaf node that has the largest item value over all the leaf nodes in the tree. It is given that the binary tree has at least two nodes. It is also given that all values in the item fields are distinct, although they may lie in any range. Modify the level-order traversal to accomplish this. You may use the following function skeleton but make all necessary changes:    

struct node
{
	int item;
	node *l, *r;
	node(int x)
	{
		item = x;
		l=0;
		r=0;
	}
};
typedef node* link;

class QUEUE      // QUEUE class implementation
{
	private:
		struct qnode
		{
			link item;
			qnode *next;
			qnode(link x)
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
			
			void put(link x)
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
		
		link get()
		{
			link v=head->item;
			qnode *t= head->next;
			delete head;
			head = t;
			return v;
		}
	};
	


void DeleteLargestLeaf(link root, int n)
{
   if(root == 0)
   return;
	
    link h;
    QUEUE q(n);
    q.put(root);

    int largest;
    link tr;
    bool firstLeaf = true;

    while(!q.empty())               // to find the leaf with largest value
    {
         h=q.get();

         if(h->l == 0 && h->r == 0)
            {     
              if(firstLeaf)
                {
                   largest = h->item;
                   tr = h;
                   firstLeaf = false;
                 }
              else if(h->item > largest)
                {
                  largest = h->item;
                  tr = h;
                }
            }

          if(h->l != 0)
          q.put(h->l);
 
          if(h->r != 0)
          q.put(h->r);
   }


QUEUE q2(n);                    //finds the parent and delete the leaf
q2.put(root);

    while(!q2.empty())
    {
	  link p=q2.get();
	
	  if(p->l == tr)
	  { 
	     delete p->l;
	     p->l = 0;
	     return;	
	  }
	
	  if(p->r == tr)
	  {
	   	 delete p->r;
		 p->r = 0;
		 return;
	  }
	
	if(p->l != 0)
	q2.put(p->l);
	
	if(p->r != 0)
	q2.put(p->r);
	
    }
}

