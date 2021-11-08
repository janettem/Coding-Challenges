#include <gtest/gtest.h>

const char ONE = 'I';
const char FIVE = 'V';
const char TEN = 'X';
const char FIFTY = 'L';
const char HUNDRED = 'C';
const char FIVE_HUNDRED = 'D';
const char THOUSAND = 'M';

static int parseRomanDigit(char digit);

int parseRomanNumeral(std::string num)
{
    int parsed = 0;
    int digit;
    for (int i = 0; i < num.length(); i++)
    {
        digit = parseRomanDigit(num[i]);
        if (i + 1 < num.length() &&
            digit < parseRomanDigit(num[i + 1]))
            parsed -= digit;
        else
            parsed += digit;
    }
    return parsed;
}

static int parseRomanDigit(char digit)
{
    int parsed = 0;
    if (digit == ONE)
        parsed = 1;
    else if (digit == FIVE)
        parsed = 5;
    else if (digit == TEN)
        parsed = 10;
    else if (digit == FIFTY)
        parsed = 50;
    else if (digit == HUNDRED)
        parsed = 100;
    else if (digit == FIVE_HUNDRED)
        parsed = 500;
    else if (digit == THOUSAND)
        parsed = 1000;
    return parsed;
}

TEST(RomanNumeralsTest, HandlesOneInput)
{
    EXPECT_EQ(parseRomanNumeral("I"), 1);
    EXPECT_EQ(parseRomanNumeral("II"), 2);
    EXPECT_EQ(parseRomanNumeral("III"), 3);
}

TEST(RomanNumeralsTest, HandlesFiveInput)
{
    EXPECT_EQ(parseRomanNumeral("V"), 5);
}

TEST(RomanNumeralsTest, HandlesTenInput)
{
    EXPECT_EQ(parseRomanNumeral("X"), 10);
    EXPECT_EQ(parseRomanNumeral("XX"), 20);
    EXPECT_EQ(parseRomanNumeral("XXX"), 30);
}

TEST(RomanNumeralsTest, HandlesFiftyInput)
{
    EXPECT_EQ(parseRomanNumeral("L"), 50);
}

TEST(RomanNumeralsTest, HandlesHundredInput)
{
    EXPECT_EQ(parseRomanNumeral("C"), 100);
    EXPECT_EQ(parseRomanNumeral("CC"), 200);
    EXPECT_EQ(parseRomanNumeral("CCC"), 300);
}

TEST(RomanNumeralsTest, HandlesFiveHundredInput)
{
    EXPECT_EQ(parseRomanNumeral("D"), 500);
}

TEST(RomanNumeralsTest, HandlesThousandInput)
{
    EXPECT_EQ(parseRomanNumeral("M"), 1000);
    EXPECT_EQ(parseRomanNumeral("MM"), 2000);
    EXPECT_EQ(parseRomanNumeral("MMM"), 3000);
}

TEST(RomanNumeralsTest, HandlesBiggerDigitFollowedBySmallerDigitInput)
{
    EXPECT_EQ(parseRomanNumeral("VI"), 6);
    EXPECT_EQ(parseRomanNumeral("VII"), 7);
    EXPECT_EQ(parseRomanNumeral("VIII"), 8);
    EXPECT_EQ(parseRomanNumeral("LX"), 60);
    EXPECT_EQ(parseRomanNumeral("LXX"), 70);
    EXPECT_EQ(parseRomanNumeral("LXXX"), 80);
    EXPECT_EQ(parseRomanNumeral("DC"), 600);
    EXPECT_EQ(parseRomanNumeral("DCC"), 700);
    EXPECT_EQ(parseRomanNumeral("DCCC"), 800);
}

