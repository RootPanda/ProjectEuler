#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

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
	vector<int> abundant_nums;
	set<int> abundant_nums_sums;
	for (int i = 1; i < 28124; i++)
	{
		if (i < d(i))
		{
			abundant_nums.push_back(i);
			//cout << i << endl;
		}
	}
	
	//sort(abundant_nums.begin(), namesVect.end());

	int retVal = 0;

	bool isGood = true;
	for (vector<int>::iterator it = abundant_nums.begin(); 
		it != abundant_nums.end(); ++it)
	{
		abundant_nums_sums.insert((*it) + 
			*(abundant_nums.begin()));
		for (vector<int>::iterator it2 = 
			abundant_nums.begin(); 
			it2 != abundant_nums.end() ; ++it2)
		{
			int insertSum = (*it) + (*it2);
			abundant_nums_sums.insert( insertSum );
		}
	}
	//cout << i << endl;
	//}

	for (set<int>::iterator it = abundant_nums_sums.begin(); 
		it != abundant_nums_sums.end(); ++it)
	{
		//cout << "ASDF " << *it << endl;
	}

	for (int i = 0; i < 30000; i++)
	{
		cout << i;
		if(!(find(abundant_nums_sums.begin(), 
			abundant_nums_sums.end(), i) != 
			abundant_nums_sums.end()))
		{
			retVal += i;
			cout << " YES";
		}
		cout << endl;
	}
	
	cout << "Answer: " << retVal << endl;
}



