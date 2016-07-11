//=== Check if each internal node of a BST has exactly one child....
//=== This is the same problem as to check whether a given binary search sequence is valid or not...

/***

Given Preorder traversal of a BST, check if each non-leaf node has only one child. Assume that the BST contains unique entries.

Examples

Input: pre[] = {20, 10, 11, 13, 12}
Output: Yes
The give array represents following BST. In the following BST, every internal
node has exactly 1 child. Therefor, the output is true.
        20
       /
      10
       \
        11
          \
           13
           /
         12


LOGIC :
* element = A[n-1] (last element)
* min = -infinite , max = infinite
*

for each element x in 0 to n-2
	x should be either
	   1) between min and element
	OR 2) between max and element

	if it satisfies 1) then min = x
	else if satisfies 2) then max = x
	else  return false ("not BS sequence"/"not all internal nodes with one child")

TC : O(n)
SC : O(1)

Another way is to compare the height of the tree (if it is given) with number of elements in the array...
Height of the tree can be computed in the loop itself in this case because either of the child should be present.. If both the children are present
* then you can simply return false...

*****/
#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
int main()
{
	int *A,n;
	cin >> n;
	A = new int[n];

	for(int i=0;i<n;i++)
		cin >> A[i];

	int min=INT_MIN,max=INT_MAX;
	int element=A[n-1];

	int i;
	for(i=0;i<n-1;i++)
	{
		if(A[i]<element && A[i]>min)	// A[i] is between element and min so update min
			min = A[i];
		else if(A[i]>element && A[i]<max)	// A[i] is between element and max so update max
			max = A[i];
		else              // A[i] is out of range so break and output false...
			break;			
	}
	
	if(i!=n-1)
		cout << 0 << endl;
	else
		cout << 1 << endl;
		
	return 0;
}
