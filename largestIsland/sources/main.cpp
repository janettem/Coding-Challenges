#include "largestIsland.h"
#include <iostream>

int main()
{
    std::cout << (countLargestIslandSize({{1, 0, 0}, {0, 0, 0}, {0, 0, 1}}) == 1);
    std::cout << (countLargestIslandSize({{1, 1, 0}, {0, 1, 1}, {0, 0, 1}}) == 5);
    std::cout << (countLargestIslandSize({{1, 0, 0}, {1, 0, 0}, {1, 0, 1}}) == 3);
    std::cout << (countLargestIslandSize({{0, 0, 0}, {0, 1, 1}, {0, 1, 1}}) == 4);
    std::cout << (countLargestIslandSize({{1, 0, 0}, {0, 0, 1}, {0, 0, 1}}) == 2);
    std::cout << (countLargestIslandSize({{1, 0, 0}, {0, 1, 1}, {0, 0, 1}}) == 4);
    std::cout << (countLargestIslandSize({{1, 0}, {0, 1}, {0, 0}}) == 2);
    std::cout << (countLargestIslandSize({{1}}) == 1);
    std::cout << (countLargestIslandSize({{1}, {0}, {1}}) == 1);
    std::cout << (countLargestIslandSize({{1, 1, 1}, {0, 1, 1}, {0, 0, 1}}) == 6);
    std::cout << std::endl;
    return 0;
}
