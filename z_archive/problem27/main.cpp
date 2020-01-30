#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include "gmpxx.h"

using namespace std;

set<int> primes;
set<int> not_primes;

// This is the Sieve of Eratostenes
void prime_sieve(int n)
{
	primes.insert(1);
	for (int i = 2; i < n; i++)
	{
		if (not_primes.find(i) != not_primes.end())
		{
			continue;
		}
		else
		{
			//cout << "Prime: " << i << endl;
			primes.insert(i);
		}

		for (int j = i * 2; j < n; j+=i)
		{
			//cout << "Not a prime: " << j << endl;
			not_primes.insert(j);
		}
	}
}


int q(int n, int a, int b)
{
	return n*n + a*n + b;
}

int max_consecutive_primes(int a, int b)
{
	int retVal = 0;
	while (1)
	{
		if (primes.find(q(retVal, a, b)) == primes.end())
		{
			break;
		}
		else
		{
			retVal++;
		}
	}

	return retVal;

}

int main() 
{
	prime_sieve(3000000);

	int max_consecutive_seen = 0;
	int max_a = 10000;
	int max_b = 10000;
	for (int a = -1000; a <= 1000; a++)
	{
		for (int b = -1000; b <= 1000; b++)
		{
			int candidate = max_consecutive_primes(a,b);
			if (candidate > max_consecutive_seen)
			{
				max_consecutive_seen = candidate;
				max_a = a;
				max_b = b;
			}
		}
	}

	cout << "Answer: " << max_a * max_b << endl;
}



