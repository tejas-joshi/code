#include<iostream>
#include<string>
using namespace std;

int countAns(int *A,int size,int index,int currSum)
{
	int tempAns=0;
	if(index==size)
		return 1;
	int sum=0;

	for(int i=index;i<size;i++)
	{
		sum = sum + A[i];
		if(sum>=currSum)
			tempAns = tempAns + countAns(A,size,i+1,sum);	
	}
	return tempAns;	
}

int main()
{
	string in;
	int A[30],count=1;
	
	while(1)
	{
		cin >> in;
		if(in.compare("bye")==0)
			break;
		
		int len = in.length();

		for(int i=0;i<len;i++)
			A[i] = in[i]-'0';	
		
		cout << count++ << ". " << countAns(A,len,0,0) << endl;
	}
	
	return 0;
}
