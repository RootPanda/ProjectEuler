#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <set>
#include <list>
#include <cmath>
#include "gmpxx.h"

using namespace std;


set<unsigned int> productSet;

void checker(unsigned int i, unsigned int j)
{
		unsigned int product = 0;
		bool invalid = false;
		string toAnalyze = string("");
		product = i * j;

		invalid = false;

		toAnalyze = string(to_string(i));
		toAnalyze.append(to_string(j));
		toAnalyze.append(to_string(product));


		set<unsigned int> tracker;
		for (unsigned int i = 0; i < toAnalyze.length(); i++)
		{
			unsigned int candidate = (unsigned int)(toAnalyze[i] - '0');
			if (candidate == 0)
				{
				invalid = true;
				break;
			}
			else if (tracker.find(candidate) == tracker.end())
			{
				tracker.insert(candidate);
			}
			else 
			{
				invalid = true;
				break;
			}
		}

		//cout << i << " * " << j << " = " << i * j << " " << toAnalyze << endl;
		if (!invalid && tracker.size() == 9)
		{
			//cout << "FLAG " << tracker.size() << endl;
			productSet.insert(product);
		}

}



int main() 
{
	for (int i = 1; i < 99; i++)
	{
		for (int j = i; j < 9999; j++)
		{
			checker(i, j);
		}
	}

	for (int i = 1; i < 999; i++)
	{
		for (int j = i; j < 999; j++)
		{
			checker(i, j);
		}
	}

	unsigned int total = 0;

	set<unsigned int>::iterator it;

	for (it = productSet.begin(); it !=  productSet.end(); it++)
		total += *it;

	cout << "Answer: " << total << endl;
}

