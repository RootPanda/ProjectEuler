#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
    auto fibonacciNumbers = std::vector<int>{1, 2};
    auto sum = 2;
    while (fibonacciNumbers.back() < 4000000) {
        auto lastI = end(fibonacciNumbers) - 1;
        fibonacciNumbers.push_back(*lastI + *(lastI - 1));
        if (fibonacciNumbers.back() % 2 == 0) {
            sum += fibonacciNumbers.back();
        }
    }
    std::cout << "Sum of fibonacci numbers below 4 million: " << sum << std::endl;

    return 0;
}
