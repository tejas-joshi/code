////=========== Connect n ropes with minimum cost
/*
There are given n ropes of different lengths, we need to connect these ropes into one rope. 
The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

Connect smallest two ropes first and recur for remaining ropes. 
We put smallest ropes down the tree so that they can be repeated multiple times rather than the longer ropes.

Following is complete algorithm for finding the minimum cost for connecting n ropes.
Let there be n ropes of lengths stored in an array len[0..n-1]
1) Create a min heap and insert all lengths into the min heap.
2) Do following while number of elements in min heap is not one.
……a) Extract the minimum and second minimum from min heap
……b) Add the above two extracted values and insert the added value to the min-heap.
3) Return the value of only left item in min heap.

// REMEMBER THE IMPLEMENTATION OF HEAP USING PRIORITY QUEUE

TC : O(nlogn)
SC : O(n)

*/


#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

int minCost(int arr[],int size)
{
	priority_queue<int,vector<int>,greater<int> > pQ(arr,arr+size);
	int res=0;
	for(int i=0;i<size-1;i++)
	{
		int first = pQ.top();		
		pQ.pop();
		int second = pQ.top();
		pQ.pop();	
		res = res+first+second;
		pQ.push(first+second);
	}
	return res;
}

int main()
{
	int len[] = {4, 3, 2, 6};
    int size = sizeof(len)/sizeof(len[0]);
	cout << minCost(len,size) << endl;
    
    return 0;
}