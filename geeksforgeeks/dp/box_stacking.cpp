//======= BOX STACKING PROBLEM

/*
You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers). 
You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box 
if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. 
Of course, you can rotate a box so that any side functions as its base. It is also allowable to use multiple instances of the same type of box.

Following are the key points to note in the problem statement:
1) A box can be placed on top of another box only if both width and depth of the upper placed box are smaller than width and depth of the lower box respectively.
2) We can rotate boxes. For example, if there is a box with dimensions {1x2x3} where 1 is height, 2×3 is base, then there can be three possibilities, {1x2x3}, {2x1x3} and {3x1x2}.
3) We can use multiple instances of boxes. What it means is, we can have two different rotations of a box as part of our maximum height stack.

LOGIC :
1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of original array. 
For simplicity, we consider depth as always smaller than or equal to width.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
MSH(i) = Maximum possible Stack Height with box i at top of stack
MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
If there is no such j then MSH(i) = height(i)

4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n

More in comments...

TC : O(n^2)   // LIS logic can be implemented in nlogn time also
SC : O(n)     
*/


#include<iostream>
#include<stdlib.h>
using namespace std;

struct box_s
{
	int h,w,l;
};
typedef struct box_s box;

int compare(const void *a,const void *b)
{
	return ((*(box *)b).l)*((*(box *)b).w) - ((*(box *)a).l)*((*(box *)a).w);
}

int main()
{
	box *B;
	int n;
	cin >> n;
	B = new box[n];

	for(int i=0;i<n;i++)
		cin >> B[i].h >> B[i].w >> B[i].l;

	/* Create an array of all rotations of given boxes
	   For example, for a box {1, 2, 3}, we consider three
	   instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
	
	box *allB;
	n=n*3;
	allB = new box[n];

	for(int i=0;i<n;)
	{
		int ind = i/3;
		
		// copy the same box
		allB[i] = B[ind];
		i++;

		// first rotation
		allB[i].h = B[ind].w;
		allB[i].l = max(B[ind].h,B[ind].l);
		allB[i].w = min(B[ind].h,B[ind].l);
		i++;

		// second rotation
		allB[i].h = B[ind].l;
		allB[i].l = max(B[ind].h,B[ind].w);
		allB[i].w = min(B[ind].h,B[ind].w);
		i++;
	}
	
	qsort(allB,n,sizeof(box),compare);

	/* Initialize msh values for all indexes
         msh[i] –> Maximum possible Stack Height with box i on top */
	int *msh;
	msh = new int[n];
	for(int i=0;i<n;i++)
		msh[i] = allB[i].h;


	// http://people.csail.mit.edu/bdean/6.046/dp/ for more clarity
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
				// to be ith box on the top of jth box.. l and w of i must be smaller than of j.. (2 conditions) and last one for max 
			if( (allB[i].l < allB[j].l) && (allB[i].w < allB[j].w) && (msh[i] < msh[j] + allB[i].h) )
				msh[i] = msh[j] + allB[i].h;
	
	// max of all msh values 
	int maxH=-1;
	for(int i=0;i<n;i++)
		if(msh[i]>maxH)
			maxH = msh[i];
	cout << maxH << endl;
	
	return 0;
}
