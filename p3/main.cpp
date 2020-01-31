#include <iostream>
#include <vector>

#include "SieveOfEratosthenes.hpp"

int main(int argc, char** argv) {
    const auto number = 600851475143;
    auto primes = segmentedSieve(number);
    auto largestPrimeFactor = 1;
    for (const auto& prime : primes) {
        if (number % prime == 0) {
            largestPrimeFactor = prime;
        }
    }
    std::cout << "Largest prime factor of " << number << " is " << largestPrimeFactor << std::endl;

    return 0;
}
