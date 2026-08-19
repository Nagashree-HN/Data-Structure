#include<iostream>
using namespace std;

int main()
{
int arr[20];
int s,l;

cout<<"Enter 20 integers : "<<endl;
for(int i=0;i<20;i++)
 {
   cin>>arr[i];
 }
   s=arr[0];
   l=arr[0];

for(int i=1;i<20;i++)
  {
    if(arr[i]<s)
    {
      s=arr[i];
    }
    if(arr[i]>l)
    {
       l=arr[i];
    }
  }

cout<<"The smallest is: "<<s<<endl;
cout<<"The largest is: "<<l;

return(0);
}


/*  Sample Input and output

Input : 22  11  5  7  4  2  12 5  15  11  2  5  11  4  25  17  5  2  9  6

Output : The smallest is : 2
         The largest is : 25
         
*/         