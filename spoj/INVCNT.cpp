//==== COUNT NUMBER OF INVERSIONS IN THE ARRAY

#include<iostream>
using namespace std;
typedef long long int LL;
LL merge(LL *temp,LL *A,int left,int mid,int right)
{
	LL inv_count=0;
	int i=left,j=mid,k=left;	// i for left parition, j for right partition, k for temp array indexing
	while(i<=mid-1 && j<=right)	// take care of conditions.
	{
		if(A[i]<=A[j])		
			temp[k++]=A[i++];
		else
		{
			temp[k++]=A[j++];
			inv_count = inv_count + (mid-i);			
		}
	}

	while(i<=(mid-1))
		temp[k++] = A[i++];
	while(j<=right)
		temp[k++] = A[j++];

	for(int i=left;i<=right;i++)
		A[i] = temp[i];
	return inv_count;
}

LL divide(LL *temp,LL *A,int left,int right)
{
	LL inv_count=0;
	if(left<right)
	{
		int mid = (left+right)/2;
		
		// inversions in left partition
		inv_count = inv_count + divide(temp,A,left,mid);

		// inversions in right partition
		inv_count = inv_count + divide(temp,A,mid+1,right);

		// inversions while merging left and right partition
		inv_count = inv_count + merge(temp,A,left,mid+1,right);
	}
	return inv_count;

}

LL countInv(LL *A,int n)
{
	LL temp[n];
	return divide(temp,A,0,n-1);
}

int main()
{		
	int n,t;
	cin >> t;

	while(t--)
	{
		cin >> n;
		LL A[n];
		for(int i=0;i<n;i++)
			cin >> A[i];
		cout << countInv(A,n) << endl;
	}

	return 0;
}
