#include "hiddenAnagram.h"

static std::string getLettersInLower(std::string str);
static bool isAnagram(std::string anagram, std::string phrase);

std::string getHiddenAnagram(std::string text, std::string phrase)
{
    std::string anagram;
    text = getLettersInLower(text);
    phrase = getLettersInLower(phrase);
    for (int i = 0; i < text.length(); i++)
    {
        anagram = text.substr(i, phrase.length());
        if (isAnagram(anagram, phrase))
            return anagram;
    }
    return "not found";
}

static std::string getLettersInLower(std::string str)
{
    std::string lettersInLower = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
            lettersInLower += tolower(str[i]);
    }
    return lettersInLower;
}

static bool isAnagram(std::string anagram, std::string phrase)
{
    int position;
    for (int i = 0;
         i < anagram.length() &&
         (position = phrase.find(anagram[i])) != std::string::npos;
         i++)
        phrase = phrase.substr(0, position) + phrase.substr(position + 1);
    return phrase.length() == 0;
}
