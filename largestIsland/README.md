# largestIsland
[Largest Island](https://edabit.com/challenge/EmEaT9K4wKe3g6QH3)

## Created
28.10.2021

## Explanation
An island is a region of contiguous ones. A contiguous one is a "1" that is touched by at least one other "1", either horizontally, vertically or diagonally. Given a map, represented by a 2-D array, create a function that returns the area of the largest island.

Examples:

```c++
getLargestIslandArea({
  {1, 0, 0},
  {0, 1, 1},
  {0, 0, 1}
}); // -> 4

getLargestIslandArea({
  {1, 0, 0},
  {0, 0, 1},
  {0, 0, 1}
}); // -> 2
```

## Usage
Open this directory in a terminal.

Compile the application:

```shell
make
```

Run the application:

```shell
./largestIsland
```
