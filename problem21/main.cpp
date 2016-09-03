#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include "gmpxx.h"

using namespace std;

int d(int n)
{
	int retVal = 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			retVal += i;
		}
	}
	return retVal;
}

int main() 
{
	int d_map[25500] = {};	// Adjusted for largest: 25320
	int largest = 0;
	for (int i = 1; i < sizeof(d_map)/sizeof(int); i++)
	{
		d_map[i] = d(i);
		/*
		if (d_map[i] > largest)
		{
			largest = d_map[i];
		}
		*/
	}
	//cout << "Largest: " << largest << endl;;
	cout << d_map[1] << endl;
	cout << d_map[220] << endl;
	cout << d_map[284] << endl;
	int answer = 0;
	for (int i = 1; i < 10000; i++)
	{
		if (i == d_map[d_map[i]] && i != d_map[i])
		{
			cout << i << endl;
			answer += i;
		}
	}
	cout << "Answer: " << answer << endl;
}
