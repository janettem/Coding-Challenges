# Can You Exit the Maze?
[Can You Exit the Maze?](https://edabit.com/challenge/PR5D7Lp42FGtE5tqD)

## Created
29.10.2021

## Explanation
A maze can be represented by a 2D array, where 0s represent walkeable areas, and 1s represent walls. You start on the upper left corner and the exit is on the lower right corner.

Create a function that returns true if you can walk from one end of the maze to the other. You can only move horizontally and vertically. You cannot move diagonally.

Examples:

```c++
canExit({
  {0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 0, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 0}
}); // -> true

canExit({
  {0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1}
}); // -> false
```

## Usage
Open this directory in a terminal.

Compile the application:

```shell
make
```

Run the application:

```shell
./exitMaze
```
