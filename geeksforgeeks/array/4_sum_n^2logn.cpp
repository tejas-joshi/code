//========== FIND FOUR ELEMENTS WHICH HAS SUM AS GIVEN VALUE 

/******
Given an unsorted array, print four elements which has sum as X.

Logic :
Take array which contains the sum of all the pairs of array.
Sort that array.
Find the pair from that array like finding 2 sum problem. Just make sure that any of the indexes of both the elements are not same.

TC : O(n^2logn)
SC : O(n^2)

******/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct sum
{
	int x,y,sum;
};

typedef struct sum S;

int compare (const void *a,const void *b)
{
	return (*(S *)a).sum > (*(S *)b).sum;
}

bool valid(S a,S b)
{
	return !((a.x == b.x) || (a.x == b.y) || (a.y==b.x) || (a.y==b.y));
}
int main()
{
	int n,*A;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	int X;
	cin >> X;

	S *pair_sum;
	int elem = (n*(n-1))/2;
	pair_sum = new S[elem];

	// STORING THE PAIR SUM INTO ARRAY	
	int k=0;	
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			pair_sum[k].sum = A[i]+A[j];
			pair_sum[k].x = i;
			pair_sum[k].y = j;
			k++;
		}

	// SORTING OF ARRAY
	qsort(pair_sum,elem,sizeof(S),compare);

	int low=0,high=elem-1;
	while(low<high)
	{
		if(pair_sum[low].sum+pair_sum[high].sum==X && valid(pair_sum[low],pair_sum[high]))
		{
			// Here you can check for all the pairs that has sum X because it is possible that different pairs are having the same sum...
				
			cout << A[pair_sum[low].x] << " " << 
				A[pair_sum[low].y] << " " << 
				A[pair_sum[high].x] << " " << 
				A[pair_sum[high].y] << endl;
			break;
		}
		else if(pair_sum[low].sum + pair_sum[high].sum < X)
			low++;
		else
			high--;
	}

	return 0;
}
