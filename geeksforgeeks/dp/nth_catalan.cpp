//==== Program for nth Catalan Number
/*
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

C0=1
C(n+1) = sum(for i=0 to n  ... C0*C(n-i))

TC : O(n^2)
SC : O(n)

More efficient method is O(n)

nth Catalan = 2nCn
					----
					n+1

We can find nCk in O(k)					
so here TC will be O(n)
					
*/

#include<iostream>
using namespace std;


/// O(n) solution
unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
// A Binomial coefficient based function to find nth catalan
// number in O(n) time
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2*n, n);
 
    // return 2nCn/(n+1)
    return c/(n+1);
}

// O(n^2) solution
// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalan(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n+1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (int j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
 
    // Return last entry
    return catalan[n];
}

int main()
{
	int n;
	cin >> n;
	cout << catalan(n) << endl;
	
	return 0;
}
