#include<iostream>
using namespace std;

struct Node
{
	int index,value;
	Node* next;
};

void insert(Node*& head,int inx,int val)
{
	Node* newNode=new Node;
	newNode->index=inx;
	newNode->value=val;
	newNode->next=nullptr;
	
	if(head==nullptr)
	{
		head=newNode;
	}
	else
	{
		Node* temp=head;
		while(temp->next!= nullptr)
		temp=temp->next;
		temp->next=newNode;
	}
	
	
}

int dotProduct(Node* A,Node* B)
{
	int product=0;
	Node* p = A;
	Node* q = B;
}

while(p!=nullptr && q!=nullptr)
{
	if(p->index==q->index)
	{
		product+=p->value*q->value;
		p=p->next;
		q=q->next;
	}
	else if(p=>index<q->index)
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

void freeList(node*& head)
{
	Node* temp;
	while(head!=nullptr)
	{
		temp=head;
		head=head->next;
		delete temp;
	}
}
	
int main()
{
	int n;
	cout<<"Input n: ";
	cin>>n;
	Node* A=nullptr;
	Node* B=nullptr;
	int countA,countB;
	cout<<"enter number of non-zero elements in A: ";
	cin>>countA;
	cout<<"Index   Value"<<endl;
	
	for(int i=0;i<countA;i++)
	{
		int inx,val;
		cin>>inx>>val;
		insert(A,inx,val);
	}
	
	cout<<"\n Enter number of non-zero elements in B : ";
	cin>>countB;
	cout<<"Index    Value"<<endl;
	for(int i=0;i<countB;++i)
	{
		int inx,val;
		cin>>inx>>val;
		insert(B,idx,val);
	}
	
	int result+dotProduct(A,B);
	cout<<"\n Dot product of A and B is : "<<result<<endl;
	
	freeList(A);
	freeList(B);
	
	return 0;
		
	}	
		
}






















