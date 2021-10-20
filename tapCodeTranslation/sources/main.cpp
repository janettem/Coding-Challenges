#include "tapCodeTranslation.h"
#include <iostream>

int main()
{
    TapCode tapCode;
    std::cout << (tapCode.tapCode("break") == ". .. .... .. . ..... . . . ...");
    // std::cout << (tapCode.tapCode(".... ... ... ..... . ..... ... ... .... ....") == "spent");
    std::cout << std::endl;
    return 0;
}
