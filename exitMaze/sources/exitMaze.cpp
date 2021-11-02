#include "exitMaze.h"

enum Maze
{
    Path,
    Wall
};

static int **copyMatrix(std::vector<std::vector<int>> matrix);
static int *copyRow(std::vector<int> row);
static bool hasExit(int **maze, int rows, int columns, int y, int x);
static bool isWithinBounds(int y, int x, int rows, int columns);
static bool isExit(int y, int x, int rows, int columns);
static void deleteMatrix(int **matrix, int size);

bool canExit(std::vector<std::vector<int>> maze)
{
    int **copy = copyMatrix(maze);
    int rows = maze.size();
    int columns = maze[0].size();
    bool exit = hasExit(copy, rows, columns, 0, 0);
    deleteMatrix(copy, rows);
    return exit;
}

static int **copyMatrix(std::vector<std::vector<int>> matrix)
{
    int size = matrix.size();
    int **copy = new int *[size];
    for (int i = 0; i < size; i++)
        copy[i] = copyRow(matrix[i]);
    return copy;
}

static int *copyRow(std::vector<int> row)
{
    int size = row.size();
    int *copy = new int[size];
    for (int i = 0; i < size; i++)
        copy[i] = row[i];
    return copy;
}

static bool hasExit(int **maze, int rows, int columns, int y, int x)
{
    if (isWithinBounds(y, x, rows, columns) && maze[y][x] == Path)
    {
        maze[y][x] = Wall;
        return hasExit(maze, rows, columns, y - 1, x) ||
               hasExit(maze, rows, columns, y, x - 1) ||
               hasExit(maze, rows, columns, y, x + 1) ||
               hasExit(maze, rows, columns, y + 1, x) ||
               isExit(y, x, rows, columns);
    }
    return false;
}

static bool isWithinBounds(int y, int x, int rows, int columns)
{
    return y >= 0 && y < rows && x >= 0 && x < columns;
}

static bool isExit(int y, int x, int rows, int columns)
{
    return y == rows - 1 && x == columns - 1;
}

static void deleteMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}
