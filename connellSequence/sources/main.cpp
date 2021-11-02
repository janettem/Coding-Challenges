#include "connellSequence.h"
#include <iostream>

int main()
{
    std::cout << (findInConnellSequence(1, 3, 4) == 2);
    std::cout << (findInConnellSequence(2, 3, 4) == 1);
    std::cout << (findInConnellSequence(4, 5, 22) == -1);
    std::cout << (findInConnellSequence(1, 1, 1) == 0);
    std::cout << (findInConnellSequence(1, 1, 0) == -1);
    std::cout << (findInConnellSequence(1, 100, 100) == 54);
    std::cout << (findInConnellSequence(4, 5, 77) == -1);
    std::cout << (findInConnellSequence(11, 22, 300) == 103);
    std::cout << (findInConnellSequence(30, 32, 974) == 67);
    std::cout << (findInConnellSequence(13, 88, 300) == 80);
    std::cout << (findInConnellSequence(1, 1000, 8000) == 4044);
    std::cout << (findInConnellSequence(111, 1000, 8000) == -1);
    std::cout << std::endl;
    return 0;
}
