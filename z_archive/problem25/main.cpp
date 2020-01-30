#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include "gmpxx.h"

using namespace std;

map<mpz_class, mpz_class> fibonacci_set;

mpz_class f_n(mpz_class n)
{
	mpz_class retVal = 1;
	if (fibonacci_set[n] != mpz_class())
	{
		retVal = fibonacci_set[n];
	}
	else if (n > 2)
	{
		retVal = f_n(n-1) + f_n(n-2);
		fibonacci_set[n] = retVal;
		
		// Now determine the length of the string
		char * p = mpz_get_str(NULL, 10, retVal.get_mpz_t());
		int count = 0;
		for (p; *p != 0; p++)
		{
			count++;
		}

		//cout << "Adding " << retVal << " to the set, strlen " 
		//	<< count << endl;

		static bool firstSeen = false;
		if (count == 1000 && !firstSeen)
		{
			cout << "Answer: " << n << endl;
			firstSeen = true;
		}
	}
	return retVal;
}


int main() 
{
	fibonacci_set[0] = 1;
	fibonacci_set[1] = 1;
	fibonacci_set[2] = 1;
	//cout << "Answer: " << sizeof(mpz_get_str(NULL, 10, f_n(100).get_mpz_t())) << endl;
	f_n(5000);
}



