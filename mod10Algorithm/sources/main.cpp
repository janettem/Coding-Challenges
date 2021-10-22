#include "mod10Algorithm.h"
#include <iostream>

/* https://en.wikipedia.org/wiki/Luhn_algorithm

0 ->  0 -> 0
1 ->  2 -> 2
2 ->  4 -> 4
3 ->  6 -> 6
4 ->  8 -> 8
5 -> 10 -> 1
6 -> 12 -> 3
7 -> 14 -> 5
8 -> 16 -> 7
9 -> 18 -> 9 */

int main()
{
    std::cout << (isValidCreditCard("2111111111121111") == false);
    std::cout << (isValidCreditCard("4111111111111111") == true);
    std::cout << (isValidCreditCard("5500000000000004") == true);
    std::cout << (isValidCreditCard("378282246310005") == true);
    std::cout << (isValidCreditCard("7777777777777777") == false);
    std::cout << (isValidCreditCard("6011000000000004") == true);
    std::cout << (isValidCreditCard("6451623895684318") == false);
    std::cout << std::endl;
    return 0;
}
