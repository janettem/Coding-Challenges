// https://edabit.com/challenge/EZKbj4mM3xEfDpb5c

#include <string>
#include <iostream>

#define ACE "A"
#define KING "K"
#define QUEEN "Q"
#define JACK "J"
#define TEN "10"
#define NINE "9"
#define EIGHT "8"
#define SEVEN "7"
#define SIX "6"
#define FIVE "5"
#define FOUR "4"
#define THREE "3"
#define TWO "2"
#define NONE ""

#define ROYAL_FLUSH "Royal Flush"
#define STRAIGHT_FLUSH "Straight Flush"
#define FOUR_OF_A_KIND "Four of a Kind"
#define FULL_HOUSE "Full House"
#define FLUSH "Flush"
#define STRAIGHT "Straight"
#define THREE_OF_A_KIND "Three of a Kind"
#define TWO_PAIR "Two Pair"
#define PAIR "Pair"
#define HIGH_CARD "High Card"

class PokerHand
{
public:
    PokerHand(std::string card1,
              std::string card2,
              std::string card3,
              std::string card4,
              std::string card5);
    std::string getRanking();

private:
    std::string hand[5];

    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPair();
    bool isPair();
    bool isNOfAKind(int n);
    std::string getNOfAKindRank(int n, std::string rankToAvoid);
    int countKinds(std::string card);
    bool isInSequence();
    bool isSameSuit();
    int getLowestValue();
    int getHighestValue();
    bool hasValue(int value);
    int getValue(std::string card);
    bool hasRank(std::string rank);
    std::string getRank(std::string card);
    char getSuit(std::string card);
};

int main()
{
    PokerHand royalFlush("10h", "Jh", "Qh", "Ah", "Kh");
    PokerHand straightFlush("8s", "7s", "6s", "10s", "9s");
    PokerHand fourOfAKind("10s", "10c", "8d", "10d", "10h");
    PokerHand fullHouse("9h", "8h", "9s", "8s", "8d");
    PokerHand flush("8d", "7d", "6d", "Jd", "9d");
    PokerHand straight("8h", "7s", "6d", "10d", "9d");
    PokerHand threeOfAKind("9h", "8h", "7s", "8s", "8d");
    PokerHand twoPair("9h", "8h", "9s", "10s", "8d");
    PokerHand pair("9h", "8h", "7s", "10s", "8d");
    PokerHand highCard("3h", "5h", "Qs", "9h", "Ad");

    std::cout << (royalFlush.getRanking() == ROYAL_FLUSH);
    std::cout << (straightFlush.getRanking() == STRAIGHT_FLUSH);
    std::cout << (fourOfAKind.getRanking() == FOUR_OF_A_KIND);
    std::cout << (fullHouse.getRanking() == FULL_HOUSE);
    std::cout << (flush.getRanking() == FLUSH);
    std::cout << (straight.getRanking() == STRAIGHT);
    std::cout << (threeOfAKind.getRanking() == THREE_OF_A_KIND);
    std::cout << (twoPair.getRanking() == TWO_PAIR);
    std::cout << (pair.getRanking() == PAIR);
    std::cout << (highCard.getRanking() == HIGH_CARD);

    std::cout << std::endl;

    return 0;
}

PokerHand::PokerHand(std::string card1,
                     std::string card2,
                     std::string card3,
                     std::string card4,
                     std::string card5)
{
    hand[0] = card1;
    hand[1] = card2;
    hand[2] = card3;
    hand[3] = card4;
    hand[4] = card5;
}

std::string PokerHand::getRanking()
{
    if (isRoyalFlush())
        return ROYAL_FLUSH;
    else if (isStraightFlush())
        return STRAIGHT_FLUSH;
    else if (isFourOfAKind())
        return FOUR_OF_A_KIND;
    else if (isFullHouse())
        return FULL_HOUSE;
    else if (isFlush())
        return FLUSH;
    else if (isStraight())
        return STRAIGHT;
    else if (isThreeOfAKind())
        return THREE_OF_A_KIND;
    else if (isTwoPair())
        return TWO_PAIR;
    else if (isPair())
        return PAIR;
    return HIGH_CARD;
}

bool PokerHand::isRoyalFlush()
{
    if (isSameSuit() &&
        hasRank(ACE) &&
        hasRank(KING) &&
        hasRank(QUEEN) &&
        hasRank(JACK) &&
        hasRank(TEN))
        return true;
    return false;
}