TEST(RomanNumeralsTest, HandlesSmallerDigitFollowedByBiggerDigitInput)
{
    EXPECT_EQ(parseRomanNumeral("IV"), 4);
    EXPECT_EQ(parseRomanNumeral("IX"), 9);
    EXPECT_EQ(parseRomanNumeral("XL"), 40);
    EXPECT_EQ(parseRomanNumeral("XC"), 90);
    EXPECT_EQ(parseRomanNumeral("CD"), 400);
    EXPECT_EQ(parseRomanNumeral("CM"), 900);
}

TEST(RomanNumeralsTest, HandlesTenAndOneInput)
{
    EXPECT_EQ(parseRomanNumeral("XI"), 11);
    EXPECT_EQ(parseRomanNumeral("XXII"), 22);
    EXPECT_EQ(parseRomanNumeral("XLIV"), 44);
    EXPECT_EQ(parseRomanNumeral("LV"), 55);
    EXPECT_EQ(parseRomanNumeral("LXVI"), 66);
    EXPECT_EQ(parseRomanNumeral("LXXXVIII"), 88);
    EXPECT_EQ(parseRomanNumeral("XCIX"), 99);
}

TEST(RomanNumeralsTest, HandlesHundredAndTenInput)
{
    EXPECT_EQ(parseRomanNumeral("CXX"), 120);
    EXPECT_EQ(parseRomanNumeral("CCCXXX"), 330);
    EXPECT_EQ(parseRomanNumeral("CDL"), 450);
    EXPECT_EQ(parseRomanNumeral("DXL"), 540);
    EXPECT_EQ(parseRomanNumeral("DCLXXX"), 680);
    EXPECT_EQ(parseRomanNumeral("DCCLXX"), 770);
    EXPECT_EQ(parseRomanNumeral("CMLX"), 960);
}

TEST(RomanNumeralsTest, HandlesThousandAndHundredInput)
{
    EXPECT_EQ(parseRomanNumeral("MCCC"), 1300);
    EXPECT_EQ(parseRomanNumeral("MMMD"), 3500);
}

TEST(RomanNumeralsTest, HandlesHundredTenAndOneInput)
{
    EXPECT_EQ(parseRomanNumeral("CXI"), 111);
    EXPECT_EQ(parseRomanNumeral("CCXXII"), 222);
    EXPECT_EQ(parseRomanNumeral("CDXLIV"), 444);
    EXPECT_EQ(parseRomanNumeral("DLV"), 555);
    EXPECT_EQ(parseRomanNumeral("DCLXVI"), 666);
    EXPECT_EQ(parseRomanNumeral("DCCCLXXXVIII"), 888);
    EXPECT_EQ(parseRomanNumeral("CMXCIX"), 999);
}

TEST(RomanNumeralsTest, HandlesThousandHundredAndTenInput)
{
    EXPECT_EQ(parseRomanNumeral("MCXX"), 1120);
    EXPECT_EQ(parseRomanNumeral("MMDL"), 2550);
}

TEST(RomanNumeralsTest, HandlesThousandHundredTenAndOneInput)
{
    EXPECT_EQ(parseRomanNumeral("MMDLV"), 2555);
    EXPECT_EQ(parseRomanNumeral("MMMCCXI"), 3211);
}

TEST(RomanNumeralsTest, HandlesInput)
{
    EXPECT_EQ(parseRomanNumeral("I"), 1);
    EXPECT_EQ(parseRomanNumeral("VIII"), 8);
    EXPECT_EQ(parseRomanNumeral("XXIX"), 29);
    EXPECT_EQ(parseRomanNumeral("LIV"), 54);
    EXPECT_EQ(parseRomanNumeral("CCV"), 205);
    EXPECT_EQ(parseRomanNumeral("CDXLIV"), 444);
    EXPECT_EQ(parseRomanNumeral("CMXCIX"), 999);
    EXPECT_EQ(parseRomanNumeral("M"), 1000);
    EXPECT_EQ(parseRomanNumeral("MMMDCCCLXXXVIII"), 3888);
    EXPECT_EQ(parseRomanNumeral("MMMCMX"), 3910);
}
