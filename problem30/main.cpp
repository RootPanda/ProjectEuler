#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include "gmpxx.h"

using namespace std;

set<int> results;

int fifth_power_digit_sum(int n)
{
	string n_str = std::to_string(n);

	int sum = 0;
	
	for (char& c : n_str)
	{
		sum += pow((c-'0'), 5);
		//cout << sum << endl;
	}

	return sum;
}

int main() 
{
	int answer = 0;
	for (int i = 2; i < 1000000; i++)
	{
		if (i == fifth_power_digit_sum(i))
		{
			cout << i << endl;
			answer += i;
			results.insert(i);
		}
	}
	cout << "Answer: " << answer << endl;
}



