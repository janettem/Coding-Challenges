#include "tapCodeTranslation.h"

static const char letters[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                                   {'f', 'g', 'h', 'i', 'j'},
                                   {'l', 'm', 'n', 'o', 'p'},
                                   {'q', 'r', 's', 't', 'u'},
                                   {'v', 'w', 'x', 'y', 'z'}};

static bool isCode(std::string str);
static std::string decode(std::string code);
static std::string encode(std::string message);
static char getNextLetter(std::string code);
static std::string split(std::string str, std::string delimiter, int position);
static std::string getPosition(char letter);
static std::string getTaps(int amount);

std::string tapCode(std::string str)
{
    if (isCode(str))
        return decode(str);
    return encode(str);
}

static bool isCode(std::string str)
{
    if (str[0] == '.')
        return true;
    return false;
}

static std::string decode(std::string code)
{
    std::string message = "";
    char letter;
    while ((letter = getNextLetter(code)))
        message += letter;
    return message;
}

static std::string encode(std::string message)
{
    std::string code = getPosition(message[0]);
    for (int i = 1; i < message.length(); i++)
        code = code + " " + getPosition(message[i]);
    return code;
}

static char getNextLetter(std::string code)
{
    int row, column;
    static int start = 0;
    if (start < code.length())
    {
        row = split(code, " ", start).length();
        start += row + 1;
        column = split(code, " ", start).length();
        start += column + 1;
        return letters[row - 1][column - 1];
    }
    start = 0;
    return 0;
}

static std::string split(std::string str, std::string delimiter, int start)
{
    int end = str.find(delimiter, start);
    if (end != std::string::npos)
        return str.substr(start, end - start);
    return str.substr(start);
}

static std::string getPosition(char letter)
{
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            if (letters[row][column] == letter ||
                (letter == 'k' && letters[row][column] == 'c'))
                return getTaps(row + 1) + " " + getTaps(column + 1);
        }
    }
    return "";
}

static std::string getTaps(int amount)
{
    std::string taps(amount, '.');
    return taps;
}
