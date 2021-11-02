#include "mod10Algorithm.h"

static std::string getOriginalNumber(std::string number);
static char calculateCheckDigit(std::string number);
static std::vector<std::string> doubleEveryOtherDigit(std::string originalNumber);
static std::string doubleDigit(char digit);
static std::string sumDoubledDigits(std::vector<std::string> doubledDigits);
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
    std::vector<std::string> doubledDigits = doubleEveryOtherDigit(originalNumber);
    std::string summedDigits = sumDoubledDigits(doubledDigits);
    int sum = sumDigits(summedDigits);
    return calculate(sum);
}

static std::vector<std::string> doubleEveryOtherDigit(std::string originalNumber)
{
    std::vector<std::string> doubledDigits;
    bool otherDigit = true;
    for (int i = originalNumber.length() - 1; i >= 0; i--)
    {
        if (otherDigit)
            doubledDigits.insert(doubledDigits.begin(), doubleDigit(originalNumber[i]));
        else
            doubledDigits.insert(doubledDigits.begin(), std::string(1, originalNumber[i]));
        otherDigit = !otherDigit;
    }
    return doubledDigits;
}

static std::string doubleDigit(char digit)
{
    return std::to_string(charToInt(digit) * 2);
}

static std::string sumDoubledDigits(std::vector<std::string> doubledDigits)
{
    std::string summedDigits;
    for (int i = 0; i < doubledDigits.size(); i++)
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
