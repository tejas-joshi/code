//======= FIND THE NEXT GREATER ELEMENT

/***
Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

Examples:
a) For any array, rightmost element always has next greater element as -1.
b) For an array which is sorted in decreasing order, all elements have next greater element as -1.
c) For the input array [4, 5, 2, 25}, the next greater elements for each element are as follows.

Element       NGE
4      -->   5
5      -->   25
2      -->   25
25     -->   -1

d) For the input array [13, 7, 6, 12}, the next greater elements for each element are as follows.

Element        NGE
13      -->    -1
7       -->     12
6       -->     12
12     -->     -1

You have 5 seconds to think...

Logic :
- Use stack. We use index of the elements in stack.
- Push 0. i.e. index of first element.
- Loop through 1 to n-1.. 
	if A[S.top()]>A[i] 
		push i.
	else 
		A[S.top()] = A[i]
		S.pop()

  Now set all the elements at the index in stack to -1... and pop until stack becomes empty

  Code for more understanding...
 
TC : O(n)
SC : O(n) (stack space)

***/	

#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n,*A;
	stack<int> S;

	cin >> n;
	A = new int[n];
	
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	// push 0
	S.push(0);

	for(int i=1;i<n;i++)
		if(A[i]<=A[S.top()])
			S.push(i);
		else
		{
			while(!S.empty() && A[S.top()]<A[i])
			{
				A[S.top()] = A[i];
				S.pop();
			}
			S.push(i);
		}

	while(!S.empty())
	{
		A[S.top()]=-1;
		S.pop();
	}

	for(int i=0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}
