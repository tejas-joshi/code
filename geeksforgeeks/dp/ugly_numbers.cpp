/*****************

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the nth ugly number.

******************/

#include<iostream>
#include<stdlib.h>
using namespace std;

int min(int a,int b,int c)
{
	return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

int main()
{
	int n,*U;
	int i2=0,i3=0,i5=0;
	int mul2,mul3,mul5;
	cin >> n;

	U = (int *)malloc(n*sizeof(int));
	U[0]=1;

	// i2,i3 and i5 are the indexes in U array.. which will get incremented in the case the numbers selected from their set...
	
	mul2 = U[i2]*2;
	mul3 = U[i3]*3;
	mul5 = U[i5]*5;
	
	for(int i=1;i<n;i++)
	{
		U[i] = min(mul2,mul3,mul5);

		// Here all the conditions should be in if.. not else if...
		// It will create problem of duplicates in case atleast two from mul2/mul3/mul5 are same. 
		// That case only one will get executed ane in next iteration, duplicate will come in U array..
		
		if(U[i]==mul2)
			mul2 = U[++i2]*2;		// update mul2 as the next multiple of 2

		if(U[i]==mul3)
			mul3 = U[++i3]*3;		// update mul3 as the next multiple of 3

		if(U[i]==mul5)
			mul5 = U[++i5]*5;		// update mul5 as the next multiple of 5
	}
	cout << U[n-1] << endl;
	return 0;
}	
