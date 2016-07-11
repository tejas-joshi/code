//===== FIND THE CELEBRITY IN THE PARTY..

/*****
Given a 2D array.. find the node who doesnt know anyone.. but all knows him/her. That's the celebrity.

Logic :
* THIS IS YOUR OPTIMIZATION... NICE ONE...
Take 3 variables .. curr1,curr2 and next
We will check the relation between curr1 and curr2.. next will have the index of next person to be considered.
If curr1 knows curr2 then curr1 can't be celebrity. So take next.. i.e. curr1 = next.
else curr2 knows curr1 ..i.e. curr2 can't be celebrity. Take next.. i.e. curr2=next.
continue this till next>=0 ...

After this we will have last two persons to be checked.
Just make one check between curr1 and curr2.. whoever knows other .. other will be celebrity...

TC : O(n)
SC : O(1)

********/

#include<iostream>
using namespace std;
int main()
{
	int n,**A;
	cin >> n;
	A = new int*[n];
	for(int i=0;i<n;i++)
		A[i] = new int[n];

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> A[i][j];
	
	int curr1=n-1,curr2=n-2,next=n-3;

	while(next>=0)
	{
		if(A[curr1][curr2]==1)	// curr1 is not celebrity
			curr1 = next;	
		else			// curr2 is not celebrity
			curr2 = next;    
		next--;		
	}
	
	// last check for last two persons
	if(A[curr1][curr2])
		cout << curr2 << endl;
	else
		cout << curr1 << endl;

	return 0;
}
