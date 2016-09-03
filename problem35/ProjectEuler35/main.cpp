#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

using namespace std;

static vector<bool> isPrime;
static vector<int> primes;

// Shift the number left by 1 decimal
static int circularShift(int num)
{
    char numString[14] = {};
    snprintf(numString, sizeof(numString), " %d", num);
    char * ptr = numString;
    char * lastPtr = numString;
    while (*ptr)
    {
        ptr++;
        if (!*ptr)
        {
            *numString = *lastPtr;
            *lastPtr = 0;
        }
        lastPtr = ptr;
    }
    return atoi(numString);
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

    //isPrime[1] = true;
    //isPrime[2] = true;


    for (int i = 3; i < 1000000; i++)
    {
        calculatePrimality(i);
    }

    primes.push_back(2);

    for (int i = 0; i < primes.size(); i++)
    {
        isPrime[primes[i]] = true;
    }

    int totalCircularPrimes = 0;

    for (int i = 0; i < primes.size(); i++)
    {
        int originalPrime = primes[i];
        cout << "Checking " << originalPrime << "... ";

        int shiftedPrime = circularShift(originalPrime);

        bool isCircularPrime = true;

        while (shiftedPrime != originalPrime)
        {
            if (!isPrime[shiftedPrime])
            {
                isCircularPrime = false;
                break;
            }
            shiftedPrime = circularShift(shiftedPrime);
        }

        if (isCircularPrime)
        {
            cout << "CIRCULAR PRIME." << endl;
            totalCircularPrimes++;
        }
        else
        {
            cout << "NOT CIRCULAR PRIME." << endl;
        }
    }

    cout << totalCircularPrimes << endl;

    return 0;
}
