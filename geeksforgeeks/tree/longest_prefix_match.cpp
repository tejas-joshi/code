Longest prefix matching
=======================

Given a dictionary of words and an input string, find the longest prefix of the string which is also a word in dictionary.

Examples:

Let the dictionary contains the following words:
{are, area, base, cat, cater, children, basement}

Below are some input/output examples:
--------------------------------------
Input String            Output
--------------------------------------
caterer                 cater
basemexy                base
child                   < Empty >

Solution
========
We build a Trie of all dictionary words. Once the Trie is built, traverse through it using characters of input string. 
If prefix matches a dictionary word, store current length and look for a longer match. Finally, return the longest match.

Refer Trie Insert and Search program for building the Trie.

Time Complexity
===============
Time complexity of finding the longest prefix is O(n) where n is length of the input string. 
