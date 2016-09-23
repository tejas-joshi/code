////=========== Egyptian Fraction
/*
Every positive fraction can be represented as sum of unique unit fractions. 
A fraction is unit fraction if numerator is 1 and denominator is a positive integer, for example 1/3 is a unit fraction. 
Such a representation is called Egyptial Fraction as it was used by ancient Egyptians.

Egyptian Fraction Representation of 2/3 is 1/2 + 1/6
Egyptian Fraction Representation of 6/14 is 1/3 + 1/11 + 1/231
Egyptian Fraction Representation of 12/13 is 1/2 + 1/3 + 1/12 + 1/156


nr - numerator
dr - denomenator

Logic :
for 6/14
* Take ceil(14/6)=3. so our first fraction is 1/3.. print it.
* Compute 6/14-1/3=4/42
* Take ceil(42/4)=11. so our second fraction is 1/11.. print it.
* Compute 4/42-1/11=2/462
........

Now you got the algo...

* Check the code. There are some corner case to handle.
* Use long long int in case you want the bigger fraction

PS : This will go out of bounds for numerator=5; denominator=121

*/


#include<iostream>
using namespace std;

void printEgyptianFraction(int nr,int dr)
{
	if(nr==0 || dr==0)
		return;
	
	if(nr>=dr)
	{
		if(nr%dr==0) // the whole part like 12/6 .. print 2 only
		{
			cout << (nr/dr) << endl;
			return;
		}
		else  // like 15/4.. print 3 first
		{
			cout << (nr/dr) << "+";
			nr=nr%dr;
		}
	}
	
	while(1)
	{
		if(dr%nr==0) // when we get like 2/12.. we can print 1/6
		{
			cout << "1/" << (dr/nr);
			break;
		}
		
		if(nr==1) // when we get like 1/3 directly
		{
			cout << "1/" << dr;
			break;
		}

		// logic implementation
		int fraction = (dr/nr)+1;
		cout << "1/" << fraction << " + "; 
		nr=(nr*fraction)-dr;
		dr=dr*fraction;
	}
}

int main()
{
	int nr,dr;
	cin >> nr >> dr;
	printEgyptianFraction(nr,dr);
    return 0;
}