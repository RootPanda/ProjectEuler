#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// buffer must have length >= sizeof(int) + 1
// Write to the buffer backwards so that the binary representation
// is in the correct order i.e.  the LSB is on the far right
// instead of the far left of the printed string
char *int2bin(int a, char *buffer, int buf_size)
{
    buffer += (buf_size - 1);

    for (int i = 31; i >= 0; i--)
    {
        *buffer-- = (a & 1) + '0';

        a >>= 1;
    }

    return buffer;
}

// Checks if a number is a palindrome.
// Can also check the base-two representation of that number.
static bool isPalindrome(int number, bool base2)
{
    char numAscii[33] = {};

    char * numAsciiStart = numAscii;

    if (base2)
    {
        int2bin(number, numAscii, sizeof(numAscii) - 1);

        // Put numAsciiStart at the first '1'
        while (*numAsciiStart && *numAsciiStart != '1')
        {
            numAsciiStart++;
        }

    }
    else
    {
        snprintf(numAscii, sizeof(numAscii), "%d", number);
    }
    //cout << numAsciiStart << endl;

    char * ptr1 = numAsciiStart;
    char * ptr2 = numAsciiStart;

    char * tempPtr = numAsciiStart;

    // Get the last char of this string
    while (*tempPtr)
    {
        tempPtr++;
        if (!*tempPtr)
        {
            break;
        }
        ptr2++;
    }

    // At this point, ptr1 is the start and ptr2 is the end.
    // So start checking if it's a palindrome.
    bool isPalindrome = true;
    while (ptr1 < ptr2)
    {
        if (*ptr1 != *ptr2)
        {
            isPalindrome = false;
            break;
        }
        ptr1++;
        ptr2--;
    }
    return isPalindrome;

}

int main(int argc, char *argv[])
{
    int partialSum = 0;

    // Loop from 1 to 1mill and check if its a palindrome in both b10 and b2.
    for (int i = 0; i < 1000000; i++)
    {
        if (isPalindrome(i, false) && isPalindrome(i, true))
        {
            partialSum += i;
            cout << i << endl;
        }
    }
    //cout << isPalindrome(585, false) << endl;
    cout << "Sum of all palindromes less than 1 mill: " << partialSum << endl;

    return 0;
}
