#include <vector>
#include <iostream>

int main(int argc, char **argv)
{
    auto multiplesOfThreeOrFive = std::vector<int>{};
    for (auto num = 1; num < 1000; ++num) {
        if (num % 3 == 0 || num % 5 == 0) {
            multiplesOfThreeOrFive.push_back(num);
        }
    }
    auto sum = 0;
    for (const auto& multiple : multiplesOfThreeOrFive) {
        sum += multiple;
    }
    std::cout << "Sum of numbers below 1000: " << sum << std::endl;

    return 0;
}
