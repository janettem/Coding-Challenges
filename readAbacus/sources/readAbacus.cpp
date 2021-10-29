#include "readAbacus.h"

const char BEAD = 'O';

static int getValue(std::vector<std::string> soroban, int column);
static int getUpperDeckValue(std::vector<std::string> soroban, int column);
static int getLowerDeckValue(std::vector<std::string> soroban, int column);

int getSorobanValue(std::vector<std::string> soroban)
{
    int value = 0;
    for (int column = 0; column < 7; column++)
        value += getValue(soroban, column);
    return value;
}

static int getValue(std::vector<std::string> soroban, int column)
{
    return getUpperDeckValue(soroban, column) +
           getLowerDeckValue(soroban, column);
}

static int getUpperDeckValue(std::vector<std::string> soroban, int column)
{
    if (soroban[1][column] == BEAD)
        return 5 * pow(10, 6 - column);
    return 0;
}

static int getLowerDeckValue(std::vector<std::string> soroban, int column)
{
    int value = 0;
    int beadValue = pow(10, 6 - column);
    for (int row = 3; row < 7 && soroban[row][column] == BEAD; row++)
        value += beadValue;
    return value;
}
