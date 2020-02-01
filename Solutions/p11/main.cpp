#include <array>
#include <iostream>

auto matrix = std::array<std::array<int, 20>, 20>{
    std::array<int, 20>{8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
    std::array<int, 20>{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
    std::array<int, 20>{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
    std::array<int, 20>{52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
    std::array<int, 20>{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
    std::array<int, 20>{24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
    std::array<int, 20>{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
    std::array<int, 20>{67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
    std::array<int, 20>{24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
    std::array<int, 20>{21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
    std::array<int, 20>{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
    std::array<int, 20>{16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
    std::array<int, 20>{86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
    std::array<int, 20>{19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
    std::array<int, 20>{4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
    std::array<int, 20>{88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
    std::array<int, 20>{4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
    std::array<int, 20>{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
    std::array<int, 20>{20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
    std::array<int, 20>{1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};

int main(int argc, char** argv) {
    auto greatestProduct = 0;
    for (auto rowIdx = 0; rowIdx < matrix.size(); ++rowIdx) {
        for (auto colIdx = 0; colIdx < matrix[rowIdx].size(); ++colIdx) {
            // Check horizontally
            if (colIdx < matrix[rowIdx].size() - 3) {
                const auto horizontalProduct = matrix[rowIdx][colIdx] * matrix[rowIdx][colIdx + 1] *
                                               matrix[rowIdx][colIdx + 2] * matrix[rowIdx][colIdx + 3];
                if (horizontalProduct > greatestProduct) {
                    greatestProduct = horizontalProduct;
                }
            }

            // Check vertically
            if (rowIdx < matrix.size() - 3) {
                const auto verticalProduct = matrix[rowIdx][colIdx] * matrix[rowIdx + 1][colIdx] *
                                             matrix[rowIdx + 2][colIdx] * matrix[rowIdx + 3][colIdx];
                if (verticalProduct > greatestProduct) {
                    greatestProduct = verticalProduct;
                }
            }

            // Check top-left to bottom-right diagonal
            if (colIdx < matrix[rowIdx].size() - 3 && rowIdx < matrix.size() - 3) {
                const auto diagProduct = matrix[rowIdx][colIdx] * matrix[rowIdx + 1][colIdx + 1] *
                                         matrix[rowIdx + 2][colIdx + 2] * matrix[rowIdx + 3][colIdx + 3];
                if (diagProduct > greatestProduct) {
                    greatestProduct = diagProduct;
                }
            }

            // Check top-right to bottom-left diagonal
            if (colIdx >= 3 && rowIdx < matrix.size() - 3) {
                const auto diagProduct = matrix[rowIdx][colIdx] * matrix[rowIdx + 1][colIdx - 1] *
                                         matrix[rowIdx + 2][colIdx - 2] * matrix[rowIdx + 3][colIdx - 3];
                if (diagProduct > greatestProduct) {
                    greatestProduct = diagProduct;
                }
            }
        }
    }
    std::cout << "Greatest product: " << greatestProduct << std::endl;
    return 0;
}
