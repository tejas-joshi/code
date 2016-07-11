#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int LL;

vector<LL> sum1,sum2;

void fillSum(vector<LL> &V,LL *S,int size)
{
	LL subsetSize = 1 << size;
	LL sum;
	for(LL i=0;i<subsetSize;i++)
	{
		sum=0;
		for(int j=0;j<size;j++)
			if((i>>j)&1)
				sum = sum + S[j];
		V.push_back(sum);
	}
}	

int main()
{
	LL N,A,B,*S1,*S2;
	cin >> N >> A >> B;

	int size1 = N/2;
	int size2 = N-N/2;

	S1 = new LL[size1];
	S2 = new LL[size2];
	
	for(int i=0;i<size1;i++)
		cin >> S1[i];		
	for(int i=0;i<size2;i++)
		cin >> S2[i];		
	
	fillSum(sum1,S1,size1);
	fillSum(sum2,S2,size2);	

	sort(sum1.begin(),sum1.end());
	sort(sum2.begin(),sum2.end());
		
	LL subset1Size = sum1.size();
	LL left,right,count=0;

	for(LL i=0;i<subset1Size;i++)
	{
		left = lower_bound(sum2.begin(),sum2.end(),A-sum1[i]) - sum2.begin();	
		right = upper_bound(sum2.begin(),sum2.end(),B-sum1[i]) - sum2.begin();	
		right--;
		
		if(left<=right)
			count = count + (right-left+1);		
	}
	
	cout << count << endl;	
	
	return 0;	
}	


/*
 * 
 * if I have an array S with n elements

1) I divide this array for the half obtaining 2 arrays P and Q
with N/2 elements
P = P1, P2,...,PN/2
Q = Q1, Q2,...,QN/2
this at one time

O( N/2 + N/2)=O(N)

2) then we calculate all the subsets that can be formed in
P and Q to insert them in the Arrays X,Y

the size of X and Y will be 2 ^ (N/2)
this takes a time of

O( (N/2)*2^(N/2) + (N/2)*2^(N/2) )= O( N*2^(N/2) )

3) we sort both arrays at time

O( log(X.size()) + log(Y.size()) )
= O( log(2^(N/2)) + log(2^(N/2)) )
= O(N)

4) finally we obtain the quantity of subsets whose sum this betwen A
and B.
this is solved with two binary search

*/

