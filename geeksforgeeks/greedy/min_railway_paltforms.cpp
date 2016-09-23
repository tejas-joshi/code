////=========== Minimum Number of Platforms Required for a Railway/Bus Station
/*
Given arrival and departure times of all trains that reach a railway station, 
find the minimum number of platforms required for the railway station so that no train waits.

Input:  arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
        dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3

The idea is to consider all events in sorted order. 
Once we have all events in sorted order, we can trace the number of trains at any time keeping track of trains that have arrived, but not departed.

All events sorted by time.
Total platforms at any time can be obtained by subtracting total 
departures from total arrivals by that time.
 Time     Event Type     Total Platforms Needed at this Time                               
 9:00       Arrival                  1
 9:10       Departure             0
 9:40       Arrival                  1
 9:50       Arrival                  2
 11:00      Arrival                 3 
 11:20      Departure            2
 11:30      Departure            1
 12:00      Departure            0
 15:00      Arrival                 1
 18:00      Arrival                 2 
 19:00      Departure            1
 20:00      Departure            0

Minimum Platforms needed on railway station = Maximum platforms 
                                              needed at any time 
                                           = 3  

TC : O(nlogn)
										   
*/

#include<iostream>
#include<algorithm>
using namespace std;

int findMinPlatforms(int *arrival,int *departure, int n)
{
	// sorting both the arrays
	sort(arrival,arrival+n);
	sort(departure,departure+n);
	
	int arrCount=0,depCount=0;
	int platformCount=0;
	int maxPlatform=-1;
	while(arrCount<n && depCount<n)
	{
		// Some train has arrived to allocating new platform
		if(arrival[arrCount] < departure[depCount])
		{
			arrCount++;
			platformCount++;
			if(platformCount > maxPlatform)
				maxPlatform = platformCount;
		}		
		else // some train is leaving so decreasing platform count
		{
			depCount++;
			platformCount--;
		}
	}
	
	// Here we dont need to check for the rest of the elements
	// because here only departure elements can be non-empty and it will decrease platformCount and does not make any diff in the result
	
	return maxPlatform;
}

int main()
{
	int n;
	cin >> n;
	
	int *arrival = new int[n];
	int *departure = new int[n];
	for(int i=0;i<n;i++)
		cin >> arrival[i]  >> departure[i];	
	
	cout << findMinPlatforms(arrival,departure,n) << endl;
	
    return 0;
}