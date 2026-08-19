#include<iostream>
using namespace std;

struct Node
{
	int index,value;
	Node* next;
};


void insert(Node*& head,int inx,int val)
{
	Node* newNode = new Node;
	newNode->index = inx;
	newNode->value = val;
	newNode->next = nullptr;
	
	if(head == nullptr)
	{
		head=newNode;
	}
	else
	{
		Node* temp=head;
		while(temp->next != nullptr)
		temp=temp->next;
		temp->next=newNode;
	}
	
}

int dotProduct(Node* A,Node* B)
{
	int product = 0;
	Node* p = A;
	Node* q = B;
	

  while(p != nullptr && q != nullptr )
  {
	if(p->index == q->index)
	{
		product += p->value * q->value;
		p=p->next;
		q=q->next;
	}
	else if(p->index < q->index)
	{
		p=p->next;
	}
	else
	{
	   q=q->next;	
	}
  }
  return product;
}


	
int main()
{
	int n;
	cout<<"Input n: ";
	cin>>n;
	
	Node* A=nullptr;
	Node* B=nullptr;
	
	int countA,countB;
	cout<<"Enter number of non-zero elements in A: ";
	cin>>countA;
	cout<<"Enter Index and Value pairs for A:\n";
	
	for(int i=0;i<countA;i++)
	{
		int inx,val;
		cin>>inx>>val;
		if(inx>n)
		{
			cout<<"Index "<< inx << " is out of bounds \n";
		}
		else 
		{
		insert(A,inx,val);
	    }
	}
	
	cout<<"\n Enter number of non-zero elements in B: ";
	cin>>countB;
	cout<<"Enter Index and Value pairs for B:\n";
	for(int i=0;i<countB;i++)
	{
		int inx,val;
		cin>>inx>>val;
			if(inx>n)
		{
			cout<<"Index "<< inx << " is out of bounds \n";
		}
		else 
		{
		insert(B,inx,val);
	    }
		
	}
	
	int result = dotProduct(A,B);
	cout<<"\n Dot product of A and B is : "<<result<<endl;
		
	return (0);				
}


/* ------Sample run------

Input n: 10
Enter number of non-zero elements in A: 4
Enter Index and Value pairs for A:
2 5
3 4
4 7
9 2

Enter number of non-zero elements in B: 4
Enter Index and Value pairs for B:
2 1
3 5
8 3
9 7

Dot product of A and B is : 39

*/



















