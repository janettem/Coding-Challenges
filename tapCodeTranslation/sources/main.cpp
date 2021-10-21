/*  1   2   3   4   5
1   a   b   c/k d   e
2   f   g   h   i   j
3   l   m   n   o   p
4   q   r   s   t   u
5   v   w   x   y   z

letter = row column
'b' = ". .."

word = letter letter...
"break" = ". .. .... .. . ..... . . . ..."

tapCode("break"); // -> ". .. .... .. . ..... . . . ..."
tapCode(". .. .... .. . ..... . . . ..."); // -> "breac" */

#include "tapCodeTranslation.h"
#include <iostream>

static bool testEncode(std::string message, std::string code);
static bool testDecode(std::string code, std::string message);

int main()
{
    std::string breakCode = ". .. .... .. . ..... . . . ...";
    std::string spentCode = ".... ... ... ..... . ..... ... ... .... ....";
    std::cout << testEncode("break", breakCode);
    std::cout << testEncode("spent", spentCode);
    std::cout << testDecode(breakCode, "breac");
    std::cout << testDecode(spentCode, "spent");
    std::cout << std::endl;
    return 0;
}

static bool testEncode(std::string message, std::string code)
{
    if (tapCode(message) == code)
        return true;
    return false;
}

static bool testDecode(std::string code, std::string message)
{
    if (tapCode(code) == message)
        return true;
    return false;
}
