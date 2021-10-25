#include "mod10Algorithm.h"
#include <iostream>

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
