#include "PokerHand.h"

PokerHand::PokerHand(Card aHand[5])
{
    setHand(aHand);
}

void PokerHand::setHand(Card aHand[5])
{
    hand[0] = aHand[0];
    hand[1] = aHand[1];
    hand[2] = aHand[2];
    hand[3] = aHand[3];
    hand[4] = aHand[4];
}

PokerHand::Combination PokerHand::getCombination()
{
    if (isRoyalFlush())
        return RoyalFlush;
    else if (isStraightFlush())
        return StraightFlush;
    else if (isFourOfAKind())
        return FourOfAKind;
    else if (isFullHouse())
        return FullHouse;
    else if (isFlush())
        return Flush;
    else if (isStraight())
        return Straight;
    else if (isThreeOfAKind())
        return ThreeOfAKind;
    else if (isTwoPair())
        return TwoPairs;
    else if (isPair())
        return Pair;
    return HighCard;
}

bool PokerHand::isRoyalFlush()
{
    if (isSameSuit() &&
        hasRank(Card::Ace) &&
        hasRank(Card::King) &&
        hasRank(Card::Queen) &&
        hasRank(Card::Jack) &&
        hasRank(Card::Ten))
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
    Card::Rank rank = getNOfAKindRank(2, Card::None);
    if (rank != Card::None &&
        getNOfAKindRank(2, rank) != Card::None)
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

Card::Rank PokerHand::getNOfAKindRank(int n, Card::Rank rankToAvoid)
{
    Card::Rank rank;
    for (int i = 0; i < 5; i++)
    {
        rank = hand[i].rank;
        if (rank != rankToAvoid &&
            countKinds(hand[i]) == n)
            return rank;
    }
    return Card::None;
}

int PokerHand::countKinds(Card card)
{
    int kinds = 0;
    Card::Rank rank = card.rank;
    for (int i = 0; i < 5; i++)
    {
        if (hand[i].rank == rank)
            kinds++;
    }
    return kinds;
}

bool PokerHand::isInSequence()
{
    int lowestValue = (int)getLowestValue();
    for (int value = lowestValue + 1; value <= lowestValue + 4; value++)
    {
        if (!hasRank((Card::Rank)value))
            return false;
    }
    return true;
}

bool PokerHand::isSameSuit()
{
    Card::Suit suit = hand[0].suit;
    for (int i = 0; i < 5; i++)
    {
        if (hand[i].suit != suit)
            return false;
    }
    return true;
}

Card::Rank PokerHand::getLowestValue()
{
    Card::Rank lowestValue = hand[0].rank;
    Card::Rank value;
    for (int i = 1; i < 5; i++)
    {
        value = hand[i].rank;
        if (value < lowestValue)
            lowestValue = value;
    }
    return lowestValue;
}

bool PokerHand::hasRank(Card::Rank rank)
{
    for (int i = 0; i < 5; i++)
    {
        if (hand[i].rank == rank)
            return true;
    }
    return false;
}
