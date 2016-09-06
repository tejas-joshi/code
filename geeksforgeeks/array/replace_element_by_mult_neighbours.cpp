// ======== Replace every array element by multiplication of previous and next

/* 
Given an array of integers, update every element with multiplication of previous and next elements with following exceptions. 
a) First element is replaced by multiplication of first and second.
b) Last element is replaced by multiplication of last and second last.

Input: arr[] = {2, 3, 4, 5, 6}
Output: arr[] = {6, 8, 15, 24, 30}

// We get the above output using following
// arr[] = {2*3, 2*4, 3*5, 4*6, 5*6} 

The idea is to keep track of previous element in loop.
Handle first and last elements separately.

TC : O(n)
SC : O(1)

 */

#include<iostream>
using namespace std;

void modify(int arr[], int n)
{
    // Nothing to do when array size is 1
    if (n <= 1)
      return;
 
    // store current value of arr[0] and update it
    int prev = arr[0];
    arr[0] = arr[0] * arr[1];
 
    // Update rest of the array elements
    for (int i=1; i<n-1; i++)
    {
        // Store current value of next interation
        int curr = arr[i];
 
        // Update current value using previos value
        arr[i] = prev * arr[i+1];
 
        // Update previous value
        prev = curr;
    }
 
    // Update last array element
    arr[n-1] = prev * arr[n-1];
}
