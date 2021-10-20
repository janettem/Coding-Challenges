#ifndef POKER_HAND
#define POKER_HAND

#include "Card.h"
#include <string>

class PokerHand
{
public:
    enum Combination
    {
        HighCard,
        Pair,
        TwoPairs,
        ThreeOfAKind,
        Straight,
        Flush,
        FullHouse,
        FourOfAKind,
        StraightFlush,
        RoyalFlush
    };

    PokerHand(Card card1, Card card2, Card card3, Card card4, Card card5);
    Combination getCombination();

private:
    Card hand[5];

    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPairs();
    bool isPair();
    bool hasRank(Card::Rank rank);
    bool isSameSuit();
    bool isInSequence();
    bool hasNOfAKind(int n);
    bool hasTwoPairs();
    Card::Rank getLowestRank();
    int countRanks(Card::Rank rank);
};

#endif
