#include "PokerHand.h"
#include <iostream>

int main()
{
    Card royalFlush[5] = {{Card::Ten, Card::Hearts},
                          {Card::Jack, Card::Hearts},
                          {Card::Queen, Card::Hearts},
                          {Card::Ace, Card::Hearts},
                          {Card::King, Card::Hearts}};

    Card straightFlush[5] = {{Card::Jack, Card::Hearts},
                             {Card::Ten, Card::Hearts},
                             {Card::Nine, Card::Hearts},
                             {Card::King, Card::Hearts},
                             {Card::Queen, Card::Hearts}};

    Card fourOfAKind[5] = {{Card::Ace, Card::Hearts},
                           {Card::Ace, Card::Spades},
                           {Card::King, Card::Hearts},
                           {Card::Ace, Card::Diamonds},
                           {Card::Ace, Card::Clubs}};

    Card fullHouse[5] = {{Card::Nine, Card::Hearts},
                         {Card::Eight, Card::Hearts},
                         {Card::Nine, Card::Spades},
                         {Card::Eight, Card::Spades},
                         {Card::Eight, Card::Diamonds}};

    Card flush[5] = {{Card::Eight, Card::Diamonds},
                     {Card::Seven, Card::Diamonds},
                     {Card::Six, Card::Diamonds},
                     {Card::Jack, Card::Diamonds},
                     {Card::Nine, Card::Diamonds}};

    Card straight[5] = {{Card::Eight, Card::Hearts},
                        {Card::Seven, Card::Spades},
                        {Card::Six, Card::Diamonds},
                        {Card::Ten, Card::Diamonds},
                        {Card::Nine, Card::Diamonds}};

    Card threeOfAKind[5] = {{Card::Nine, Card::Hearts},
                            {Card::Eight, Card::Hearts},
                            {Card::Seven, Card::Spades},
                            {Card::Eight, Card::Spades},
                            {Card::Eight, Card::Diamonds}};

    Card twoPairs[5] = {{Card::Nine, Card::Hearts},
                        {Card::Eight, Card::Hearts},
                        {Card::Nine, Card::Spades},
                        {Card::Ten, Card::Spades},
                        {Card::Eight, Card::Diamonds}};

    Card pair[5] = {{Card::Nine, Card::Hearts},
                    {Card::Eight, Card::Hearts},
                    {Card::Seven, Card::Spades},
                    {Card::Ten, Card::Spades},
                    {Card::Eight, Card::Diamonds}};

    Card highCard[5] = {{Card::Three, Card::Hearts},
                        {Card::Five, Card::Hearts},
                        {Card::Queen, Card::Spades},
                        {Card::Nine, Card::Hearts},
                        {Card::Ace, Card::Diamonds}};

    PokerHand hand(royalFlush);
    std::cout << (hand.getCombination() == PokerHand::RoyalFlush);
    hand.setHand(straightFlush);
    std::cout << (hand.getCombination() == PokerHand::StraightFlush);
    hand.setHand(fourOfAKind);
    std::cout << (hand.getCombination() == PokerHand::FourOfAKind);
    hand.setHand(fullHouse);
    std::cout << (hand.getCombination() == PokerHand::FullHouse);
    hand.setHand(flush);
    std::cout << (hand.getCombination() == PokerHand::Flush);
    hand.setHand(straight);
    std::cout << (hand.getCombination() == PokerHand::Straight);
    hand.setHand(threeOfAKind);
    std::cout << (hand.getCombination() == PokerHand::ThreeOfAKind);
    hand.setHand(twoPairs);
    std::cout << (hand.getCombination() == PokerHand::TwoPairs);
    hand.setHand(pair);
    std::cout << (hand.getCombination() == PokerHand::Pair);
    hand.setHand(highCard);
    std::cout << (hand.getCombination() == PokerHand::HighCard);

    std::cout << std::endl;

    return 0;
}
