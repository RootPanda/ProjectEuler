#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> permutations;

void perm(char* s, int n, int i)
{
	if (i >= n-1) 
	{
		//cout << s << endl;
		permutations.insert(string(s));
	}
	else 
	{
    		perm(s, n, i+1);
    		for (int j = i+1; j<n; j++){
      			swap(s[i], s[j]);
      			perm(s, n, i+1);
      			swap(s[i], s[j]);
    		}
  	}
}


int main() 
{
	set<int> abundant_nums_sums;
	char permArray[] = "0123456789";
	perm(permArray, 10, 0);

	int count = 1;
	for (set<string>::iterator it = permutations.begin(); 
		it != permutations.end(); it++)
	{
		cout << count << ": " << *it << endl;
		if (count == 1000000)
		{
			cout << "Answer: " << *it << endl;
			break;
		}
		count++;
	}
}



