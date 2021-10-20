#ifndef TAP_CODE_TRANSLATION
#define TAP_CODE_TRANSLATION

#include <string>

class TapCode
{
public:
    std::string tapCode(std::string code);

private:
    char letters[5][5] = {{'a', 'b', 'c', 'd', 'e'},
                          {'f', 'g', 'h', 'i', 'j'},
                          {'l', 'm', 'n', 'o', 'p'},
                          {'q', 'r', 's', 't', 'u'},
                          {'v', 'w', 'x', 'y', 'z'}};

    std::string encode(std::string str);
    std::string getPosition(char letter);
    std::string getTaps(int amount);
};

#endif
