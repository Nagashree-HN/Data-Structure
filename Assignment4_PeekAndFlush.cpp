#include<iostream>
using namespace std;

class STACK
{
	private:
		struct node
		{
			int item;
			node* next;
			node(int x,node* t)
			{
				item = x;
				next = t;
			}
		};
		
		typedef node* link;
		link head;
		
	public:	
	    STACK(int)
	    {
	    	head = 0;
		}
		
		int empty() const
		{
			return head == 0;
		}
		
		void push(int x)
		{
			head = new node(x,head);
		}
		
		int peek()
		{
			if (empty())
			{
				cout<<"Stack is empty, nothing to peek "<<endl;
				return -1;
			}
			return head->item;
		}
		
		int pop()
		{
			if(empty())
			{
				cout<<"Nothing to pop off, stack is empty"<<endl;
				return -1;
			}
			int value = head->item;
			link temp = head->next;
			delete head;
			head = temp ;
			return value;
		}
		
		void flush()
		{
			if(empty())
			{
				cout<<endl;
				return;
			}
			
			while(head != NULL)
			{
				cout<<head->item<<" ";
				link temp = head;
				head = head->next;
				delete temp;
			}
			cout<<endl;
		}
};




















