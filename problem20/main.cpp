#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include "gmpxx.h"

using namespace std;

mpz_class iter_factorial(mpz_class &n)
{
	mpz_class ret = 1;
	for(mpz_class i = 1; i <= n; ++i)
		ret *= i;
	return ret;
}

int main() 
{
	mpz_class input = 100;
	mpz_class input_factorial = iter_factorial(input);
	char * outString = mpz_get_str(NULL, 10, input_factorial.get_mpz_t());
	char * p = outString;

	int retVal = 0;
	while (*p)
	{
		retVal += (int)(*p) - '0';
		p++;
	}
	cout << "Answer: " << retVal << endl;
}
