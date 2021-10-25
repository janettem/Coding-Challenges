# mod10Algorithm
[Mod 10 Algorithm](https://edabit.com/challenge/dcPJS9rwjfvtXyM2d)

## Created
22.10.2021

## Explanation
Create a function that takes a credit card number as a parameter and checks whether it is valid using the Luhn algorithm also known as the mod 10 algorithm.

### Luhn algorithm
1. Cut off the check digit (the last digit) of the number:

```
79927398713 -> 7992739871
```

2. Calculate the check digit

2.1 Take the original number and starting from the rightmost digit moving left, double the value of every other digit including the rightmost digit:

```
7992739871 -> 718947691672

7 -> 7     = 7
9 -> 9 * 2 = 18
9 -> 9     = 9
2 -> 2 * 2 = 4
7 -> 7     = 7
3 -> 3 * 2 = 6
9 -> 9     = 9
8 -> 8 * 2 = 16
7 -> 7     = 7
1 -> 1 * 2 = 2
```

2.2 Replace the value of each position with the sum of the digits:

```
718947691672 -> 7994769772

7  -> 7     = 7
18 -> 1 + 8 = 9
9  -> 9     = 9
4  -> 4     = 4
7  -> 7     = 7
6  -> 6     = 6
9  -> 9     = 9
16 -> 1 + 6 = 7
7  -> 7     = 7
2  -> 2     = 2
```

2.3 Sum the digits of all the positions (s):

```
7994769772 -> 7 + 9 + 9 + 4 + 7 + 6 + 9 + 7 + 7 + 2 = 67
```

2.4 The calculated check digit is equal to 10 - s % 10:

```
10 - 67 % 10 = 3
```

3. Compare your result with the check digit you cut off:

```
3 = 3
```

If they match the credit card number passed the test.

## Usage
Open this directory in a terminal.

Compile the application:

```
make
```

Run the application:

```
./mod10Algorithm
```
