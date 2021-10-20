#include "tapCodeTranslation.h"

std::string TapCode::tapCode(std::string code)
{
    return encode(code);
}

std::string TapCode::encode(std::string str)
{
    std::string code = getPosition(str[0]);
    for (int i = 1; i < str.length(); i++)
        code = code + " " + getPosition(str[i]);
    return code;
}

std::string TapCode::getPosition(char letter)
{
    for (int column = 0; column < 5; column++)
    {
        for (int row = 0; row < 5; row++)
        {
            if (letters[column][row] == letter ||
                (letter == 'k' && letters[column][row] == 'c'))
                return getTaps(column + 1) + " " + getTaps(row + 1);
        }
    }
    return "";
}

std::string TapCode::getTaps(int amount)
{
    std::string taps(amount, '.');
    return taps;
}
