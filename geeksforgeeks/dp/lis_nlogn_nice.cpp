#include<iostream>
#include<vector>
using namespace std;

int findCeil(int *A,vector<int> lenVec,int low,int high,int elem)
{
	int mid;
	while(high-low > 1)
	{
		mid = low + (high-low)/2;
		if(A[lenVec[mid]] >= elem)
			high = mid;
		else
			low = mid;
	}
	return high;	
}

int main()
{
	int n,*A,*prevInd;
	vector<int> lenVec;

	cin >> n;
	A = new int[n];
	prevInd = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	// prevInd[i] stores the index of the element for which the next element in LIS would be A[i]
	// i.e. index of second last element of LIS for which A[i] would be last element
	// this is to backtrack the LIS
	
	lenVec.push_back(0);	// push 0 because of LIS with first element
	prevInd[0] = -1;		// previous index for LIS with first element would be -1
	
	for(int i=1;i<n;i++)
	{
		if(A[i]<A[lenVec[0]])	// smaller than first element
			lenVec[0] = i;
		else if(A[i]>A[lenVec.back()])		// bigger than last element 
		{
			prevInd[i] = lenVec.back();
			lenVec.push_back(i);
		}
		else         // somewhere in the middle of the series...
					// this element needs to be replaced by its ceiling element to allow other bigger LIS
		{
			int pos = findCeil(A,lenVec,-1,lenVec.size()-1,A[i]);	// finding ceiling .. pos is the index in lenVec..
			prevInd[i] = lenVec[pos-1];						// pos-1 would be the previous index in LIS for current element
			lenVec[pos] = i;							// replacing index at pos with i.. (replacing with ceiling)
		}	
	}	
	
	// printing LIS... this would be in reverse order... 
	for(int i=lenVec.back();i>=0;i=prevInd[i])
		cout << A[i] << " ";
	cout << endl;
	
	return 0;	
}
