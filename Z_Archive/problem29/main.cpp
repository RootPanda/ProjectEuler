#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include "gmpxx.h"

using namespace std;

set<mpz_class> distinct_powers;

int main() 
{
	for (int a = 2; a <= 100; a++)
	{
		for (int b = 2; b <= 100; b++)
		{
			mpz_class c;
			mpz_ui_pow_ui(c.get_mpz_t(), a, b);
			distinct_powers.insert(c);
			cout << a << "^" << b << "=" << mpz_class(c) << endl;
		}
	}

	cout << "Answer: " << distinct_powers.size() << endl;
}



