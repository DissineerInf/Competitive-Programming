#include <iostream>

using namespace std;

void merge_inversion(int low, int mid , int high , int arr[], int aux[],int & inversions)
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
			inversions+=(mid-i+1);	

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

void mergesort_inversion(int low, int high, int arr[],int aux[],int & inversions)
{
	if (low < high)
	{
		int mid = (low + high)/2;
		mergesort_inversion(low, mid,arr,aux,inversions);
		mergesort_inversion(mid+1,high,arr,aux,inversions);
		merge_inversion(low,mid,high,arr,aux,inversions);

	}
}

int main() {
	int n=10;
	int arr[n] {30,60,70,45,33,87,99,7,2,100};
	int aux[n];
	int inversions=0;
	mergesort_inversion(0,n-1,arr,aux,inversions);

	cout<<inversions<<endl;
	
	return 0;
}