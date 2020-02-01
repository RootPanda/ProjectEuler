#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(int number) {
    auto numString = std::to_string(number);
    if (numString.empty()) {
        return true;
    }
    auto frontI = begin(numString);
    auto backI = prev(end(numString));
    while (frontI < backI) {
        if (*frontI != *backI) {
            return false;
        }
        frontI = next(frontI);
        backI = prev(backI);
    }
    return true;
}

int main(int argc, char** argv) {
    auto products = std::vector<int>{};
    for (auto i = 100; i <= 999; ++i) {
        for (auto j = 100; j <= 999; ++j) {
            products.push_back(i * j);
        }
    }
    std::sort(begin(products), end(products), [](const int& p1, const int& p2) { return p1 > p2; });
    auto largestPalindrome = 0;
    for (const auto& product : products) {
        if (isPalindrome(product)) {
            largestPalindrome = product;
            break;
        }
    }
    std::cout << "Largest palindrome of two 3-digit numbers is " << largestPalindrome << std::endl;

    return 0;
}
