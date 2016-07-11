//======== FIND THE PAIR WITH THE GIVEN DIFFERENCE

/*******

Given an array, find the array with given difference.
array : 5 20 3 2  50 80
diff : 78
pair : 80 2

Logic : 
Sort the array.
Initialize two index i=0 and j=1

while(i<n and j<n)
	diff A[j]-A[i] 
	If it is X then we are done
	else if diff < X ( here diff is less so we have to increase it so increment j. )
	else (here diff is more so we have to decrease it so increment i.. If after incrementing, if i is the same as j.. then increment j also..)

TC : O(nlogn)
SC : O(1)

*******/


#include<iostream>
#include<stdlib.h>
using namespace std;

int compare (const void  *a,const void *b)
{
	return (*(int *)a) > (*(int *)b);
}

int main()
{	
	int n,*A;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	qsort(A,n,sizeof(int),compare);

	int X;
	cin >> X;

	bool found=false;
	int i=0,j=1;
	while(i<n && j<n)
	{
		int diff = A[j]-A[i];
		if(abs(diff)==X)
		{
			found = true;
			cout << A[j] << " " << A[i] << endl;
			break;
		}
		else if(abs(diff)>X)	// now we need to decrement the difference so increment i..
		{
			i++;
			if(i==j)	// after i++ .. if it is same as j then also increment j.. because i<j must be maintained.
				j++;
		}
		else			// here we need to increment the difference so increment j
			j++;
	}
	
	if(!found)
		cout << "not found" << endl;

	return 0;
}
