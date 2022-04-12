#include <iostream>

using namespace std;

void merge(int low, int mid , int high , int arr[], int aux[])
{
	int i =low, k=low, j=mid+1;
	
	while(i<=mid && j<=high)
	{
		if (arr[i]<=arr[j]) 
		{
			aux[k]=arr[i];
			i++;
			k++;
		}
		else
		{
			aux[k]=arr[j];
			j++;
			k++;
		}
	}

	if (i>mid)
		{
			while(j<= high)
			{
				aux[k]=arr[j];
				k++;
				j++;
			}
		}
	else
	{
		while(i<=mid)
		{
			aux[k]=arr[i];
			i++;
			k++;
		}
	}

	for(int x=low; x<=high; x++)
	arr[x]=aux[x];
	
}

void mergesort(int low, int high, int arr[],int aux[])
{
	if (low < high)
	{
		int mid = (low + high)/2;
		mergesort(low, mid,arr,aux);
		mergesort(mid+1,high,arr,aux);
		merge(low,mid,high,arr,aux);

	}
}

int main() {
	int n=10;
	int arr[n] {30,60,70,45,33,87,99,7,2,100};
	int aux[n];
	mergesort(0,n-1,arr,aux);

	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	
	return 0;
}