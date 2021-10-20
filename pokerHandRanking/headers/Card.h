#ifndef CARD
#define CARD

struct Card
{
    enum Rank
    {
        Two = 2,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    };

    enum Suit
    {
        Clubs,
        Diamonds,
        Spades,
        Hearts
    };

    Rank rank;
    Suit suit;
};

#endif
