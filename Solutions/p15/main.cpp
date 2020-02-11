#include <iostream>
#include <map>
#include <vector>

int main(int argc, char** argv) {
    auto paths = std::map<std::pair<int, int>, long long int>{};
    paths[{1, 1}] = 2;
    for (auto size = 2; size <= 20; ++size) {

        // Create path lengths for all right-sub-quadrilaterals.
        // For example, for size = 3 there are right-sub-quads (3,1), (3,2)
        const auto subQuadHeight = size;
        for (auto subQuadWidth = 1; subQuadWidth < size; ++subQuadWidth) {
            auto lowerSqPathI = paths.find({subQuadHeight - 1, subQuadWidth});
            auto rightSqPathI = paths.find({subQuadHeight, std::max(subQuadWidth - 1, 1)});

            paths[{subQuadHeight, subQuadWidth}] = 0;
            if (lowerSqPathI != end(paths)) {
                paths[{subQuadHeight, subQuadWidth}] += lowerSqPathI->second;
            }
            if (rightSqPathI != end(paths)) {
                paths[{subQuadHeight, subQuadWidth}] += rightSqPathI->second;
            } else {
                paths[{subQuadHeight, subQuadWidth}] += 1;
            }
            // std::cout << "Subquadheight: " << subQuadHeight << ". subquadwidth: " << subQuadWidth << ". path: ";
            // std::cout << paths[{subQuadHeight, subQuadWidth}] << std::endl;
        }

        // Total paths is paths of paths(size, size - 1) + paths(size - 1, size) = 2 * paths(size, size - 1)
        auto pathI = paths.find({size, size - 1});
        if (pathI != end(paths)) {
            paths[{size, size}] = 2 * pathI->second;
            std::cout << "Size: " << size << " has " << paths[{size, size}] << " paths." << std::endl;
        }

    }
    return 0;
}
