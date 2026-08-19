#include<iostream>
using namespace std;

struct Node {

     int item ; /* integer value stored at node */

     Node* next;  /* the link field */

  } ;

typedef Node *link;

int AllIdentical(link h)
{
	int value=h->item;
	link temp=h->next;
	
	while(temp!=NULL)
	{
		if(temp->item!=value)
		return 0;
		temp=temp->next;
	}
	return 1;
}

Node* newNode(int val)
{
	Node* n = new Node;
	n->item = val;
	n->next = NULL;
	return n;
}
int main()
{
	Node* head = newNode(10);
	head->next = newNode(10);
	head->next->next = newNode(10);
	
	cout<<"list 1 : 10 -> 10 -> 10 -> NULL\n";
	cout<<"AllIdentical = "<<AllIdentical(head)<<endl;
	cout<< "        \n";
	return 0;
}