bool PokerHand::isStraightFlush()
{
    if (isSameSuit() &&
        isInSequence())
        return true;
    return false;
}

bool PokerHand::isFourOfAKind()
{
    if (isNOfAKind(4))
        return true;
    return false;
}

bool PokerHand::isFullHouse()
{
    if (isNOfAKind(3) &&
        isNOfAKind(2))
        return true;
    return false;
}

bool PokerHand::isFlush()
{
    if (isSameSuit() &&
        !isInSequence())
        return true;
    return false;
}

bool PokerHand::isStraight()
{
    if (isInSequence() &&
        !isSameSuit())
        return true;
    return false;
}

bool PokerHand::isThreeOfAKind()
{
    if (isNOfAKind(3) &&
        !isNOfAKind(2))
        return true;
    return false;
}

bool PokerHand::isTwoPair()
{
    std::string rank = getNOfAKindRank(2, NONE);
    if (rank != NONE &&
        getNOfAKindRank(2, rank) != NONE)
        return true;
    return false;
}

bool PokerHand::isPair()
{
    if (isNOfAKind(2) &&
        !isNOfAKind(3) &&
        !isTwoPair())
        return true;
    return false;
}

bool PokerHand::isNOfAKind(int n)
{
    for (int i = 0; i < 5; i++)
    {
        if (countKinds(hand[i]) == n)
            return true;
    }
    return false;
}

std::string PokerHand::getNOfAKindRank(int n, std::string rankToAvoid)
{
    std::string rank;
    for (int i = 0; i < 5; i++)
    {
        rank = getRank(hand[i]);
        if (rank != rankToAvoid &&
            countKinds(hand[i]) == n)
            return rank;
    }
    return NONE;
}

int PokerHand::countKinds(std::string card)
{
    int kinds = 0;
    std::string rank = getRank(card);
    for (int i = 0; i < 5; i++)
    {
        if (getRank(hand[i]) == rank)
            kinds++;
    }
    return kinds;
}

bool PokerHand::isInSequence()
{
    int lowestValue = getLowestValue();
    for (int value = lowestValue + 1; value <= lowestValue + 4; value++)
    {
        if (!hasValue(value))
            return false;
    }
    return true;
}

bool PokerHand::isSameSuit()
{
    char suit = getSuit(hand[0]);
    for (int i = 0; i < 5; i++)
    {
        if (getSuit(hand[i]) != suit)
            return false;
    }
    return true;
}

int PokerHand::getLowestValue()
{
    int lowestValue = getValue(hand[0]);
    int value;
    for (int i = 1; i < 5; i++)
    {
        value = getValue(hand[i]);
        if (value < lowestValue)
            lowestValue = value;
    }
    return lowestValue;
}

int PokerHand::getHighestValue()
{
    int highestValue = getValue(hand[0]);
    int value;
    for (int i = 1; i < 5; i++)
    {
        value = getValue(hand[i]);
        if (value > highestValue)
            highestValue = value;
    }
    return highestValue;
}

bool PokerHand::hasValue(int value)
{
    for (int i = 0; i < 5; i++)
    {
        if (getValue(hand[i]) == value)
            return true;
    }
    return false;
}

int PokerHand::getValue(std::string card)
{
    std::string rank = getRank(card);
    if (rank == ACE)
        return 14;
    else if (rank == KING)
        return 13;
    else if (rank == QUEEN)
        return 12;
    else if (rank == JACK)
        return 11;
    else if (rank == TEN)
        return 10;
    else if (rank == NINE)
        return 9;
    else if (rank == EIGHT)
        return 8;
    else if (rank == SEVEN)
        return 7;
    else if (rank == SIX)
        return 6;
    else if (rank == FIVE)
        return 5;
    else if (rank == FOUR)
        return 4;
    else if (rank == THREE)
        return 3;
    return 2;
}

bool PokerHand::hasRank(std::string rank)
{
    for (int i = 0; i < 5; i++)
    {
        if (getRank(hand[i]) == rank)
            return true;
    }
    return false;
}

std::string PokerHand::getRank(std::string card)
{
    return card.substr(0, card.length() - 1);
}

char PokerHand::getSuit(std::string card)
{
    return card[card.length() - 1];
}
