#include <string>
#include <iostream>

using namespace std;

string getPokerHandRanking(string hand[5]);

int main()
{
    string royalFlush[5] = {"10h", "Jh", "Qh", "Ah", "Kh"};
    string highCard[5] = {"3h", "5h", "Qs", "9h", "Ad"};

    cout << (getPokerHandRanking(royalFlush) == "Royal Flush");
    cout << (getPokerHandRanking(highCard) == "High Card");

    cout << endl;

    return 0;
}

string getPokerHandRanking(string hand[5])
{
    return "Royal Flush";
}
