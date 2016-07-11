#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	int mod[10][10];
	vector< vector<int> > V;

	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			mod[i][j]=-1;

	for(int i=0;i<10;i++)
	{
		int cnt=i;
		vector<int> temp;
		while(mod[i][cnt]==-1)
		{
			temp.push_back(cnt);
			mod[i][cnt]=1;
			cnt = (cnt*i)%10;
		}
		V.push_back(temp);
	}

	int T;
	cin >> T;

	while(T--)
	{
		char b;
		int base;
		b=getchar();
		while(b!=' ')
		{
			base = b-'0';
			b=getchar();
		}

		long long int pw;
		cin >> pw;
		
		if(pw==0)
			cout << 1 << endl;
		else
		{
			vector<int> vec = V[base];
			cout << vec[(pw-1)%(vec.size())] << endl;
		}
	}	


	return 0;
}	
