#include "hiddenAnagram.h"
#include <iostream>

int main()
{
    std::cout << (getHiddenAnagram("Sir Patrick Moore was a famous moon starer", "Astronomer") == "moonstarer");
    std::cout << (getHiddenAnagram("A building, built to stay free of defects, is uncommon!", "Statue of Liberty") == "builttostayfree");
    std::cout << (getHiddenAnagram("Bright is the moon", "Bongo mirth") == "not found");
    std::cout << (getHiddenAnagram("Anchor man Bill, a well known TV personality, was confused about becoming president", "Abraham Lincoln") == "anchormanbilla");
    std::cout << (getHiddenAnagram("There seem to be more and more television ads on the box these days!", "enslave idiots") == "televisionads");
    std::cout << (getHiddenAnagram("The thing orators hate most is a throat infection", "A sore throat") == "oratorshate");
    std::cout << (getHiddenAnagram("I thought I heard a high cornet note of great beuaty", "One Cornetto") == "cornetnoteo");
    std::cout << (getHiddenAnagram("D  e b90it->?$ (c)a r...d,,#~", "bad credit") == "debitcard");
    std::cout << (getHiddenAnagram("You won't find any anagram here!", "aerogramhenna") == "not found");
    std::cout << std::endl;
    return 0;
}
