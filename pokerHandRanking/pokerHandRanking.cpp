// https://edabit.com/challenge/EZKbj4mM3xEfDpb5c

#include <string>
#include <iostream>

std::string getPokerHandRanking(std::string hand[5]);
bool isRoyalFlush(std::string hand[5]);
bool isSameSuit(std::string hand[5]);
char getSuit(std::string card);
std::string getRank(std::string card);

int main()
{
    std::string royalFlush[5] = {"10h", "Jh", "Qh", "Ah", "Kh"};
    std::string highCard[5] = {"3h", "5h", "Qs", "9h", "Ad"};

    std::cout << (getPokerHandRanking(royalFlush) == "Royal Flush");
    std::cout << (getPokerHandRanking(highCard) == "High Card");

    std::cout << std::endl;

    return 0;
}

std::string getPokerHandRanking(std::string hand[5])
{
    if (isRoyalFlush(hand))
        return "Royal Flush";
    return "High Card";
}

bool isRoyalFlush(std::string hand[5])
{
    if (isSameSuit(hand) &&
        getRank(hand[0]) == "A" &&
        getRank(hand[1]) == "K" &&
        getRank(hand[2]) == "Q" &&
        getRank(hand[3]) == "J" &&
        getRank(hand[4]) == "10")
        return true;
    return false;
}

bool isSameSuit(std::string hand[5])
{
    char suit = getSuit(hand[0]);
    if (getSuit(hand[1]) == suit &&
        getSuit(hand[2]) == suit &&
        getSuit(hand[3]) == suit &&
        getSuit(hand[4]) == suit)
        return true;
    return false;
}

char getSuit(std::string card)
{
    return card[card.length() - 1];
}

std::string getRank(std::string card)
{
    return card.substr(0, card.length() - 1);
}
