# Tap Code Translation
[Tap Code Translation](https://edabit.com/challenge/dXjHmqGvSwn9toe6R)

## Created
20.10.2021

## Explanation
Tap code is a way to communicate messages via a series of taps for each letter in the message. Letters are arranged in a 5x5 polybius square, with the letter "k" being moved to the space with "c":

```
    1   2   3   4   5
1   a   b   c/k d   e
2   f   g   h   i   j
3   l   m   n   o   p
4   q   r   s   t   u
5   v   w   x   y   z
```

Each letter is translated by tapping out the row and column number that the letter appears in, leaving a short pause in-between. We use "." for each tap, and a single space to denote the pause:

```
'b' = ". .."
```

Another space is added between the groups of taps for each letter to give the final code:

```
"break" = ". .. .... .. . ..... . . . ..."
```

Write a function that returns the tap code if given a word, or returns the translated word in lower case if given the tap code. When translating from tap-code, default to the letter "c" if the tap-code ". ..." is found.

Examples:

```c++
tapCode("break"); // -> ". .. .... .. . ..... . . . ..."
tapCode(". .. .... .. . ..... . . . ..."); // -> "breac"
```

## Usage
Open this directory in a terminal.

Compile the application:

```shell
make
```

Run the application:

```shell
./tapCodeTranslation
```
