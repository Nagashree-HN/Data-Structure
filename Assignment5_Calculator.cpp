#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class STACK
{
	private:
		char *s;
		int N;
		
	public:
	STACK(int maxN)	
	{
		s=new char[maxN];
		N=0;
	}
	int empty() const
	{
		return N == 0;
	}
	void push(char item)
	{
		s[N++] = item;
	}
	char pop()
	{
		return s[--N];
	}
};

int main()
{
	char a[200];
	cout<<"Expresion?: ";
	cin>>a;
	
	int N = strlen(a);
	STACK ops(N);
	
	cout<<"\n Answer: \n"; //infix to postfix
	char postfix[200];
	int k=0;
	
	for(int i=0;i<N;i++)
	{
		if(a[i] == ')')
		{
			postfix[k++] = ops.pop();
			postfix[k++]=' ';
		}
		
		else if(a[i]== '(')
		{
			continue;
		}
		
		else if((a[i]=='+') || (a[i]=='*') || (a[i]=='^'))
		{
			ops.push(a[i]);
		}
		
		else if((a[i]>='0') && (a[i]<='9'))
		{
			postfix[k++]=a[i];
			postfix[k++]=' ';
		}	
		
	}
	postfix[k]='\0';
	cout<<postfix<<endl;
	
	
	int M = strlen(postfix); // to evaluate postfix Mod 10
	STACK save(M);
	
	for(int i=0;i<M;i++)
	{
		if(postfix[i] ==' ' || postfix[i] =='\n')
		continue;
		
		if(postfix[i] >='0' && postfix[i] <='9')
		{
			save.push(postfix[i]);
		}
		
		else if((postfix[i]=='+') || (postfix[i]=='*') || (postfix[i]=='^'))
		{
			int b=save.pop() - '0';
			int a=save.pop() - '0';
			int res=0;
			
			if(postfix[i]=='+')
			res=(a+b) % 10;
			
			else if(postfix[i]=='*')
			res=(a*b) % 10;
			
			else if(postfix[i]=='^')
		    res =(int)pow(a,b)%10;
			
			save.push((res%10)+'0');
			
		}
	}
	
	int result = save.pop() - '0';
	cout<<result<<" in modulo 10 "<<endl;
	
	return 0;

		
		
}
	
	
/*-----------------------Sample Run---------------

Expresion?: (((2+(5^2))+7)

 Answer:
2 5 2 ^ + 7 +
4 in modulo 10


Expresion?: ((((9*8)+(3*6))^2)+((1^3)*(2+1)))

 Answer:
9 8 * 3 6 * + 2 ^ 1 3 ^ 2 1 + * +
3 in modulo 10


Expresion?: ((((2+5)*7)+((9*3)*2))^2)

 Answer:
2 5 + 7 * 9 3 * 2 * + 2 ^
9 in modulo 10	


Expresion?: ((((2*3)*(4*6))*7)+(((7+8)+9)*((2+4)*((7+8)+9))))

 Answer:
2 3 * 4 6 * * 7 * 7 8 + 9 + 2 4 + 7 8 + 9 + * * +
4 in modulo 10


Expresion?: (9+(8*(7+(6*(5+(4*(3+2)))))))

 Answer:
9 8 7 6 5 4 3 2 + * + * + * +
5 in modulo 10

*/