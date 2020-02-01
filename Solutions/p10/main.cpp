#include <iostream>
#include <numeric>

#include "SieveOfEratosthenes.hpp"

int main(int argc, char** argv) {
    auto primes = segmentedSieve(2'000'000);

    std::cout << "Sum of primes below two million: " << std::accumulate(begin(primes), end(primes), 0l) << std::endl;

    return 0;
}
