#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include "gmpxx.h"

using namespace std;

int get_cycle_length(int n)
{
	vector<int> seen_remainders;
	float dividend = 1.0 / n;
	//cout << dividend << endl;
	
	int power = ceil(abs(log10(dividend)));
	//cout << log10(dividend) << endl;
	//cout << power << endl;
	dividend = (int)(dividend * pow(10, power));
	//cout << dividend << endl;

	seen_remainders.push_back(dividend);

	int new_remainder;
	while (1)
	{
		new_remainder = ((int)(10 * dividend)) % n;
		//cout << new_remainder << endl;

		if (new_remainder == 0)
			return 0;
		
		// If remainder is in vector, we have cycled.
		if (find(seen_remainders.begin(), 
			seen_remainders.end(), new_remainder) != 
			seen_remainders.end())
		{
			break;
		}
		else
		{
			seen_remainders.push_back(new_remainder);
			dividend = new_remainder;
		}
		
	}

	int count = 0;
	for (vector<int>::iterator it=find(seen_remainders.begin(), 
		seen_remainders.end(), new_remainder);
		it != seen_remainders.end(); it++)
	{
		count++;
	}

	return count;

}


int main() 
{
	int max_i = 1;
	int max_val = 0;
	for (int i = 1; i <= 1000; i++)
	{
		int current_cycle_len = get_cycle_length(i);
		if (current_cycle_len > max_val)
		{
			max_i = i;
			max_val = current_cycle_len;
		}
	}
	cout << "Answer: " << max_i << endl;
}



