#include "mod10Algorithm.h"

static std::string getOriginalNumber(std::string number);
static char calculateCheckDigit(std::string number);
static std::string *doubleEveryOtherDigit(std::string number);
static std::string doubleDigit(char digit);
static std::string sumDoubledDigits(std::string *number, int size);
static int sumDigits(std::string number);
static int charToInt(char c);
static char calculate(int sum);
static char getCheckDigit(std::string number);

bool isValidCreditCard(std::string number)
{
    std::string originalNumber = getOriginalNumber(number);
    return calculateCheckDigit(originalNumber) == getCheckDigit(number);
}

static std::string getOriginalNumber(std::string number)
{
    return number.substr(0, number.length() - 1);
}

static char calculateCheckDigit(std::string originalNumber)
{
    std::string *doubledDigits = doubleEveryOtherDigit(originalNumber);
    std::string summedDigits = sumDoubledDigits(doubledDigits, originalNumber.length());
    int sum = sumDigits(summedDigits);
    delete[] doubledDigits;
    return calculate(sum);
}

static std::string *doubleEveryOtherDigit(std::string originalNumber)
{
    int size = originalNumber.length();
    std::string *doubledDigits = new std::string[size];
    bool otherDigit = true;
    for (int i = size - 1; i >= 0; i--)
    {
        if (otherDigit)
            doubledDigits[i] = doubleDigit(originalNumber[i]);
        else
            doubledDigits[i] = originalNumber[i];
        otherDigit = !otherDigit;
    }
    return doubledDigits;
}

static std::string doubleDigit(char digit)
{
    return std::to_string(charToInt(digit) * 2);
}

static std::string sumDoubledDigits(std::string *doubledDigits, int size)
{
    std::string summedDigits;
    for (int i = 0; i < size; i++)
        summedDigits += std::to_string(sumDigits(doubledDigits[i]));
    return summedDigits;
}

static int sumDigits(std::string number)
{
    int sum = 0;
    for (int i = number.length() - 1; i >= 0; i--)
        sum += charToInt(number[i]);
    return sum;
}

static int charToInt(char c)
{
    return c - '0';
}

static char calculate(int sum)
{
    return std::to_string(10 - sum % 10)[0];
}

static char getCheckDigit(std::string number)
{
    return number[number.length() - 1];
}
