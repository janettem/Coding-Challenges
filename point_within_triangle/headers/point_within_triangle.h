#ifndef POINT_INSIDE_TRIANGLE
#define POINT_INSIDE_TRIANGLE

#include <math.h>

typedef struct Point
{
    int x;
    int y;
} Point;

#define TRUE 1
#define FALSE 0

int is_point_inside_triangle(Point corner1, Point corner2, Point corner3, Point point);
double get_area_of_triangle(Point corner1, Point corner2, Point corner3);
double get_perimeter_of_triangle(double side1, double side2, double side3);
double get_length_of_side(Point point1, Point point2);
Point get_point(int x, int y);

#endif
