#include<iostream>
#include<string>
#include<set>
#include<map>
#include<sstream>
#include<functional>
using namespace std;
int main()
{
	string in,name;
	map<int,multiset<string>,greater<int> > M;
	int age,pos;
	
	while(1)
	{
		getline(cin,in);
		if(!cin.eof())
		{
			multiset<string> S;
			pos = in.find(" ");
			name = in.substr(0,pos);			
			stringstream(in.substr(pos+1)) >> age;
			
			if(M.find(age)!=M.end())
				S = M[age];
			S.insert(name);
			M[age] = S;
		}
		else
			break;
	}

	multiset<string>::iterator sItr;
	multiset<string> S;
	
	map<int,multiset<string> > :: iterator itr;
	for(itr=M.begin();itr!=M.end();itr++)
	{		
		S = itr->second;
		for(sItr = S.begin();sItr!=S.end();sItr++)
			cout << *sItr << endl;
	}
		
	return 0;	
}
