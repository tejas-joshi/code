//====== FIND NO. OF TRIANGLES IN AN ARRAY

/****
Given an unsorted array, find the number of triangles in it.
For a triangle to be possible from 3 values, the sum of any two values (or sides) must be greater than the third value (or third side).
For example, if the input array is {4, 6, 3, 7}, the output should be 3. 
There are three triangles possible {3, 4, 6}, {4, 6, 7} and {3, 6, 7}. Note that {3, 4, 7} is not a possible triangle.
As another example, consider the array {10, 21, 22, 100, 101, 200, 300}. 
There can be 6 possible triangles: {10, 21, 22}, {21, 100, 101}, {22, 100, 101}, {10, 100, 101}, {100, 101, 200} and {101, 200, 300}

LOGIC :
1. Sort the array in increasing order.

2. Initialize two pointers ‘i’ and ‘j’ to first and second elements respectively, and initialize count of triangles as 0.

3. Fix ‘i’ and ‘j’ and find the rightmost index ‘k’ (or largest ‘arr[k]‘) such that ‘arr[i] + arr[j] > arr[k]‘. 
The number of triangles that can be formed with ‘arr[i]‘ and ‘arr[j]‘ as two sides is ‘k – j’. Add ‘k – j’ to count of triangles.

Let us consider ‘arr[i]‘ as ‘a’, ‘arr[j]‘ as b and all elements between ‘arr[j+1]‘ and ‘arr[k]‘ as ‘c’. 
The above mentioned conditions (ii) and (iii) are satisfied because ‘arr[i] < arr[j] < arr[k]'. And we check for condition (i) when we pick 'k'

4. Increment ‘j’ to fix the second element again.

Note that in step 2, we can use the previous value of ‘k’. The reason is simple, if we know that the value of ‘arr[i] + arr[j-1]‘ is greater than ‘arr[k]‘, 
then we can say ‘arr[i] + arr[j]‘ will also be greater than ‘arr[k]‘, because the array is sorted in increasing order.

5. If ‘j’ has reached end, then increment ‘i’. Initialize ‘j’ as ‘i + 1′, ‘k’ as ‘i+2′ and repeat the steps 3 and 4.

TC : O(n^2)
SC : O(1)

The time complexity looks more because of 3 nested loops. 
If we take a closer look at the algorithm, we observe that k is initialized only once in the outermost loop. 
The innermost loop executes at most O(n) time for every iteration of outer most loop, because k starts from i+2 and goes upto n for all values of j.

 ******/

#include<iostream>
#include<stdlib.h>
using namespace std;

int compare(const void *a,const void *b)
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

	int k,ans=0;	
	for(int i=0;i<n-2;i++)
	{	
		k=i+2;
		for(int j=i+1;j<n-1;j++)
		{
			while(k<n && A[i]+A[j]>A[k])
				k++;
			ans = ans + (k-j-1);	// -1 because k has already been incremented in the last iteration of the above while loop.
		}
	}
		
	cout << ans << endl;

	return 0;
}
