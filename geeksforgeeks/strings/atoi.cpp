// WRITE YOUR OWN atoi FUNCTION

// The atoi() function takes a string (which represents an integer) as an argument and returns its value.

// I dont think I need to explain the logic.. Just read the code.. You will easily understand..

#include<iostream>
using namespace std;

int fun_atoi(char *str)
{
	int num=0;
	while(*str)
	{
		num = num*10 + ((*str)-'0');
		str++;
	}
	return num;
}

int main()
{
	char str[] = "4567";
	cout << fun_atoi(str) << endl;
	return 0;
}
