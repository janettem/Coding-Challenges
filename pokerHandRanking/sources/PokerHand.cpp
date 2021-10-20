#include "PokerHand.h"

PokerHand::PokerHand(Card card1, Card card2, Card card3, Card card4, Card card5)
{
    hand[0] = card1;
    hand[1] = card2;
    hand[2] = card3;
    hand[3] = card4;
    hand[4] = card5;
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
    else if (isTwoPairs())
        return TwoPairs;
    else if (isPair())
        return Pair;
    return HighCard;
}

bool PokerHand::isRoyalFlush()
{
    if (hasRank(Card::Ace) &&
        hasRank(Card::King) &&
        hasRank(Card::Queen) &&
        hasRank(Card::Jack) &&
        hasRank(Card::Ten) &&
        isSameSuit())
        return true;
    return false;
}

bool PokerHand::isStraightFlush()
{
    if (isInSequence() &&
        isSameSuit() &&
        !isRoyalFlush())
        return true;
    return false;
}

bool PokerHand::isFourOfAKind()
{
    if (hasNOfAKind(4))
        return true;
    return false;
}

bool PokerHand::isFullHouse()
{
    if (hasNOfAKind(3) &&
        hasNOfAKind(2))
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
    if (hasNOfAKind(3) &&
        !isFullHouse())
        return true;
    return false;
}

bool PokerHand::isTwoPairs()
{
    if (hasTwoPairs())
        return true;
    return false;
}

bool PokerHand::isPair()
{
    if (hasNOfAKind(2) &&
        !isFullHouse() &&
        !hasTwoPairs())
        return true;
    return false;
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

bool PokerHand::isSameSuit()
{
    Card::Suit suit = hand[0].suit;
    for (int i = 1; i < 5; i++)
    {
        if (hand[i].suit != suit)
            return false;
    }
    return true;
}

bool PokerHand::isInSequence()
{
    int lowestRank = (int)getLowestRank();
    for (int rank = lowestRank + 1; rank <= lowestRank + 4; rank++)
    {
        if (!hasRank((Card::Rank)rank))
            return false;
    }
    return true;
}

bool PokerHand::hasNOfAKind(int n)
{
    for (int i = 0; i < 5; i++)
    {
        if (countRanks(hand[i].rank) == n)
            return true;
    }
    return false;
}

bool PokerHand::hasTwoPairs()
{
    Card::Rank rank = (Card::Rank)0;
    for (int i = 0; i < 5; i++)
    {
        if (hand[i].rank != rank &&
            countRanks(hand[i].rank) == 2)
        {
            if (!rank)
                rank = hand[i].rank;
            else
                return true;
        }
    }
    return false;
}

Card::Rank PokerHand::getLowestRank()
{
    Card::Rank lowestRank = hand[0].rank;
    Card::Rank rank;
    for (int i = 1; i < 5; i++)
    {
        rank = hand[i].rank;
        if (rank < lowestRank)
            lowestRank = rank;
    }
    return lowestRank;
}

int PokerHand::countRanks(Card::Rank rank)
{
    int ranks = 0;
    for (int i = 0; i < 5; i++)
    {
        if (hand[i].rank == rank)
            ranks++;
    }
    return ranks;
}
