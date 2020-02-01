#include <iostream>
#include <map>

#include "SieveOfEratosthenes.hpp"

int main(int argc, char** argv) {
    auto primes = segmentedSieve(200'000);
    if (primes.size() < 10'001) {
        std::cout << "Only produced " << primes.size() << ". Not enough." << std::endl;
    } else {
        std::cout << "The 10,001st prime is: " << primes[10'000] << std::endl;
    }

    return 0;
}
