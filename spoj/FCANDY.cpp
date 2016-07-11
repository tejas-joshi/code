#include<iostream>
using namespace std;
int main()
{
	int N,k,c,withC=0,withoutC=0,minDiff;	
	cin >> N;
	
	for(int i=0;i<N;i++)
	{
		cin >> k >> c;
		
		for(int j=0;j<k;j++)
		{
			if(withC>withoutC)
				withoutC = withoutC + c;
			else
				withC = withC + c;
			min = abs(withoutC-withC);
		}
	}
	cout << min << endl;
		
	return 0;
}
