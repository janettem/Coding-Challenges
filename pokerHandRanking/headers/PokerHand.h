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

    PokerHand(Card aHand[5]);
    void setHand(Card aHand[5]);
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
    bool isTwoPair();
    bool isPair();
    bool isNOfAKind(int n);
    Card::Rank getNOfAKindRank(int n, Card::Rank rankToAvoid);
    int countKinds(Card card);
    bool isInSequence();
    bool isSameSuit();
    Card::Rank getLowestValue();
    bool hasRank(Card::Rank rank);
};

#endif
