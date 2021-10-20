#include "tapCodeTranslation.h"
#include <iostream>

int main()
{
    std::cout << tapCode("break") << std::endl;
    // -> ". .. .... .. . ..... . . . ..."

    std::cout << tapCode(".... ... ... ..... . ..... ... ... .... ....") << std::endl;
    // -> "spent"

    return 0;
}
