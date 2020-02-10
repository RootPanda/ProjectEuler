#include <iostream>
#include <map>
#include <vector>

int main(int argc, char** argv) {
    auto chainLength = std::map<int, int>{};
    struct LongestChainInfo {
        unsigned int startNum{0u};
        unsigned int chainLength{0u};
    };
    auto longestChain = LongestChainInfo{};
    chainLength[1u] = 1;
    for (auto startNum = 2u; startNum < 1'000'000u; ++startNum) {
        auto currentChainLength = 0u;
        auto collatzBurndown = startNum;
        auto numbersToIndex = std::vector<unsigned int>{};
        numbersToIndex.push_back(startNum);
        while (collatzBurndown != 1u) {
            if (collatzBurndown % 2 == 0) {
                collatzBurndown /= 2;
            } else {
                collatzBurndown = 3 * collatzBurndown + 1;
            }
            ++currentChainLength;
            if (chainLength.find(collatzBurndown) != end(chainLength)) {
                currentChainLength += chainLength[collatzBurndown];
                break;
            } else {
                numbersToIndex.push_back(collatzBurndown);
            }
        }
        chainLength[startNum] = currentChainLength;
        for (auto numberI = begin(numbersToIndex); numberI != end(numbersToIndex); numberI = next(numberI)) {
            chainLength[*numberI] = currentChainLength - std::abs(distance(numberI, begin(numbersToIndex)));
        }
        if (currentChainLength > longestChain.chainLength) {
            longestChain = {startNum, currentChainLength};
        }
    }
    std::cout << "The startNum that gives the largest chain length: " << longestChain.startNum
              << ". Chain length: " << longestChain.chainLength << std::endl;
    return 0;
}
