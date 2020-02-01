#pragma once

#include <cmath>
#include <vector>

// Calculate primes given a startInt, an endInt, and a set of known primes.
// This function will add all new primes found between startInt and endInt to
// knownPrimes.
inline void simpleSieve(long int startInt, long int endInt, std::vector<int>& knownPrimes) {
    if (endInt < startInt) {
        return;
    }

    auto primeCandidates = std::vector<bool>{};
    primeCandidates.resize(endInt - startInt + 1, true);

    // Mark multiples of known primes as not prime.
    for (const auto& knownPrime : knownPrimes) {
        for (auto notPrimeIndex = knownPrime; notPrimeIndex <= endInt; notPrimeIndex += knownPrime) {
            if (notPrimeIndex >= startInt) {
                primeCandidates[notPrimeIndex - startInt] = false;
            }
        }
    }

    // Traverse prime candidates and mark multiples as not prime.
    for (auto index = 0; index < primeCandidates.size(); ++index) {
        if (primeCandidates[index]) {
            for (auto notPrimeIndex = 2 * (index + startInt); notPrimeIndex < primeCandidates.size() + startInt;
                 notPrimeIndex += (index + startInt)) {
                primeCandidates[notPrimeIndex - startInt] = false;
            }
        }
    }

    // Output new primes.
    for (auto index = 0; index < primeCandidates.size(); ++index) {
        if (primeCandidates[index]) {
            knownPrimes.push_back(index + startInt);
        }
    }
}

// Find all prime numbers up to n using the segmented sieve of Eratosthenes.
inline std::vector<int> segmentedSieve(long int n) {
    auto primes = std::vector<int>{};
    auto startIndex = 2l;
    const auto increment = static_cast<long int>(std::floor(sqrt(n)));
    auto endIndex = increment;
    while (endIndex <= n) {
        simpleSieve(startIndex, endIndex, primes);
        if (endIndex == n) {
            break;
        }
        startIndex = endIndex + 1;
        endIndex = std::min(endIndex + increment, n);
    }
    return primes;
}
