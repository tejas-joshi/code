/*
 * 
 * BASIC STRUCTURE OF TRIE
 * FUNCTIONS : INSERT, SEARCH
 *
 */

#include<iostream>
#include<string.h>
#define CHAR_TO_INT(c) ((int)c-(int)'a')
using namespace std;

struct trie_node_t 
{
	int value;				// if the value in the node is not 0 then some string has last character at previous level node... 
	trie_node_t *ptr[26];	
};

struct trie_ADT
{
	int count;				// number of strings which has been inserted to trie
	trie_node_t *root;		// the root of the trie
};

typedef struct trie_node_t trieNode;
typedef struct trie_ADT trie;

trieNode *createNode()
{
	trieNode *temp = new trieNode;
	temp->value=0;
	for(int i=0;i<26;i++)
		temp->ptr[i] = NULL;	
	return temp;
}

// initializes the root of trie
void initialize(trie *trRoot)
{
	trRoot->count=0;	// no string has been inserted to initialized to 0
	trRoot->root = createNode();	// creating the root		
}

// insert the string str to trie
void insert(trie *rootTrie,char str[])
{
	rootTrie->count++;	// updating the count of the root

	// temp is to crawl through the trie created
	trieNode *temp = rootTrie->root;

	int ind;
	int l = strlen(str);
	
	// this code can also be optimized because here length is calculated before and then below loop...
	// instead we can go till we dont find NULL in the string.. it saves one scan... 
	
	for(int i=0;i<l;i++)
	{
		ind = CHAR_TO_INT(str[i]);	// converts the ascii(97-122) to corresponding index(0-25)
		if(!temp->ptr[ind])	// if node is not present
			temp->ptr[ind] = createNode();
		temp = temp->ptr[ind];	// go to next level		
	}		

	temp->value = rootTrie->count;	// updating the value of the node... indicating the end of string
	// note that we have already ended the string in the loop.. so we have come to the next level where the last character of the string is on the previous 
	// level and the value we have set in the current node...  you can treat it as the NULL indication ( if the value is not 0 )
}

bool search(trie *rootTrie,char str[])
{
	trieNode *temp = rootTrie->root;
	int len = strlen(str);
	int ind;

	for(int i=0;i<len;i++)
	{
		ind = CHAR_TO_INT(str[i]);	
		if(!temp->ptr[ind])		// found null node so returning false
			return false;
		temp = temp->ptr[ind];	// go to  next level
	}	
	
	return (temp && temp->value);	// checking the current node for null and 
	//the value for checking whether any string is completing at this node	
}

int main()
{
	trie trRoot;
	string in;
	initialize(&trRoot);
	
	while(1)
	{
		cin >> in;			
		if(in.compare("end")==0)
			break;
		insert(&trRoot,(char *)in.c_str());
	}
	
	while(1)
	{
		cin >> in;		
		if(in.compare("end")==0)
			break;
		cout << " found : " << search(&trRoot,(char *)in.c_str()) << endl;
	}	
	
	return 0;	
}
