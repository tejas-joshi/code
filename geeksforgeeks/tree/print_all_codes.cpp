// GIVEN AN int ARRAY PRINT ALL THE POSSIBLE CODES...


/*
Consider a coding system for alphabets to integers where ‘a’ is represented as 1, ‘b’ as 2, .. ‘z’ as 26. 
Given an array of digits (1 to 9) as input, write a function that prints all valid interpretations of input array.

Examples

Input: {1, 1}
Output: ("aa", 'k") 
[2 interpretations: aa(1, 1), k(11)]

Input: {1, 2, 1}
Output: ("aba", "au", "la") 
[3 interpretations: aba(1,2,1), au(1,21), la(12,1)]

Input: {9, 1, 8}
Output: {"iah", "ir"} 
[2 interpretations: iah(9,1,8), ir(9,18)]

Logic :
* array length is n..
* input array is arrCodes ... 
* codes is global array for mapping..(e.g. 1-a,2-b..) .. you can pass it to each function if global is not allowed.

1) Use BFS strategy to solve this problem.
2) You can either use single digit number(1-9) or use two digit number(10-26).
3) structure containing string and dRem... 
	string to store the already build string
	dRem is the index of the array from which we are going to start
4) Initially push ("",0)
5)
* 	while Q is not empty
	{
		nd = take front element of queue
		sInd = nd->sInd		// taking the starting index for which we will include char
		str = nd->word
		
		if sInd is n 
			print str 
		else
			// for single digit number
			if sInd is in 1-9 then
				c = take the char at that index from arrCodes
				and push the new node with (str+c) and sInd+1
				
				// for double digit number
				if check the length
					compute the number by taking two digit
					if it is in 10-26 then
						c = char at that index from arrCodes
						and push the new node with (str+c) and sInd+2
					endif
				endif
			endif
		endif
	}	
*/

#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

string codes[27] = {"","a","b","c","d","e","f","g","h","i","j","k","l","m",
					"n","o","p","q","r","s","t","u","v","w","x","y","z"};

typedef struct node_n
{
	string word;
	int startInd;
} node;

node *createNode(string str,int startInd)
{
	node *nd = new node;
	nd->word = str;
	nd->startInd = startInd;
	return nd;
}

void printCodes(node *nd,int n,int *arrCode)
{
	queue<node *> Q;	
	Q.push(nd);	
	
	while(!Q.empty())
	{
		node *nd = Q.front();
		string s = nd->word;
		int startInd = nd->startInd;
		
		if(startInd==n)			// printing the word
			cout << s << endl;
		else
		{
			int singleDigit,doubleDigit;

			singleDigit = arrCode[startInd++];		// for single digit and index incremented							
			if(singleDigit!=0)			// checking the digit
			{
				node *newNode = createNode(s + codes[singleDigit],startInd);			
				Q.push(newNode);
				
				if(startInd<n)		// checking the length
				{
					doubleDigit = singleDigit*10 + arrCode[startInd++];	// for double digit and index incremented
					if(doubleDigit>=1 && doubleDigit<=26)		// checking the number
					{
						node *newNode = createNode(s + codes[doubleDigit],startInd);			
						Q.push(newNode);
					}				
				}
			}
		}
		
		Q.pop();	// popping from queue
		delete nd;	// delete the node
	} 
}

void printCodesWrapper(int n,int *arrCode)
{
	// initially we are going to start from index 0 and blank string
	
	string s="";
	node *nd = createNode(s,0);		
	
	printCodes(nd,n,arrCode);
}

int main()
{
	int *A,n;	

	cin >> n;
	A = new int[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	
	printCodesWrapper(n,A);
		
	return 0;	
}
