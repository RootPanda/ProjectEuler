#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

static vector<bool> isPrime;
static vector<int> primes;

// Truncates the number by 1 digit. If leftTruncate true, truncates from left. Otherwise from the right.
static int truncate(int num, bool leftTruncate)
{
    char numString[14] = {};
    char * numStringPtr = numString;

    snprintf(numString, sizeof(numString), "%d", num);

    if (leftTruncate)
    {
        numStringPtr++;
    }
    else
    {
        char * ptr = numString;
        char * lastPtr = numString;
        while (*ptr)
        {
            ptr++;
            if (!*ptr)
            {
                *lastPtr = 0;
            }
            lastPtr = ptr;
        }
    }

    return atoi(numStringPtr);
}

static bool isTruncatablePrime(int candidate)
{
    if (candidate == 2 || candidate == 3 || candidate == 5 || candidate == 7)
        return false;

    // Check the left-truncates
    int temp = candidate;
    while (temp != 2 && temp != 3 && temp != 5 && temp != 7)
    {
        temp = truncate(temp, true);
        if (!isPrime[temp])
        {
            return false;
        }
    }

    // Check the right-truncates
    temp = candidate;
    while (temp != 2 && temp != 3 && temp != 5 && temp != 7)
    {
        temp = truncate(temp, false);
        if (!isPrime[temp])
        {
            return false;
        }
    }
    // If we get here, then we are a truncatable prime
    return true;

}

static void calculatePrimality(int candidate)
{
    // False if even, obviously
    if (candidate % 2 == 0)
    {
        return;
    }
    // Otherwise, check the list of primes for a divisor, only up to its sqrt
    else
    {
        bool targetIsPrime = true;
        for (int i = 0; i < primes.size(); i++)
        {
            if (candidate % primes[i] == 0)
            {
                targetIsPrime = false;
                break;
            }
            if (candidate < primes[i] * primes[i])
                break;
        }
        if (targetIsPrime)
        {
            primes.push_back(candidate);
            //cout << candidate << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    isPrime.assign(1000000, false);

    primes.push_back(2);

    // Calculate primality of each number upto 1 mill
    for (int i = 3; i < 1000000; i++)
    {
        calculatePrimality(i);
    }

    // Generate a list of only primes
    for (int i = 0; i < primes.size(); i++)
    {
        isPrime[primes[i]] = true;
    }

    int numTruncatablePrimes = 0;
    int truncatablePrimesSum = 0;
    // Go through the list of primes and check if its a truncatable prime
    for (int i = 0; i < primes.size(); i++)
    {
        if (isTruncatablePrime(primes[i]))
        {
            numTruncatablePrimes++;
            truncatablePrimesSum += primes[i];
            cout << primes[i] << endl;
        }
    }

    cout << "Truncatable primes: " << numTruncatablePrimes << endl;
    cout << "Sum: " << truncatablePrimesSum << endl;

    return 0;
}
