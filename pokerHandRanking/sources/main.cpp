#include "PokerHand.h"
#include <iostream>

bool testRoyalFlush();
bool testStraightFlush();
bool testFourOfAKind();
bool testFullHouse();
bool testFlush();
bool testStraight();
bool testThreeOfAKind();
bool testTwoPairs();
bool testPair();
bool testHighCard();

int main()
{
    std::cout << testRoyalFlush();
    std::cout << testStraightFlush();
    std::cout << testFourOfAKind();
    std::cout << testFullHouse();
    std::cout << testFlush();
    std::cout << testStraight();
    std::cout << testThreeOfAKind();
    std::cout << testTwoPairs();
    std::cout << testPair();
    std::cout << testHighCard();
    std::cout << std::endl;
    return 0;
}

bool testRoyalFlush()
{
    PokerHand hand({Card::Ten, Card::Hearts},
                   {Card::Jack, Card::Hearts},
                   {Card::Queen, Card::Hearts},
                   {Card::Ace, Card::Hearts},
                   {Card::King, Card::Hearts});
    if (hand.getCombination() == PokerHand::RoyalFlush)
        return true;
    return false;
}

bool testStraightFlush()
{
    PokerHand hand({Card::Jack, Card::Hearts},
                   {Card::Ten, Card::Hearts},
                   {Card::Nine, Card::Hearts},
                   {Card::King, Card::Hearts},
                   {Card::Queen, Card::Hearts});
    if (hand.getCombination() == PokerHand::StraightFlush)
        return true;
    return false;
}

bool testFourOfAKind()
{
    PokerHand hand({Card::Ten, Card::Spades},
                   {Card::Ten, Card::Clubs},
                   {Card::Eight, Card::Diamonds},
                   {Card::Ten, Card::Diamonds},
                   {Card::Ten, Card::Hearts});
    if (hand.getCombination() == PokerHand::FourOfAKind)
        return true;
    return false;
}

bool testFullHouse()
{
    PokerHand hand({Card::Nine, Card::Hearts},
                   {Card::Eight, Card::Hearts},
                   {Card::Nine, Card::Spades},
                   {Card::Eight, Card::Spades},
                   {Card::Eight, Card::Diamonds});
    if (hand.getCombination() == PokerHand::FullHouse)
        return true;
    return false;
}

bool testFlush()
{
    PokerHand hand({Card::Eight, Card::Diamonds},
                   {Card::Seven, Card::Diamonds},
                   {Card::Six, Card::Diamonds},
                   {Card::Jack, Card::Diamonds},
                   {Card::Nine, Card::Diamonds});
    if (hand.getCombination() == PokerHand::Flush)
        return true;
    return false;
}

bool testStraight()
{
    PokerHand hand({Card::Eight, Card::Hearts},
                   {Card::Seven, Card::Spades},
                   {Card::Six, Card::Diamonds},
                   {Card::Ten, Card::Diamonds},
                   {Card::Nine, Card::Diamonds});
    if (hand.getCombination() == PokerHand::Straight)
        return true;
    return false;
}

bool testThreeOfAKind()
{
    PokerHand hand({Card::Ace, Card::Hearts},
                   {Card::King, Card::Hearts},
                   {Card::Queen, Card::Spades},
                   {Card::King, Card::Spades},
                   {Card::King, Card::Diamonds});
    if (hand.getCombination() == PokerHand::ThreeOfAKind)
        return true;
    return false;
}

bool testTwoPairs()
{
    PokerHand hand({Card::Nine, Card::Hearts},
                   {Card::Eight, Card::Hearts},
                   {Card::Nine, Card::Spades},
                   {Card::Ten, Card::Spades},
                   {Card::Eight, Card::Diamonds});
    if (hand.getCombination() == PokerHand::TwoPairs)
        return true;
    return false;
}

bool testPair()
{
    PokerHand hand({Card::Nine, Card::Hearts},
                   {Card::Eight, Card::Hearts},
                   {Card::Seven, Card::Spades},
                   {Card::Ten, Card::Spades},
                   {Card::Eight, Card::Diamonds});
    if (hand.getCombination() == PokerHand::Pair)
        return true;
    return false;
}

bool testHighCard()
{
    PokerHand hand({Card::Three, Card::Hearts},
                   {Card::Five, Card::Hearts},
                   {Card::Queen, Card::Spades},
                   {Card::Nine, Card::Hearts},
                   {Card::Ace, Card::Diamonds});
    if (hand.getCombination() == PokerHand::HighCard)
        return true;
    return false;
}
