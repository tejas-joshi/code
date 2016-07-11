#include<iostream>
#include<string>
#include<vector>
#define CHARS 256
using namespace std;

void setCount(string str,vector<int> *V)
{
	fill(V->begin(),V->end(),0);
	int l = str.length();
	for(int i=0;i<l;i++)
		V->at[str[i]]++;
}

int main()
{
	string str;
	vector<int> V(CHARS);

	cin >> str;
	setCount(str,V);
	
	
	return 0;	
}
