#include <iostream>
//#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int factorial(int x)
{
    int retVal = 0;

    switch (x) {
    case 0:
        retVal = 1;
        break;
    case 1:
        retVal = 1;
        break;
    case 2:
        retVal = 2;
        break;
    case 3:
        retVal = 6;
        break;
    case 4:
        retVal = 24;
        break;
    case 5:
        retVal = 120;
        break;
    case 6:
        retVal = 720;
        break;
    case 7:
        retVal = 5040;
        break;
    case 8:
        retVal = 40320;
        break;
    case 9:
        retVal = 362880;
        break;
    default:
        break;
    }

    return retVal;
}

int main(int argc, char *argv[])
{
    int finalSum = 0;
    for (int i = 3; i < 100000000; i++)
    {
        //qDebug() << factorial(i);
        char str[10] = {};
        snprintf(str, sizeof(str), "%d", i);

        char * strPtr = str;
        char oneChar[2] = {};

        int currentSum = 0;
        while (*strPtr)
        {
            snprintf(oneChar, sizeof(oneChar), strPtr);
            strPtr++;

            currentSum += factorial(atoi(oneChar));
        }

        if (currentSum == i)
        {
            printf("%d \n", currentSum);
            finalSum += currentSum;
        }

    }

    printf("FINAL: %d \n", finalSum);

    return 0;
}
