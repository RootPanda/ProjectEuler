#include <iostream>
#include <map>

#include "SieveOfEratosthenes.hpp"

int main(int argc, char** argv) {
    auto uniquePrimeFactors = std::map<int, int>{};
    for (auto num = 1; num <= 20; ++num) {
        auto primesToNum = segmentedSieve(num);
        auto toBurndown = num;
        auto localUniquePrimeFactors = std::map<int, int>{};
        while (toBurndown != 1) {
            for (const auto& prime : primesToNum) {
                if (toBurndown % prime == 0) {
                    toBurndown /= prime;
                    if (localUniquePrimeFactors.find(prime) != end(localUniquePrimeFactors)) {
                        ++localUniquePrimeFactors[prime];
                    } else {
                        localUniquePrimeFactors[prime] = 1;
                    }
                }
            }
        }

        // Reconcile local unique prime factors with the master table of unique prime factors.
        for (const auto& localUniquePrimeFactor : localUniquePrimeFactors) {
            if (uniquePrimeFactors.find(localUniquePrimeFactor.first) == end(uniquePrimeFactors) ||
                uniquePrimeFactors[localUniquePrimeFactor.first] < localUniquePrimeFactor.second) {
                uniquePrimeFactors[localUniquePrimeFactor.first] = localUniquePrimeFactor.second;
            }
        }
    }
    auto outputNumber = 1;
    for (const auto& uniquePrimeFactor : uniquePrimeFactors) {
        outputNumber *= (pow(uniquePrimeFactor.first, uniquePrimeFactor.second));
    }
    std::cout << "Smallest positive number evenly divisible by all numbers between 1-20: " << outputNumber << std::endl;

    return 0;
}
