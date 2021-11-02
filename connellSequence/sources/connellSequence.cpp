#include "connellSequence.h"

static std::vector<int> getConnellSequence(int startLine, int endLine);
static std::vector<int> getConnellSequenceLine(int lineNumber);

int findInConnellSequence(int startLine, int endLine, int number)
{
    std::vector<int> sequence = getConnellSequence(startLine, endLine);
    int position = std::find(sequence.begin(), sequence.end(), number) - sequence.begin();
    return position >= sequence.size() ? -1 : position;
}

static std::vector<int> getConnellSequence(int startLine, int endLine)
{
    std::vector<int> sequence, line;
    for (int i = startLine; i <= endLine; i++)
    {
        line = getConnellSequenceLine(i);
        sequence.insert(sequence.end(), line.begin(), line.end());
    }
    return sequence;
}

static std::vector<int> getConnellSequenceLine(int lineNumber)
{
    std::vector<int> line;
    int number = lineNumber * lineNumber;
    for (int i = 0; i < lineNumber; i++)
    {
        line.insert(line.begin(), number);
        number -= 2;
    }
    return line;
}
