struct Card
{
    enum Rank
    {
        None = 1,
        Two,
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
