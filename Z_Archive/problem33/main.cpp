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

	set<int> digitSet;
	
	for (int i = 98; i < 99 && i > 9; i--)
	{
		for (int j = i - 1; j < 99 && j > 9; j--)
		{
			string compare = string("");
			compare = string(to_string(j));
			compare.append(to_string(i));
			//cout << j << " / " << i << " = " << compare << endl;
			if ( (int)(compare[0]-'0') == (int)(compare[3]-'0') && (int)(compare[0]-'0') != 0)
			{
				//cout << j << " / " << i << " = " << compare << endl;
				
				if( ((double)(j)/(double)(i)) == ((double)(compare[1]-'0')/(double)(compare[2]-'0')) )
				{
					digitSet.insert(((j*100)+i));
					
				}

			}
			else if ( (int)(compare[1]-'0') == (int)(compare[2]-'0') && (int)(compare[1]-'0') != 0)
			{
				//cout << j << " / " << i << " = " << compare << endl;
				//cout << ((double)(j)/(double)(i)) << " = " << ((double)(compare[1]-'0')/(double)(compare[2]-'0')) << endl;
				if( ((double)(j)/(double)(i)) == ((double)(compare[0]-'0')/(double)(compare[3]-'0')) )
				{
					digitSet.insert(((j*100)+i));
					
				}
			}
			

		}
	}

	

	int total = 0;

	set<int>::iterator it;

	for (it = digitSet.begin(); it !=  digitSet.end(); it++)
		cout << "Answer: " << *it << endl;
		total += 1;

	cout << "Answer: " << total << endl;
}

