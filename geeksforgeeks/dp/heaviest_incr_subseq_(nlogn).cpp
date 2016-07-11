

// THIS SOLUTION IS NOT WORKING FOR SOME CASES
// EX. 1 100 2 3 101 4 5 -> OUTPUT SHOULD BE 201 (1+100+101) .. IT IS GIVING 107 (1+2+3+101)...

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
	int *A,n;
	vector<int> B;
	vector<int> S;
	vector<int> SMax;

	cin >> n;
	A = (int *)malloc(n*sizeof(int));
	
	for(int i=0;i<n;i++)
		cin >> A[i];

	B.push_back(0);
	S.push_back(A[0]);
	SMax.push_back(A[0]);

	for(int i=1;i<n;i++)
	{
		if(A[i]>A[B.back()])
		{
			B.push_back(i);
			S.push_back(S.back()+A[i]);
			SMax.push_back(S.back());
			continue;
		}

		int u=0,v=B.size()-1;

		while(u<v)
		{
			int c=u+(v-u)/2;
			if(A[i]>A[B[u]])
				u = c+1;
			else
				v=c;
		}

		if(A[B[u]]>A[i])
		{
			S[u] = S[u-1]+A[i];
			B[u] = i;
		}
	}	

//	cout << S.size() << endl;
//	cout << SMax.size() << endl;
	

	cout << "S array : " << endl;
	for(int i=0;i<S.size();i++)
		cout << S[i] << " ";
	cout << endl;

	cout << "SMax array : " << endl;
	for(int i=0;i<SMax.size();i++)
		cout << SMax[i] << " ";
	cout << endl;



	int max = INT_MIN;
	for(int i=0;i<SMax.size()-1;i++)
		if(SMax[i]>max)
			max = SMax[i];

	cout << max << endl;		
	
	return 0;
}
