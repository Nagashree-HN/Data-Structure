#include<iostream>
using namespace std;

struct point
{
	int x;
	int y;
};

int main()
{
    point array[10];
	point uniqueValues[10];
	int uniqueCount=0;
	
	cout<<"Enter 10 points for x and y values : \n";
	cout<<"x  y\n";

	
	for(int i=0;i<10;i++)
	{
		cin>>array[i].x>>array[i].y;
	}
	
	for(int i=0;i<10;i++)
	{
		bool isDuplicate = false;
	
	
	for(int j=0;j<uniqueCount;j++)
	{
		if(array[i].x==uniqueValues[j].x  &&  array[i].y==uniqueValues[j].y)
		{
		
			isDuplicate = true;
			break;
		}
			
	}
	
	    if(!isDuplicate)
	    {
		uniqueValues[uniqueCount]=array[i];
		uniqueCount++;
		
	    }
    }  
    
    
    cout<<"\nDistinct Points\n";
    cout<<"x y\n";
    
    for(int i=0;i<uniqueCount;i++)
    {
    	cout<<uniqueValues[i].x<< " " << uniqueValues[i].y <<"\n";
	}
   

return 0;
}





/*     Sample output

Input : 

Enter 10 points for x and y values :
x  y
1 2
3 4
4 5
5 6
3 4
5 6
7 8
1 2
7 8
4 5

Output :

Distinct Points
x y
1 2
3 4
4 5
5 6
7 8

*/