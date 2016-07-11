#include<iostream>
using namespace std;

bool isMatch(char *str,char *pat)
{
	// Here checking for both null values
	if(*str==NULL)
		return (*pat==NULL);
	
	// non- * chars
	if(*(pat+1)!='*')
		return ((*str==*pat) || (*pat=='.' && *str!=NULL)) 	// exact match OR . match(any char)
				&& isMatch(str+1,pat+1);						// call for the next 
	
	// * char
	while( (*str==*pat) || (*pat=='.' && *str!=NULL) )		// exact char in *  OR any char except (in case of .*)
	{
		if(isMatch(str,pat+2)						// next call .. this is one branch which is going out of .* match
			return true;
		str++;										// We are comparing other branch in the loop itself
													// it is if the above branch fails continue with * and next char in str 
	}
	return isMatch(str,p+2);
}

int main()
{
	char str[100],pat[100];
	cin >> str;
	cin >> pat;
	cout << isMatch(str,pat) << endl;
	return 0;
}
