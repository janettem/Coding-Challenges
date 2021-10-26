#include "readTheAbacus.h"
#include <iostream>

int main()
{
    std::cout << (getSorobanValue({"|O|O|O|",
                                   "O|O|O|O",
                                   "-------",
                                   "||O|OO|",
                                   "OOOO||O",
                                   "OO|OOOO",
                                   "OOOOOOO",
                                   "OOOOOOO"}) == 5070615);

    std::cout << (getSorobanValue({"OOO||OO",
                                   "|||OO||",
                                   "-------",
                                   "OOOOO||",
                                   "OOO||OO",
                                   "OO|OOOO",
                                   "OOOOOOO",
                                   "||OOOOO"}) == 4426600);

    std::cout << (getSorobanValue({"|O|O|OO",
                                   "O|O|O||",
                                   "-------",
                                   "OO||||O",
                                   "O|OOOOO",
                                   "|OOOOOO",
                                   "OOOOOO|",
                                   "OOOOOOO"}) == 7150503);

    std::cout << (getSorobanValue({"|OOO|OO",
                                   "O|||O||",
                                   "-------",
                                   "|||OO|O",
                                   "OOOO|OO",
                                   "OOO|OOO",
                                   "OOOOOOO",
                                   "OOOOOO|"}) == 5002604);

    std::cout << (getSorobanValue({"O|OOO|O",
                                   "|O|||O|",
                                   "-------",
                                   "OOO|OO|",
                                   "|OOOOOO",
                                   "OO|OOOO",
                                   "O|OOO|O",
                                   "OOOO|OO"}) == 1820480);

    std::cout << (getSorobanValue({"OOO|OO|",
                                   "|||O||O",
                                   "-------",
                                   "OOOOO|O",
                                   "|OOO|O|",
                                   "OO|OOOO",
                                   "OOO|OOO",
                                   "O|OOOOO"}) == 1428106);

    std::cout << (getSorobanValue({"OOOOOOO",
                                   "|||||||",
                                   "-------",
                                   "||OO|OO",
                                   "OO|OO|O",
                                   "OOOOOOO",
                                   "OOO|OOO",
                                   "OOOOOO|"}) == 13014);

    std::cout << (getSorobanValue({"|OOO|||",
                                   "O|||OOO",
                                   "-------",
                                   "O||OOOO",
                                   "OOOOOOO",
                                   "OOOOO|O",
                                   "|OO||O|",
                                   "OOOOOOO"}) == 8003878);

    std::cout << (getSorobanValue({"O|OOOOO",
                                   "|O|||||",
                                   "-------",
                                   "||OO|||",
                                   "OOOOOOO",
                                   "OOOOOOO",
                                   "OO|OOOO",
                                   "OOO|OOO"}) == 534000);

    std::cout << (getSorobanValue({"OOOO|||",
                                   "||||OOO",
                                   "-------",
                                   "|OO||OO",
                                   "OOOOOOO",
                                   "OOOOOO|",
                                   "OO|OO|O",
                                   "O|OOOOO"}) == 430587);

    std::cout << (getSorobanValue({"OOO|||O",
                                   "|||OOO|",
                                   "-------",
                                   "||OOOO|",
                                   "OOOOOOO",
                                   "OOOOO|O",
                                   "OO|OOOO",
                                   "OOO||OO"}) == 39970);

    std::cout << (getSorobanValue({"O||OO||",
                                   "|OO||OO",
                                   "-------",
                                   "OO|OOO|",
                                   "O|OOOOO",
                                   "OOOOOOO",
                                   "OOOO|OO",
                                   "|OO|O|O"}) == 4654395);

    std::cout << (getSorobanValue({"OOO|OO|",
                                   "|||O||O",
                                   "-------",
                                   "|||OO||",
                                   "OOOOOOO",
                                   "OOO|OOO",
                                   "OOOOOOO",
                                   "OOOO|OO"}) == 7405);

    std::cout << (getSorobanValue({"|O|OOOO",
                                   "O|O||||",
                                   "-------",
                                   "OO|OO|O",
                                   "|OOOOOO",
                                   "OOO||OO",
                                   "OOOOOOO",
                                   "O|OOOO|"}) == 6452204);

    std::cout << (getSorobanValue({"O|OO|O|",
                                   "|O||O|O",
                                   "-------",
                                   "OOOOO|O",
                                   "OOOOOO|",
                                   "||O||OO",
                                   "OOOOOOO",
                                   "OO|OOOO"}) == 2742706);

    std::cout << (getSorobanValue({"OO|OOOO",
                                   "||O||||",
                                   "-------",
                                   "OO|O|||",
                                   "OOOOOOO",
                                   "O|OOOOO",
                                   "OOOOOOO",
                                   "|OO|OOO"}) == 4254000);

    std::cout << (getSorobanValue({"|OOOOO|",
                                   "O|||||O",
                                   "-------",
                                   "OOOOO|O",
                                   "O|OOOO|",
                                   "|OOOOOO",
                                   "OOOO|OO",
                                   "OO||OOO"}) == 7144306);

    std::cout << (getSorobanValue({"OO|OO||",
                                   "||O||OO",
                                   "-------",
                                   "O|||O|O",
                                   "OOOOOOO",
                                   "|OOOOOO",
                                   "OOOO|O|",
                                   "OOOOOOO"}) == 2050358);

    std::cout << (getSorobanValue({"||O|OOO",
                                   "OO|O|||",
                                   "-------",
                                   "O||||OO",
                                   "|OOOOOO",
                                   "OOOOOO|",
                                   "OOOOO|O",
                                   "OOOOOOO"}) == 6505032);

    std::cout << (getSorobanValue({"|OOOO|O",
                                   "O||||O|",
                                   "-------",
                                   "|O||OO|",
                                   "OOOOOOO",
                                   "O|OOOOO",
                                   "OOOOOOO",
                                   "OOOO||O"}) == 5200490);

    std::cout << std::endl;

    return 0;
}
