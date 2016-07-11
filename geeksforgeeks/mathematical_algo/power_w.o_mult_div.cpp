// CALCULATE THE POWER WITHOUT USING * AND /...

/*
We can calculate power by using repeated addition.

For example to calculate 5^6.
1) First 5 times add 5, we get 25. (5^2)
2) Then 5 times add 25, we get 125. (5^3)
3) Then 5 time add 125, we get 625 (5^4)
4) Then 5 times add 625, we get 3125 (5^5)
5) Then 5 times add 3125, we get 15625 (5^6)

Just refer the code once... you will easily understand...
*/
	

#include<iostream>
using namespace std;

int power(int b,int p)
{
	int temp=0,addValue=b;
	for(int i=0;i<p-1;i++)
	{
		temp=0;		// remember this statement...
		for(int j=0;j<b;j++)
			temp = temp + addValue;	// temp will count the next power of b every time..
		addValue = temp;	// addValue is the value that is going to be used for the calculation of next power 
	}
	return addValue;
}

int main()
{
	int b,p;
	cin >> b >> p;
	cout << power(b,p) << endl;
	return 0;
}
