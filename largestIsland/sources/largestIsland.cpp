#include "largestIsland.h"

enum Map
{
    Water,
    Land
};

static int **copyMatrix(std::vector<std::vector<int>> matrix);
static int *copyRow(std::vector<int> row);
static int getIslandAreaAndErase(int **map, int rows, int columns, int y, int x);
static void deleteMatrix(int **matrix, int size);

int getLargestIslandArea(std::vector<std::vector<int>> map)
{
    int largestArea = 0;
    int area;
    int **copy = copyMatrix(map);
    int rows = map.size();
    int columns = map[0].size();
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            if (copy[y][x] == Land)
            {
                area = getIslandAreaAndErase(copy, rows, columns, y, x);
                if (area > largestArea)
                    largestArea = area;
            }
        }
    }
    deleteMatrix(copy, rows);
    return largestArea;
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

static int getIslandAreaAndErase(int **map, int rows, int columns, int y1, int x1)
{
    int area = 1;
    map[y1][x1] = Water;
    for (int y2 = (y1 - 1 < 0 ? 0 : y1 - 1); y2 < (y1 + 2 > rows ? rows : y1 + 2); y2++)
    {
        for (int x2 = (x1 - 1 < 0 ? 0 : x1 - 1); x2 < (x1 + 2 > columns ? columns : x1 + 2); x2++)
        {
            if (map[y2][x2] == Land)
                area += getIslandAreaAndErase(map, rows, columns, y2, x2);
        }
    }
    return area;
}

static void deleteMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
        delete[] matrix[i];
    delete[] matrix;
}
