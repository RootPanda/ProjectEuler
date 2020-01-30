#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <set>
#include <list>
#include <cmath>
#include "gmpxx.h"

using namespace std;

class CoinCombo
{
public:
	CoinCombo(int _c_1, int _c_2, int _c_5, int _c_10, 
		int _c_20, int _c_50, int _c_100, int _c_200)
		: (c_1 = _c_1)
 	{}
		
	~CoinCombo() {}
	int sum() {}
	int c_1;
	int c_2;
	int c_5;
	int c_10;
	int c_20;
	int c_50;
	int c_100;
	int c_200;
};

set<CoinCombo> asdf;

// Use recursion to find all combinations of the smaller sets
int gen_perm(list<int> & next_perm, const list<int> & last_perm)
{
	next_perm = last_perm;
	list<int>::iterator it;
	// Find the first non-one entry
	for (it = next_perm.begin(); it != next_perm.end(); it++)
	{
		if (*it != 1)
			break;
	}
	if (it == next_perm.end())
	{
		return 1;
	}
	else
	{
		switch (*it)
		{
		case 200:
			next_perm.insert(it, 100);
			next_perm.insert(it, 100);
			next_perm.erase(it);
			break;
		case 100:
			next_perm.insert(it, 50);
			next_perm.insert(it, 50);
			next_perm.erase(it);
			break;
		case 50:
			next_perm.insert(it, 10);
			next_perm.insert(it, 20);
			next_perm.insert(it, 20);
			next_perm.erase(it);
			break;
		case 20:
			next_perm.insert(it, 10);
			next_perm.insert(it, 10);
			next_perm.erase(it);
			break;
		case 10:
			next_perm.insert(it, 5);
			next_perm.insert(it, 5);
			next_perm.erase(it);
			break;
		case 5:
			next_perm.insert(it, 1);
			next_perm.insert(it, 2);
			next_perm.insert(it, 2);
			next_perm.erase(it);
			break;
		case 2:
			next_perm.insert(it, 1);
			next_perm.insert(it, 1);
			next_perm.erase(it);
			break;
		default:	// Do nothing otherwise.
			break;
		}
		return 0;
	}
		
}

int main() 
{
	int answer = 1;

	list<int> last_perm;
	last_perm.push_back(200);

	list<int> next_perm;

	while (gen_perm(next_perm, last_perm) == 0)
	{
		last_perm = next_perm;

		
		cout << "ASDF" << endl;
		for (list<int>::iterator it = last_perm.begin();
			it != last_perm.end(); it++)
		{
			cout << *it << endl;
		}
		
		answer++;
		cout << answer << endl;
	}
	answer--;

	cout << "Answer: " << answer << endl;
}



