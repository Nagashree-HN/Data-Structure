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
	
/*	for(int i=0;i<N;i++)
	{
		if(a[i] == ')')
		{
			postfix[k++] = ops.pop();
			postfix[k++]=' ';
		}
		
		if((a[i]=='+') || (a[i]=='*') || (a[i]=='^'))
		ops.push(a[i]);
		
		if((a[i]>='0') && (a[i]<='9'))
		{
			postfix[k++]=a[i];
			postfix[k++]=' ';
		}	
		
	}
	postfix[k]='\0';
	cout<<postfix<<endl;
	*/
	
	for (int i = 0; i < N; i++)
{
    if ((a[i] >= '0') && (a[i] <= '9'))
    {
        postfix[k++] = a[i];
        postfix[k++] = ' ';
    }

    else if ((a[i] == '+') || (a[i] == '*') || (a[i] == '^'))
    {
        ops.push(a[i]);
    }

    else if (a[i] == ')')
    {
        // Pop until we find '('
        while (!ops.empty() && ops.pop() != '(')
        {
            postfix[k++] = ops.pop();
            postfix[k++] = ' ';
        }

        // Pop the '(' as well
        if (!ops.empty() && ops.pop() == '(')
            ops.pop();
    }

    else if (a[i] == '(')
    {
        ops.push(a[i]);
    }
}

// Pop any remaining operators
while (!ops.empty())
{
    postfix[k++] = ops.pop();
    postfix[k++] = ' ';
}

postfix[k] = '\0';
cout << postfix << endl;
	
	int M = strlen(postfix); // evaluate postfix Mod 10
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
			/*{
				int temp = 1;
				for (int j=0;j<b;j++)
				temp =(temp * a) % 10;
				res=temp;
			}*/
			
			res =(int)pow(a,b)%10;
			
			save.push((res%10)+'0');
			
		}
	}
	
	int result = save.pop() - '0';
	cout<<result<<" in modulo 10 "<<endl;
	
	return 0;

		
		
}
	
	
	
	
	
	
	
	

