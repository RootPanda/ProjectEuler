#include <cmath>
#include <iostream>

bool isPerfectSquare(int number) {
    auto squareRoot = sqrt(number);
    return ((squareRoot - floor(squareRoot)) == 0);
}

int main(int argc, char** argv) {
    auto ans = 0;
    for (auto a = 1; a < 1000; ++a) {
        for (auto b = a; b < 1000; ++b) {
            const auto c2 = pow(a, 2) + pow(b, 2);
            if (!isPerfectSquare(c2)) {
                continue;
            } else if (a + b + sqrt(c2) == 1000) {
                std::cout << "a: " << a << ". b: " << b << ". c: " << sqrt(c2) << std::endl;
                ans = a * b * sqrt(c2);
            }
        }
    }
    std::cout << "Product abc such that a2 + b2 = c2 and a + b + c = 1000: " << ans << std::endl;
    return 0;
}
