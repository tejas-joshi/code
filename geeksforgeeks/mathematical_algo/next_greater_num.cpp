//=== PRINT THE NEXT HIGHER NUMBER FROM THE SET OF THE DIGITS GIVEN IN THE NUMBER..

/*

e.g. 524321 => 531224

Logic :
123456784987654321
start with a number

123456784987654321
            ^the first place where the left-digit is less-than the right-digit is here.  Digit "x" is 4

123456784 987654321
              ^find the smallest digit larger than 4 to the right (ceiling)

123456785 4 98764321
        ^place it to the left of 4

123456785 4 12346789
123456785123446789
         ^sort the digits to the right of 5.  Since all of them except the '4' were already in descending order, all we need to do is reverse their order, and find the correct place for the '4'
Note:
Any number whose digits are already fully sorted in descending order is the max (so 98765 also has no solution, for example).
This is easy to detect programatically because step 1 of the algorithm will fail
(there is no pair of consecutive digits such that "the left-digit is smaller than the right-digit").

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void *a,const void *b)
{
	return (* (int *)a) > (* (int *)b);
}

void printNextHigher(int *num,int n)
{
	int i;
	for(i=n-2;i>=0;i--)			// finding the position where ith digit is less than (i+1)th digit.
		if(num[i]<num[i+1])
			break;

	int j,b;
	int j=b=i+1;	//  j is the position from where the decreasing order starts and upto last digit..
	
	if(i>=0)	// this will only be true if all the digits are not already sorted in decreasing order..
	{
		while(j<n && (num[j]>num[i]))	// finding the greater digit than ith digit
			j++;
		j--;

		// exchanging ith and jth digit
		int temp = num[i];
		num[i] = num[j];
		num[j] = temp;

		// sorting all the digits from bth index
		qsort(num+b,n-b,sizeof(int),compare);

		// printing the number
		for(int i=0;i<n;i++)
			cout << num[i];
		cout << endl;
	}
}

int main()
{
	int num[10]={1,2,3,6,7,8};

	printNextHigher(num,6);

	return 0;
}
