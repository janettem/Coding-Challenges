#include "mod10Algorithm.h"
#include <iostream>

int main()
{
    std::cout << (validCreditCard("2111111111121111") == false);
    std::cout << (validCreditCard("4111111111111111") == true);
    std::cout << (validCreditCard("5500000000000004") == true);
    std::cout << (validCreditCard("378282246310005") == true);
    std::cout << (validCreditCard("7777777777777777") == false);
    std::cout << (validCreditCard("6011000000000004") == true);
    std::cout << (validCreditCard("6451623895684318") == false);
    std::cout << std::endl;
    return 0;
}
