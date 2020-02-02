#include <cmath>
#include <iostream>

int main(int argc, char** argv) {
    auto triangleNum = 0l;
    auto toAdd = 1;
    for (;;) {
        triangleNum += (toAdd++);
        auto numDivisors = 0;
        for (auto divisorCandidate = 1; divisorCandidate <= sqrt(triangleNum); ++divisorCandidate) {
            if (triangleNum % divisorCandidate == 0) {
                numDivisors += 2;
                if (numDivisors > 500) {
                    std::cout << "First triangle number with over 500 divisors: " << triangleNum << std::endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
