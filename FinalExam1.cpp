#include<iostream>
using namespace std;


struct node 
{
	int item;
	node* next;
	
	node(int x)
	{
		item = x;
		next = 0;
	}
};
typedef node* link;


void traverse(link h) //function to traverse the list
{
	while(h != 0)
	{
		cout<< h->item << " ";
		h = h->next;
	}
	cout<< "\n";
}



void DeleteLastIfIdenticalTwo(link h) //Deletes the last node only if the last nodes are identical
{
	if(!h || !h->next)    //checks if list at least has two nodes
	return;
	
	link p=h;        //second-last node
	link q=h->next;   // last node
	
	while(q->next != 0)
	{
		p=q;
		q=q->next;
	}
	
	if(p->item == q->item)   // delete last node if last two nodes are identical
	{
		p->next = 0;
		delete q;
	}
}

int main()
{
    // Build a sample list for demonstration
    link h = new node(10);
    h->next = new node(30);
    h->next->next = new node(30);
    h->next->next->next = new node(30);   // last two identical

    cout << "Original list: ";
    traverse(h);

    DeleteLastIfIdenticalTwo(h);

    cout << "After deletion: ";
    traverse(h);

    return 0;
}

