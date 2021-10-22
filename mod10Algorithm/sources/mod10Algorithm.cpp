#include "mod10Algorithm.h"

std::string getOriginalNumber(std::string number)
{
    return number.substr(0, number.length() - 1);
}

int charToInt(char c)
{
    return c - '0';
}

std::string doubleDigit(char digit)
{
    return std::to_string(charToInt(digit) * 2);
}

std::string *doubleEveryOtherDigit(std::string number)
{
    std::string *everyOtherDigitDoubled = new std::string[number.length()];
    bool everyOtherDigit = true;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        if (everyOtherDigit)
            everyOtherDigitDoubled[i] = doubleDigit(number[i]);
        else
            everyOtherDigitDoubled[i] = number[i];
        everyOtherDigit = !everyOtherDigit;
    }
    return everyOtherDigitDoubled;
}

char sumDigits2(std::string number)
{
    if (number.length() == 2)
        return std::to_string(charToInt(number[0]) + charToInt(number[1]))[0];
    return number[0];
}

std::string sumDigits(std::string *number, int size)
{
    std::string digitsSummed;
    for (int i = 0; i < size; i++)
        digitsSummed += sumDigits2(number[i]);
    return digitsSummed;
}

int sumDigits3(std::string number)
{
    int sum = 0;
    for (int i = 0; i < number.length(); i++)
        sum += charToInt(number[i]);
    return sum;
}

char calculateCheckDigit(int sum)
{
    return std::to_string(10 - sum % 10)[0];
}

bool isValidCreditCard(std::string number)
{
    std::string originalNumber, *everyOtherDigitDoubled, digitsSummed;
    int sum, calculatedCheckDigit;
    originalNumber = getOriginalNumber(number);
    everyOtherDigitDoubled = doubleEveryOtherDigit(originalNumber);
    digitsSummed = sumDigits(everyOtherDigitDoubled, originalNumber.length());
    sum = sumDigits3(digitsSummed);
    calculatedCheckDigit = calculateCheckDigit(sum);
    delete[] everyOtherDigitDoubled;
    return calculatedCheckDigit == number[number.length() - 1];
}
