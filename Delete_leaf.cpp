void DeleteLargestLeaf(link root,int n)
{
	if(root == 0)
	return;
	
    link h;
    QUEUE q(n);
    q.put(root);

    int largest = root->item;
    link tr = 0;

    while(!q.empty())               // to find the leaf with largest value
    {
      h=q.get();

      if(h->l == 0 && h->r == 0)
      {     
        if(h->item > largest)
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









