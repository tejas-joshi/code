////=========== FRACTIONAL KNAPSACK
/*
Input:
  Items as (value, weight) pairs
  arr[] = {{60, 10}, {100, 20}, {120, 30}}
  Knapsack Capacity, W = 50;

Output :
   Maximum possible value = 240
   By taking full items of 10 kg, 20 kg and 
   2/3rd of last item of 30 kg

* Calculate the ratio value/weight for each item 
* Sort the item on basis of this ratio. 
* Take the item with highest ratio and add them until we can’t add the next item as whole
* At the end add the next item as much as we can. Which will always be optimal solution of this problem.   

TC : O(nlogn)
   
*/


#include<iostream>
#include<algorithm>
using namespace std;

typedef struct item_s
{
	int value,weight;
	item_s() {}
	item_s(int Value, int Weight)
	{
		value = Value;
		weight = Weight;
	}
} Item;

// Sort the array by (profit/weight) ratio in decreasing order
bool compare (const Item &a, const Item &b)
{
	double ratioA = (double)(a.value/a.weight);
	double ratioB = (double)(b.value/b.weight);	
	return ratioA > ratioB;
}

double getMaxProfit(Item *items, int n, int W)
{
	sort(items,items+n,compare);

	int currW=0;
	double profit=0;
	
	for(int i=0;i<n;i++)
	{
		if(currW+items[i].weight <= W)	// Taking the whole item as it can be accomodated
		{
			profit=profit+items[i].value;	
			currW=currW+items[i].weight;
		}
		else // Taking partial item
		{
			int remW=W-currW; // Remaining weight
			profit=profit + items[i].value*((double)remW/items[i].weight); // Taking only profit which can be gained by remaining weight
			break;
		}
	}
	return profit;
}

int main()
{
	int n,W;
	cin >> n >> W;
	
	Item *items = new Item[n];
	for(int i=0;i<n;i++)
		cin >> items[i].value >> items[i].weight;

	cout << getMaxProfit(items,n,W) << endl;	
    
    return 0;
}