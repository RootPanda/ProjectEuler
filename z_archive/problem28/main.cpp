#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include "gmpxx.h"

using namespace std;

// 1001 x 1001 matrix has 0..500 rings, with the zeroth 'ring' being 1
int sum_ring(int n)
{
	// The nth ring starts with (2n+1)^2
	int square = (2*n+1) * (2*n+1);

	// Now add the square 4 times, less 2n each time
	int sum = square;
	sum += square - 2*n;
	sum += square - 4*n;
	sum += square - 6*n;

	return sum;
}

int main() 
{
	int sum = 1;

	for (int i = 1; i <= 500; i++)
	{
		sum += sum_ring(i);
	}

	cout << "Answer: " << sum << endl;
}



