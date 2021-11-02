# The Connell Sequence
[The Connell Sequence](https://edabit.com/challenge/FTw5dJAnFtxjwSfuQ)

## Created
02.11.2021

## Explanation
The Connell sequence can be represented as a growing series of numbered lines. The line number is the quantity of the numbers in the line and the square of the last number of the line. The numbers in the line increase by two:

```
Line 1 = 1
Line 2 = 2, 4
Line 3 = 5, 7, 9
...
```

Given a start line, an end line, and a number, implement a function that returns the index of the number in the generated portion of the Connell sequence. If the number is not found, return -1.

Examples:

```c++
findInConnellSequence(1, 2, 2); // -> 1
// Line 1 = 1
// Line 2 = 2, 4
// Sequence = {1, 2, 4}
// 2 is at the index 1

findInConnellSequence(2, 3, 2); // -> 0
// Line 2 = 2, 4
// Line 3 = 5, 7, 9
// Sequence = {2, 4, 5, 7, 9}
// 2 is at the index 0

findInConnellSequence(3, 4, 6); // -> -1
// Line 3 = 5, 7, 9
// Line 4 = 10, 12, 14, 16
// Sequence = {5, 7, 9, 10, 12, 14, 16}
// 6 is not in the sequence
```

## Usage
Open this directory in a terminal.

Compile the application:

```shell
make
```

Run the application:

```shell
./connellSequence
```
