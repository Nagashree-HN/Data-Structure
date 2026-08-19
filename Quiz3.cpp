#include<iostream>
using namespace std;

void mergeParts(int a[],int left,int mid,int right)  //Merges the two sorted parts
{
	int n1 = mid - left + 1;  
	int n2 = right - mid;
	
	int *L = new int[n1];
	int *R = new int[n2];
	
	for (int i=0;i<n1;i++) // left half of the array
	{
		L[i] = a[left+i];
	}
	
	for (int j=0;j<n2;j++)  // right half of the array
	{
		R[j] = a[mid+1+j];
	}
	
	int i=0;      // Pointers for L[], R[] and mergered array 
	int j=0;
	int k=left;
	
	while (i < n1 && j< n2) // merging the two halves and comparing the array elements
	{
		cout<<" Comparing " << L[i] << " and " << R[j] <<endl;
		
		
		if(L[i] <= R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
		     a[k]=R[j];
		     j++;
		}
		k++;
	}
	
	while(i<n1)   // moving the leftover elements into the array
	{
	
	   a[k]=L[i];
	   i++;
	   k++;
    }
	
	while(j<n2)
	{
	
	   a[k]=R[j];
	   j++;
	   k++;
    }
	
	delete[] L;
	delete[] R;
}


void mergeSort(int a[], int left, int right) // Recursively splits the array and merges it back
{
	cout<< " Call: mergeSort(" << left << " , " << right <<") --> part: ";
	for(int i=left; i<= right; i++)
	cout<<a[i]<<" ";
	cout<<endl;
	
	
	if(left >= right)
	return;
	
	int mid =(left+right) / 2 ;
	
	mergeSort(a,left,mid);   //left half
	mergeSort(a,mid+1,right);   //right half
	
	mergeParts(a,left,mid,right);
	
	cout<<"After merging (" << left << "," <<right << "): "; //after merging
	for(int i=left; i<= right; i++)
	cout<<a[i]<<" ";
	cout<<endl;
}


int main()
{
	
	int arr[] = {8, 6, 5, 7, 4, 3, 1, 2};
	int n = 8;
	
	
	cout<<"Original array: \n";
	for(int i= 0; i< n; i++)
	cout << arr[i] << " ";
	cout<<"\n\n";
	
	
	mergeSort(arr,0,n-1);
	
	cout<<"\n Final sorted array: \n";
	for(int i= 0; i< n; i++)
	cout << arr[i] << " ";
	cout<<endl;
	
	return 0;   
	   
}