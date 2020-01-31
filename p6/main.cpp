#include <cmath>
#include <iostream>

// Find the sum of squares up to k > 0.
int sumOfSquares(int k) {
    auto output = 0;
    for (int i = 1; i <= k; ++i) {
        output += pow(i, 2);
    }
    return output;
}

// Find the square of the sum up to k > 0.
int squareOfSum(int k) {
    auto sum = 0;
    for (int i = 1; i <= k; ++i) {
        sum += i;
    }
    return pow(sum, 2);
}

int main(int argc, char** argv) {
    const auto number = 100;
    std::cout << "Difference between sum of the squares and the square of the sum "
              << abs(sumOfSquares(number) - squareOfSum(number)) << std::endl;

    return 0;
}
